#include <Arduino.h>

void setup() {
  // needed for all Arduino programs
  init();

  Serial.begin(9600);
}


// forward declaration of powmod, or else the test function below
// doesn't know about it
uint32_t powmod(uint32_t x, uint32_t pow, uint32_t m);

// calls powmod to compute x^pow mod m, and compares it with ans
// prints a statement if the test failed
void powmodTestOnce(uint32_t x, uint32_t pow, uint32_t m, uint32_t ans) {
  Serial.print("Testing: ");
  Serial.print(x);
  Serial.print(" ");
  Serial.print(pow);
  Serial.print(" ");
  Serial.print(m);
  Serial.print("... ");

  uint32_t computed = powmod(x, pow, m);
  if (ans != computed) {
    Serial.println("failed!");
    Serial.print("Expected: ");
    Serial.println(ans);
    Serial.print("Got: ");
    Serial.println(computed);
  }
  else {
    Serial.println("OK!");
  }
}

void powmodTest() {
  // you can generate examples by calling, say, pow(2, 15, 37) in Python
  // to compute 2^(15) mod 37
  Serial.println("Beginning powmod tests...");
  Serial.println(powmod(97, 7, 95477));
  Serial.println(powmod('a', 7, 95477));
  Serial.println(powmod(powmod(97, 7, 95477), 27103, 95477));
  
  Serial.println("Done tests");
}

// computes the value x^pow mod m ("x to the power of pow" mod m)
uint32_t powmod(uint32_t x, uint32_t pow, uint32_t m) {
  // you will make these uint32_t types
  // for the final submission
  uint64_t ans = 1;
  uint64_t pow_x = x;

  // NOTE: in the full assignment you will have to
  // replace the 64-bit types with an algorithm that
  // performs multiplication modulo a 31-bit number while
  // only using 32-bit types.

  while (pow > 0) {
    if (pow&1 == 1) {
      // will replace the following line with a "mulmod" call
      // discussed on Nov 7 (see also the worksheet posted then)
      ans = (ans*pow_x)%m;
    }

    // as well as this line (i.e. call mulmod instead)
    pow_x = (pow_x*pow_x)%m;

    pow >>= 1; // divides by 2
  }

  return ans;
}


int main() {
  setup();

  powmodTest();

  Serial.flush();
  return 0;
}
