#include <Arduino.h>

int LEDpins[5] = {9, 10, 11, 12, 13};
int incrementButtonPin = 6;
int incrementButtonValue;

void setup(){
   for (int i=0; i<5; i++){
    pinMode(LEDpins[i], OUTPUT);
   digitalWrite(LEDpins[i], LOW); // if resistor and LED to ground else
                                  // HIGH for resistor and LED to VCC
  }
//  pinMode(incrementButtonPin, INPUT);
//  digitalWrite(incrementButtonPin, HIGH); // isn't what you want
  pinMode(incrementButtonPin, INPUT_PULLUP); // this is what you want
}
int main() {
	init();
	setup();
	while(1) {
		incrementButtonValue = digitalRead(incrementButtonPin);
 		if (incrementButtonValue == LOW) {
    		for (int i=0; i<5; i++) {
         		if (digitalRead(LEDpins[i]) == LOW){
               		digitalWrite(LEDpins[i], HIGH);
                 	break; // no carry to other lights so no more loops
        		}

         digitalWrite(LEDpins[i], LOW);
   			}
		}
	delay(5); // debounce switch
 	while ( incrementButtonValue == LOW ){  // wait until switch is high again
   incrementButtonValue = digitalRead(incrementButtonPin);
 	}
	
}
return 0;
}
