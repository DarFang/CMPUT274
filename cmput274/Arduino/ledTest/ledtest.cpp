#include <Arduino.h>
#define MY_LED_PIN 13
void setup() {
    // needed for all Arudino programs
    // rather, the compiler just uses 13 in the
    // code whenever it sees MY_LED_PIN
    init();

    Serial.begin(9600);

    pinMode(MY_LED_PIN, OUTPUT);
}

int main(){
    setup();
    int delay_on = 250, delay_off = 750;
    for (int i = 0; i<1000; i++) {
        Serial.println("LED ON!");
        digitalWrite(MY_LED_PIN, HIGH);
        delay(delay_on); //wait 1000ms

        Serial.println("LED OFF!");
        digitalWrite(MY_LED_PIN, LOW);
        delay(delay_off+3000);
    }
    Serial.flush();
    return 0;
}
