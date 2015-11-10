#include <cstdlib>
#include <iostream>

using namespace std;

void evalInput() {
}

void calcSolution() {
}

void writeOutput() {
}

void readInput() {
}

int parse(int argc, char** argv) {
    if (argc == 3) {
        if (argv[1] == "-eval") {
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
        if (argv[1] == "-in" && argv[3] == "-out") {
            dat1 = argv[2];
            dat2 = argv[4];
            readInput();
            calcSolution();
            writeOuput();
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        return 1;
    }
}

void print_usage(char* progname) {
    cout << "Usage: " << progname << " -in <infile> -out <outfile> | -eval <infile>" << endl;
    cout << "\t-in <infile>: call infile to run algorithms on, need -out" << endl;
    cout << "\t-out <outfile>: call outfile for results, need -in" << endl;
    cout << "\t-eval <infile>: call infile to print results" << endl;
}

/*
 *
 */
int main(int argc, char** argv) {
    if (parse(argc, argv)) {
        print_usage(argv[0]);
        return 1;
    }
    else {
        return 0;
    }
}
