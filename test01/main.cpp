#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "lexer.h"
#include "parser.h"

// #include "Lab02_Par/schemes.h"
// #include "Lab02_Par/facts.h"
// #include "Lab02_Par/rules.h"
// #include "Lab02_Par/queries.h"

// #include "Lab02_Par/datalogProgram.h"
// #include "Lab02_Par/expression.h"
// #include "Lab02_Par/headPredicate.h"
// #include "Lab02_Par/id.h"
// #include "Lab02_Par/parameter.h"
// #include "Lab02_Par/predicate.h"
// #include "Lab02_Par/string.h"

// #include "Lab02_Par/scheme.h"
using namespace std;

int main(int argc, char* argv[]){
    
    ifstream input;
    ofstream output;
    try{
        if(argc > 0){
            input.open (argv[1]);
            if(!input.good()){
                cout << "Error opening file " << endl;
                return 0;
            }
            Lexer lex = Lexer(&input);
            Parser parsed = Parser(&lex);
            
            cout << parsed.toString();
            //DatalogProgram datalogProgram = DatalogProgram(lex);
        }

		
		//cout << datalogProgram.toString() << endl
        //Parser parse = Parser(lex.getTokens());
        //DatalogProgram* parsed = parse.datalogParsing();
        //cout << parsed->toString();
        //delete parsed;
    } catch(Token token) {
        cout << "Failure!" << endl;
        cout << "  " << token.toString();
    }
    //output.open("outText00.txt");
    //output << scan1.print();
    //input.close;
    //output.close;
    
    
    
    // ifstream input;
    // ofstream output;
    // string fileName;
    // char fileNumber;
    
    // input.open (argv[1]);
    // fileName = argv[1];
    
    // cout << "ERROR" << endl;
    // Lexer lex = Lexer(&input);
    // Parser parsed = Parser(&lex);
    // //cout << scan1.print() << endl;
    
    // fileNumber = fileName[8];
    // fileName = "01_testOut.";
    // fileName += fileNumber;
    // fileName += ".txt";
    
    // output.open(fileName);
    // output << parsed.toString();
    
     
    
    return 0;
};
