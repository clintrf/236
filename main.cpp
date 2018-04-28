#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "lexer.h"
#include "token.h"
using namespace std;

int main(int argc, char* argv[]){
    ifstream input;
    ofstream output;
    
    input.open (argv[1]);
    
    Lexer scan1 = Lexer(&input);
    scan1.analysisFile();
    cout << scan1.print() << endl;
    //output.open("outText00.txt");
    //output << scan1.print();
    //input.close;
    //output.close;
    
    return 0;
};