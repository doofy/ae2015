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
  int i, start, end;

  if (n -1 >= m) {
    cerr << "ERROR: you can't connect " << n <<
            " vertices with " << m << " edges!" << endl;
    return 1;
  }

  cout << "Meine Testinstanz" << endl;
  cout << n << endl;
  cout << m << endl;

  for (i = 0; i < n; i++) {
    cout << myrand(1, 10) << endl;
  }

  for (i = 0; i < m; i++) {
    start = myrand(0, n);
    end = myrand(0, n);
    while (start == end) {
      end = myrand(0, n);
    }
    cout << start << " " << end << " " << myrand(1, 10) << endl;
  }
}
