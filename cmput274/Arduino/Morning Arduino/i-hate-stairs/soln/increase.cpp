#include <iostream>

using namespace std;

int main() {
  int n;
  int array[1000];
  int answer=0;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> array[i];
  }

  // now compute the answer and put it into the "answer" variable
  // good luck :) you've got this!
  // p.s. don't forget your semi-colons

  for (int i = 0; i<n-1; i++) {
    if (array[i+1] > array [i]) {
      answer = answer +array[i+1]-array[i];
    }
  }

  // output the result
  cout << answer << endl;

  return 0;
}
