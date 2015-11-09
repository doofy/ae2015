#include <cstdlib>
#include <iostream>

using namespace std;

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
    if (argc == 1) {
        print_usage(argv[0]);
        return 0;
    }

    return 0;
}
