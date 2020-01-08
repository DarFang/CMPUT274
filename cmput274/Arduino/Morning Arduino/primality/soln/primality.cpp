#include <iostream>
#include <cmath> // for sqrt

using namespace std;

// given a positive integer n <= 4,000,000 this returns the smallest
// integer d such that d*d > n
//
// not needed to solve the problem, but some might find it helpful
unsigned int upper_sqrt(unsigned int n) {
    unsigned int d = sqrt((double) n);

    // should iterate at most once or twice
    while (d*d <= n) {
        ++d;
    }

    return d;
}

int main() {
    long long n, m;
    bool prime = true;

    // read in the integer
    // NOTE: look *carefully* at the maximum value of the number
    // in the problem description
    cin >> n;
    m = upper_sqrt(n);

    // determine if the integer is prime
    // good luck and remember that composite numbers are for chumps :)
    for (int a = 2; a <= m; a++){
        if((n%a == 0 || n == 1) && n != 2){
            prime = false;
            break;
        }
}

    // print the answer
    if (prime == false){
        cout << "not prime" << endl;
    } else{
        cout << "prime" << endl;
    }

    return 0;
}
