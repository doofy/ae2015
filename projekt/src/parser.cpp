#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <climits>

using namespace std;

string dat1;
string dat2;

char datasetName[256];
int* V;
int* E;
int n; //number of veritces
int m; //number of edges

// writes 0 in all the is part of the solution entries of array A
void clearSolutions(int* A, int s) {
    for (int i = 3; i < s * 4; i += 4) {
        A[i] = 0;
    }
}

// checks if solution is valid
void evalInput() {
}

// greedy selects all edges to non connected vertices to find a solution
void calcSolution() {
    int i;
    int C[n]; // array to journal if a vertex is connected
    for (i = 0; i < n; i++) {
        C[i] = 0;
    }
    C[0] = 1; //mark starting vertex as connected
    for (i = 0; i < m * 4; i += 4) {
        if (!C[E[i + 1]]) {
            E[i + 3] = 1;
            C[E[i + 1]] = 1;
        }
    }
}

// writes out in data format following the convention
void writeOutput() {
    ofstream f(dat2.c_str());

    if (f.is_open()) {
        f << datasetName << endl;
        f << n << endl;
        f << m << endl;
        for (int i = 0; i < n; i++) {
            f << V[i] << endl;
        }
        for (int i = 0; i < m * 4; i += 4) {
            f << E[i] << " " << E[i + 1] << " " << E[i + 2] << " " << E[i + 3] << endl;
        }
    }
    f.close();
}

// reads data in data format following the convention
void readInput() {
    ifstream f(dat1.c_str());

    if (f.is_open()) {
        f.getline(datasetName, 256);

        f >> n; //#vertices
        f >> m; //#edges

        V = new int[n];
        E = new int[m * 4];

        for (int i = 0; i < n; i++) {
            f >> V[i];
        }

        for (int i = 0; i < m * 4; i += 4) {
            f >> E[i]; //start vertex
            f >> E[i + 1]; //end vertex
            f >> E[i + 2]; //wheight
            f >> E[i + 3]; //is part of the solution
        }
    }
    f.close();
}

// parse the programs parameters
int parse(int argc, char** argv) {
    if (argc == 3) {
        if (!strcmp(argv[1], "-eval")) {
            dat1 = argv[2];
            readInput();
            evalInput();
            return 0;
        }
        else {
            return 1;
        }
    }
    else if (argc == 5) {
        if (!strcmp(argv[1], "-in") && !strcmp(argv[3],"-out")) {
            dat1 = argv[2];
            dat2 = argv[4];
            readInput();
            clearSolutions(E, m);
            calcSolution();
            writeOutput();
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        return 1;
    }
    return 0;
}

void print_usage(char* progname) {
    cout << "Usage: " << progname << " -in <infile> -out <outfile> | -eval <infile>" << endl;
    cout << "\t-in <infile>: call infile to run algorithms on, need -out" << endl;
    cout << "\t-out <outfile>: call outfile for results, need -in" << endl;
    cout << "\t-eval <infile>: call infile to print results" << endl;
}

int main(int argc, char** argv) {
    if (parse(argc, argv)) {
        print_usage(argv[0]);
        return 1;
    }
    else {
        return 0;
    }
    delete[] V;
    delete[] E;
}
