#include "parser_fact.h"
#include <string>

using namespace std;

Fact::Fact(Lexer* lex){
    factId = new Id(lex);
    (lex)->getNextToken(LEFT_PAREN);
    factVec.push_back(new String(lex));
    while((lex)->tokenList.back().getTokenType() == COMMA){
        (lex)->tokenList.pop_back();
        factVec.push_back(new String(lex));
    }
    (lex)->getNextToken(RIGHT_PAREN);
    (lex)->getNextToken(PERIOD);
};