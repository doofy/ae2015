#include <cstdlib>
#include <iostream>

using namespace std;

int myrand(int l, int u) {
  return rand() % u + l;
}

int main(int argc, char** argv) {
  srand(atoi(argv[1]));

  int n = atoi(argv[2]);
  int m = atoi(argv[3]);
  int i;

  cout << "Meine Testinstanz" << endl;
  cout << n << endl;
  cout << m << endl;

  for (i = 0; i < n; i++) {
    cout << myrand(1, 10) << endl;
  }

  for (i = 0; i < m; i++) {
    cout << myrand(0, n) << " " << myrand(0, n) << " " << myrand(1, 10) << " " << "0" << endl;
  }
}
