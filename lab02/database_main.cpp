#include <string>
#include <fstream>
#include <iostream>

#include "lexer_token.h"
#include "lexer_lexer.h"
//#include "parser_parser.h"
#include "database_interpreter.h"
#include "database_relation.h"
#include "database_header.h"


using namespace std;

int main(int argc, const char* argv[]) {
        ifstream input;
    ofstream output;
    string fileName;
    char fileNumber;
    
    for( int i = 0; i<10; i++){
        Interpreter interpTest = Interpreter(i);
        
        fileNumber = '0';
        fileName = "testOut.";
        fileName += (fileNumber+i);
        fileName += ".txt"; 
        
        string comment;
        switch (i){
            case 0: comment = "Does select work"; break;
            case 1: comment = "select with a list of indexes work"; break;
            case 2: comment = "does project work"; break;
            case 3: comment = "does rename work"; break;
            case 4: comment = "test('1','1','1')"; break;
            case 5: comment = "test('5', anynum, somenum)"; break;
            case 6: comment = "test(what, why, '3')"; break;
            case 7: comment = "test(X,X,X)"; break;
            case 8: comment = "test(X,Y,Z)"; break;
            case 9: comment = "test(X,'6',Y)"; break;
            default: comment = "no comment"; break;
        }
        
        output.open(fileName);
        output << comment << endl;
        output << interpTest.printRelations();
        output.close();
    }
    return 0;
    
};