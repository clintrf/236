#include "parser_fact.h"
#include <string>

using namespace std;

Fact::Fact(Lexer* lex, vector<Parameter*>* myVecParam){
    
    factId = new Id(lex);
    myVecParam->push_back(factId);
    
    (lex)->getNextToken(LEFT_PAREN);
    String* s1 = new String(lex);
    factVec.push_back(s1);
    myVecParam->push_back(s1);
    
    
    while((lex)->tokenList.back().getTokenType() == COMMA){
        (lex)->tokenList.pop_back();
        String* s2 = new String(lex);
        factVec.push_back(s2);
        myVecParam->push_back(s2);
    }
    (lex)->getNextToken(RIGHT_PAREN);
    (lex)->getNextToken(PERIOD);
};

Fact::~Fact(){}