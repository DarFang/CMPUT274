#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int vote[1001];
    int count[1001];
    bool tie = false;

    for (int i = 0; i < 1001; i++ ){
        count[i] = 0;
    }
    // keep reading until we see 0
    while (cin >> vote[n] && vote[n] != 0) {
        ++n;
    }

    // now n == # votes and vote[i] is the i'th vote
    // for 0 <= i <= n-1
    int i =0;
    while ( vote[i] != 0) {
        int num = vote[i];

        count[num] = count[num] + 1;
        i++;
    }
    int winner =1;
    
    for (int i = 2; i<1001; i++){
        if (count[winner] < count[i]){
            winner = i;
        }

    }
    for (int i = 2; i<1001; i++){
        if (count[winner] == count[i] && winner != i){
            tie = true;
        }

    }

    if (tie){
        cout << "tie" << endl;
    }
    else{
        cout << winner << endl;
    }
    // solve the problem and print the answer
    // good luck! (and remember to vote next election) :)

    return 0;
}
