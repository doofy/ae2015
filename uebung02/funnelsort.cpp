#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

void funnelSort(int* X, int n) {
  int a = cbrt(n);
  int b = cbrt(n * n);
  int* B[a];
  int i;
  int j;
  for (i = 0; i < a; i++) {
    B[i] = new int[b];
    for (j = 0; j < n / a; j++) {
      B[i][j] = X[i * a + j];
    }
  }
  //for (i = 0; i < a; i++) {
    //for (j = 0; j < n / a; j++) {
      //cout << X[i * n / a + j];
      //if (i < a - 1 || j < (n / a) - 1) {
        //cout << endl;
      //}
    //}
  //}
  //cout << endl;
}

void bubbleSort(int* X, int n) {
  for (int i = 0; i < n - 1; i++) {
    if (X[i] > X[i + 1]) {
      int t = X[i + 1];
      X[i + 1] = X[i];
      X[i] = t;
      bubbleSort(X, n);
    }
  }
}

void print(int* X, int n) {
  for (int i = 0; i < n; i++) {
    cout << X[i];
    if (i < n - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

int main (int argc, char** argv) {
  int n = atoi(argv[1]);
  int A[n] = {};
  int* X = A;
  int x;
  while (cin >> x) {
    *(X++) = x;
  }
  funnelSort(A, n);
  //print(A, n);
  return 0;
}
