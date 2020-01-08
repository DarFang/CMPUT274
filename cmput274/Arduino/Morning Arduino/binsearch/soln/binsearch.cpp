/*
  Reads input in the following format
    n - length of array (at most 1000000)
    a[] - the array
    num_q - number of queries
    finally followed by num_q different query integers q

  For each query, you should binary search a[] for an index i such that
   a[i] == q (or determine q is not in the array).

  Implement the function binary_search below.
*/


#include <iostream>
#include <math.h>
using namespace std;

/*
  Assumes a[] is already sorted and n >= 1.

  Returns any index i such that a[i] == q. If no such
  index exists (i.e. q is not in the array), this returns -1.

  Should run in O(log n) time (i.e. use a binary search).
*/
int binary_search(int a[], int n, int q) {
  // IMPLEMENT THIS
  int low = 0, high = n-1, middle = floor((high+low)/2);
  for (int i = 0; i < log2(n)+1; i++){
    //cout << low << " " << middle << " " << high << "\n";
    if (q == a[middle]){
      return middle;
    }
    else if (q < a[middle]){
      high = middle-1;
      middle = floor((high+low)/2);
    }
    else if (q > a[middle]){
      low = middle+1;
      middle=floor((high+low)/2);
    }
  }
  return -1;
}

int main() {
  // DO NOT edit anything int this main function. To solve the problem as
  // intended, only edit the binary_search() function above.

  int a[1000000], n;

  // read in the array
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  // process the queries
  int num_q;
  cin >> num_q;

  for (int i = 0; i < num_q; ++i) {
    int q;
    cin >> q;

    // call binary_search to get the index
    int index = binary_search(a, n, q);

    // output the appropriate message
    if (index < -1 || index >= n) {
      cout << "Uh oh... the 'index' you output is not -1 or in the" << endl
           << "range of the array." << endl;
    }
    else if (index == -1) {
      cout << "Not Found!" << endl;
    }
    else if (a[index] == q) {
      cout << "Found!" << endl;
    }
    else {
      cout << "Uh oh... you should never output this." << endl
           << "If you get here, you returned an index that" << endl
           << "did not have the queried number: " << q << endl;
    }
  }

  return 0;
}
