#include <Arduino.h>

int LEDpins[5] = {9, 10, 11, 12, 13};  // LED output ports
int incButtonP = 6, decButtonP = 7, saveButtonP = 5;  // Button input ports
int incButtonV, decButtonV, saveButtonV;  // Button input values
bool storedV[5];  // Stored Value
bool stored = true;  // Store value, false is output stored value

void setup() {
    for (int i = 0; i < 5; i++) {
        pinMode(LEDpins[i], OUTPUT);  // Make each port an OUTPUT
        digitalWrite(LEDpins[i], LOW);  // Set each port as LOW
    }

    pinMode(incButtonP, INPUT_PULLUP);  // Make each Button input
    pinMode(decButtonP, INPUT_PULLUP);
    pinMode(saveButtonP, INPUT_PULLUP);
}

int main() {
    init();  // initialize variables
    setup();  // setup inputs and outputs

    while (1) {  // Forever loop
        incButtonV = digitalRead(incButtonP);  // Read in inputs
        decButtonV = digitalRead(decButtonP);
        saveButtonV = digitalRead(saveButtonP);
        if (incButtonV == LOW) {  // If increment button pressed
            for (int i = 0; i < 5 ; i++) {
                if (digitalRead(LEDpins[i]) == LOW) {  // If digit is 0
                    digitalWrite(LEDpins[i], HIGH);  // Change to 1
                    break;
                }
            digitalWrite(LEDpins[i], LOW);  // Change to 0
            }
        }

        if (decButtonV == LOW) {  // If decrement button pressed
            for (int i = 0; i <5 ; i++) {
                if (digitalRead(LEDpins[i]) == HIGH) {  // If digit is 1
                    digitalWrite(LEDpins[i], LOW);  // Cahne to 0
                    break;
                }
            digitalWrite(LEDpins[i], HIGH);  // Change to 1
            }
        }

        if (saveButtonV == LOW) {  // If store button pressed
            if (stored == true) {  // Store value mode
                stored = false;
                for (int i = 0; i < 5; i++) {
                    storedV[i] = digitalRead(LEDpins[i]);
                    digitalWrite(LEDpins[i], LOW);
                }
            } else {  // Output store value
                stored = true;
                for (int i = 0; i < 5; i++) {
                    digitalWrite(LEDpins[i], storedV[i]);
                }
            }
        }
        delay(10);
        while (incButtonV == LOW || decButtonV == LOW || saveButtonV ==LOW) {
        // While one is pressed
            incButtonV = digitalRead(incButtonP);
            decButtonV = digitalRead(decButtonP);
            saveButtonV = digitalRead(saveButtonP);
        }
    }
    return 0;
}