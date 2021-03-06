#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <climits>
#include <ctime>

using namespace std;

string dat1;
string dat2;

char datasetName[256];
int* V;
int* E;
int n; //number of veritces
int m; //number of edges

clock_t start;
double duration;
int weight;

void printInfo() {
    cout.precision(3);
    cout << weight << '\t' << duration << endl;
}

void startTimer() {
    start = std::clock();
}

void stopTimer() {
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
}

// writes 0 in all the is part of the solution entries of array A
void clearSolutions(int* A, int s) {
    for (int i = 3; i < s * 4; i += 4) {
        A[i] = 0;
    }
}

// checks if weight limits are respected and all vertices have at least one edge
int checkConnections(int verbose) {
    int i;
    int C[n]; // array to journal if and how often a vertex is connected
    weight = 0;
    for (i = 0; i < n; i++) {
        C[i] = 0;
    }
    // count
    for (i = 0; i < m * 4; i += 4) {
        if (E[i + 3]) {
            C[E[i]]++;
            C[E[i + 1]]++;
            weight += E[i + 2];
        }
    }
    // check
    for (i = 0; i < n; i++) {
        if (C[i] == 0) {
            if (verbose) {
                cout << "ERROR: " << "Vertex " << i << " is not connected." << endl;
            }
            return 1;
        }
        else if (V[i] < C[i]) {
            if (verbose) {
                cout << "ERROR: " << "Vertex " << i << " is connected with too many edges." << endl;
            }
            return 1;
        }
    }
    return 0;
}

// checks if solution is valid
int evalInput(int verbose) {
    return checkConnections(verbose);
}

// greedy selects all edges to non connected vertices to find a solution
void calcSolution() {
    int i;
    int C[n]; // array to journal if a vertex is connected
    for (i = 0; i < n; i++) {
        C[i] = 0;
    }
    for (i = 0; i < m * 4; i += 4) {
        if ((!C[E[i + 1]] && C[E[i]] < V[E[i]]) || (!C[E[i]] && C[E[i + 1]] < V[E[i + 1]])) {
            E[i + 3] = 1;
            C[E[i + 1]]++;
            C[E[i]]++;
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
            f >> E[i + 2]; //weight
            string lineEnd;
            getline(f, lineEnd);
            if (!lineEnd.empty())
              E[i + 3] = atoi(lineEnd.c_str()); //is part of the solution
            else
              E[i + 3] = 0;
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
            if(!evalInput(1)) {
                cout << weight << endl;
            }

            delete[] V;
            delete[] E;
            return 0;
        }
    }
    else if (argc == 5) {
        if (!strcmp(argv[1], "-in") && !strcmp(argv[3],"-out")) {
            dat1 = argv[2];
            dat2 = argv[4];
            readInput();
            clearSolutions(E, m);
            startTimer();
            calcSolution();
            stopTimer();
            if(evalInput(0)) {
                weight = -1;
            }
            writeOutput();
            printInfo();

            delete[] V;
            delete[] E;
            return 0;
        }
    }

    return 1;
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
    return 0;
}
