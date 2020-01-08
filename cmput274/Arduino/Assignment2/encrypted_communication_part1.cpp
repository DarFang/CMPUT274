#include <Arduino.h>
uint32_t serverPublicKey = 7;
uint32_t serverPrivateKey = 27103;
uint32_t serverModulus = 95477;  // Server values
uint32_t clientPublicKey = 11;
uint32_t clientPrivateKey = 38291;
uint32_t clientModulus = 84823;  // Client values

void setup() {
	init();  // Initialize serial
	pinMode(13, INPUT);  // Determine Aurdiono 1 and 2
	Serial.begin(9600);  // User input
	Serial3.begin(9600);  // Aurdiono input
}

void uint32_to_serial3(uint32_t num) {  // Write encrypt value
	Serial3.write((char) (num >> 0));
	Serial3.write((char) (num >> 8));
	Serial3.write((char) (num >> 16));
	Serial3.write((char) (num >> 24));
}

uint32_t uint32_from_serial3() {  // Read encrypt value
	uint32_t num = 0;
	num = num | ((uint32_t) Serial3.read()) << 0;
	num = num | ((uint32_t) Serial3.read()) << 8;
	num = num | ((uint32_t) Serial3.read()) << 16;
	num = num | ((uint32_t) Serial3.read()) << 24;
	return num;
}
uint32_t mulmod(uint32_t a, uint32_t b, uint32_t m) {
		uint32_t result = 0;
		for (uint32_t i = 0; i<32 ; i++) {
			if (a & 1){
				result = (result+b)%m;
			}
			b = (b*2)%m;
			a = a >> 1;
		}
		return result;
}	

uint32_t powMod(uint32_t byte, uint32_t Key, uint32_t Mod) {  // Power mod
	uint32_t newByte = 1;
	while (Key > 0) {
		//Serial.println(newByte);
		//Serial.println(byte);
		if (Key & 1) {
			
			newByte = mulmod(newByte, byte, Mod); // byte times newByte
			//Serial.println(newByte);
			//Serial.println();
			

		}
		byte = mulmod(byte, byte, Mod); // Byte squared
		Key = Key >> 1;


	}
	//Serial.println(newByte);
	return newByte;
}
	

int main() {
	uint32_t e = 0, m = 0, d = 0, n = 0;
	setup();
	if (digitalRead(13) == LOW) {  // Client
		Serial.println("Client");
		e = serverPublicKey; // Recive public server key
		m = serverModulus; // Recive server mod
	 	d = clientPrivateKey;  // Recive  private client key
		n = clientModulus;  // Recive  client mod
	} else {  // Server
		Serial.println("Server");
		e = clientPublicKey;  // Recive public client key
		m = clientModulus;  // Recive client mod
		d = serverPrivateKey;  // Recive private server key
		n = serverModulus;  // Recive server mod
	}

	uint32_t en_byte;  // Encrypte Byte
	uint8_t de_byte;  // Dencrypte Byte


	while (true) {
		if (Serial.available() > 0 ) { // User writes input
			uint32_t readByte = Serial.read();
			if(readByte == '\r') {  // If user inputs return
				Serial.print('\n');
				en_byte = powMod('\n', e, m);
				uint32_to_serial3(en_byte);
				}
			//Serial.print("Read byte: ");
			Serial.print(char(readByte));  // Write to monitor
			en_byte = powMod(char(readByte), e, m);  // Encrypt

			uint32_to_serial3(en_byte);  // Write encrypt value to the other Arduino
			//de_byte = powMod(en_byte, serverPrivateKey, m);
			//Serial.print("Encrypted byte: ");
			//Serial.println(en_byte);
			//Serial.print("Decoded byte: ");
			//Serial.println(de_byte);
			

		} else if (Serial3.available() > 3) {  // Arduino recieving input from other Arduino
			en_byte = uint32_from_serial3();  // Read input from Arduino
			de_byte = powMod(en_byte, d, n);  // Dencrypt
			Serial.write(de_byte);  // Write Dencrypt value
		}

	}
	Serial.flush();
	Serial3.flush();
	return 0;
}