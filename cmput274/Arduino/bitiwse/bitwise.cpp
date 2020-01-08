#include <Arduino.h>
void setup (){
init();
Serial.begin(9600);


}

int main() {
	setup();
	uint8_t a = B10110011;
	uint8_t b = B01111001;

	uint8_t z = (a & b);
	uint8_t h = (a | b);
	uint8_t k = (a ^ b);
	uint8_t l = (~a);
	uint8_t m = (a << 1);


	Serial.print("AND: ");
	Serial.println(z, BIN);

	Serial.print("OR ");
	Serial.println(h, BIN);

	Serial.print("XOR ");
	Serial.println(k, BIN);

	Serial.print("NOT: ");
	Serial.println(l, BIN);
	
	Serial.print("Left shift: ");
	Serial.println(m, BIN);

	Serial.flush();
	return 0;
}