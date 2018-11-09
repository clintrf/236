#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "lexer_lexer.h"
#include "parser_parser.h"


using namespace std;

int main(int argc, char* argv[]){
 
    
    
    ifstream input;
    ofstream output;
    string fileName;
    string fileNumber;

    fileName = argv[1];

    if(argc > 0){
        input.open (argv[1]);
        if(!input.good()){
            cout << "Error opening file " << endl;
            return 0;
        }


        //fileNumber = fileName[0];
        fileNumber = fileName[2];
        if (fileName[3] != '.'){fileNumber += fileName[3];}
        
        fileName = "01_testOut.";
        fileName += fileNumber;
        fileName += ".txt"; 
        
        
        Lexer lex = Lexer(&input);
        Parser parsed = Parser(&lex);
        
        output.open(fileName);
        output << parsed.toString() << parsed.catchOut;          // for self testing

        //cout << parsed.toString();              //for pass off
        parsed.clearMemory();
    }
		
    //output.open("outText00.txt");
    //output << scan1.print();
    //input.close;
    //output.close;
    
    return 0;
};
