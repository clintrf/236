#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "lexer_lexer.h"
#include "lexer_token.h"
using namespace std;

int main(int argc, char* argv[]){

    ifstream input;
    ofstream output;
    string fileName;
    char fileNumber;
    
    input.open (argv[1]);
    fileName = argv[1];
    
    Lexer scan1 = Lexer(&input);
    scan1.analysisFile();
    cout << scan1.print() << endl;
    
    fileNumber = fileName[8];
    fileName = "00_testOut.";
    fileName += fileNumber;
    fileName += ".txt";
    
    //output.open(fileName);
    //output << scan1.print();

    
    
    return 0;
};