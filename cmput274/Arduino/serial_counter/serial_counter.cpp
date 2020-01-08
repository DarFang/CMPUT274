#include <Arduino.h>
int LED[] = {9, 10, 11, 12, 13};  // 5 LED pins

void setup() {
	init();
	Serial.begin(9600);  // Serial moniter setup
	for (int i = 0; i < 5; i++) {
		pinMode(LED[i], OUTPUT);  // Pin Setup
		digitalWrite(LED[i], 0);  // Set initial pin to output LOW
	}
}

int8_t getHexValue(char digit) {  // Checks Ascii Value input
	if (digit >= '0' && digit <= '9') {  // Digit
		return (digit - '0');
	}
	else if (digit >= 'a' && digit <= 'f') {  // Lowercase a to f
		return (digit - 'a' + 10);
	}
	else if (digit >= 'A' && digit <= 'F') {  // Uppercase A to F
		return (digit - 'A' + 10);
	}
	if (digit == ' ' || digit == '\r') {  // Return/Enter or Space
		return -2;
	}
	else {
		return -1;
	}
}
void updateLEDs(int8_t total){
int out = 0;  // Dummy variable
for (int i = 0; i < 5; i++) {
 	out = total >> i & 1;  // Total moves to the right comparing least signifigant bit
 	digitalWrite(LED[i], out);
 	Serial.print(out);  // Print the binary from least significant to most
 }
 Serial.println("\n");
}

int main() {
	setup();
	char Byte = '0';  // Keybaord Input
	uint8_t Total = 0;  // Total
	int Value = 0;  // Hex Value
	while (1) {
		if (Serial.available() > 0) {
			Byte = Serial.read();  // Reads Kaybaord input
			Value = getHexValue(Byte);  // Converts to Hex Value
			if (Value == -2) {  // If user inputs Return/Enter or Space
				Serial.println("Reset");
				Total = 0;
			}
			else if (Value != -1) {  // If user inputs valid input
				Serial.println(Value);  // Prints the value inputed
				Total = Total + Value;
			}
			else {  // If user does not input valid input
				Serial.println("Invalid input");
			}
			Serial.println(Total);  // Prints the total to screen
			updateLEDs(Total);
		}
	}
}
