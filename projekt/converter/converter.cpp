#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int* data;
int n;
int d;
string filename;
vector<string> edges;

void printUsage(string progname) {
  cerr << "USAGE: " << progname << " ( full | half ) filename #nodes" << endl;
  cerr << "full: " << "  Read a full cost matrix from filename" << endl;
  cerr << "half: " << "  Read half a cost matrix from filename" << endl;
  cerr << "#nodes: " << "Number of nodes in cost matrix" << endl;
  cerr << "d: " << "     Node wheight" << endl;
}

void readHalf(string filename, int n) {
  int nextint;
  ifstream f(filename.c_str());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      f >> nextint;
      data[n * i + j] = nextint;
      data[n * j + i] = nextint;
      stringstream edge;
      edge << i + 1 << " " << j + 1 << " " << nextint << " 0";
      edges.push_back(edge.str());
    }
  }
  f.close();
}

void readFull(string filename, int n) {
  int nextint;
  ifstream f(filename.c_str());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      f >> nextint;
      data[n * i + j] = nextint;
      stringstream edge;
      edge << i + 1 << " " << j + 1 << " " << nextint << " 0";
      edges.push_back(edge.str());
    }
  }
  f.close();
}

void printData(int d) {
  cout << "Datensatz " << filename << endl;
  cout << n << endl;
  cout << edges.size() << endl;
  for (int i = 0; i < n; i++) {
    cout << d << endl;
  }
  for (vector<string>::iterator it = edges.begin(); it != edges.end(); ++it) {
    cout << *it << endl;
  }
}

int main (int argc, char** argv) {
  string progname = argv[0];
  if (argc == 5) {
    filename = argv[2];
    n = atoi(argv[3]);
    data = new int[n * n];
    d = atoi(argv[4]);
    if (strcmp(argv[1], "full") == 0) {
      readFull(filename, n);
      printData(d);
      delete[] data;
      return 0;
    }
    else if (strcmp(argv[1], "half") == 0) {
      readHalf(filename, n);
      printData(d);
      delete[] data;
      return 0;
    }
    else {
      printUsage(progname);
      delete[] data;
      return 1;
    }
  }
  printUsage(progname);
  delete[] data;
  return 1;
}
