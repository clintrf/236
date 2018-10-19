#include "parser_scheme.h"
#include <string>

using namespace std;

Scheme::Scheme(Lexer* lex, vector<Parameter*>* myVecParam){
    schemeId = new Id(lex);
    myVecParam->push_back(schemeId);
    
    (lex)->getNextToken(LEFT_PAREN);
    Id* i1 = new Id(lex);
    columnNames.push_back(i1);
    myVecParam->push_back(i1);
    
    while((lex)->tokenList.back().getTokenType() == COMMA){
        (lex)->tokenList.pop_back();
        
        Id* i2 = new Id(lex);
        columnNames.push_back(i2);
        myVecParam->push_back(i2);
    }
    (lex)->getNextToken(RIGHT_PAREN);
}

Scheme::~Scheme(){}