#include <iostream>
using namespace std;

int main() {
    // I've heard that climbing is a good workout for your legs.
    // But I haven't moved from my chair in years, so I might not be the best person to ask.
    // Good luck with the problem! The term is almost over! :)

	// Read in the input
	int n = 0;
	cin >> n;
	int climb[n];
	for (int i = 0; i<n; i++){
	cin >> climb[i];
	}

	// Solve the problem
int count = 0;
if (n!=0){
		for (int i = 0; i<n; i++){
			if (climb[i] < climb [i+1] && i != n-1){
				count++;
			}
			else{
				while(count>0){
					cout << count << " ";
					count--;
				}
				cout << 0 << " ";
			}
		}
	}
	return 0;
}
