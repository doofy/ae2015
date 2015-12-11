#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char** argv) {
  int next;
  int word = 0;
  ifstream f(argv[1]);
  while (f >> next) {
    word++;
  }
  double a = sqrt(2.0 * word + 0.25) - 0.5;
  cout << a << endl;
  f.close();
  return 0;
}
