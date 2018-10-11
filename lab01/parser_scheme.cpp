#include "parser_scheme.h"
#include <string>

using namespace std;

Scheme::Scheme(Lexer* lex){
    schemeId = new Id(lex);
    (lex)->getNextToken(LEFT_PAREN);
    columnNames.push_back(new Id(lex));
    while((lex)->tokenList.back().getTokenType() == COMMA){
        (lex)->tokenList.pop_back();
        columnNames.push_back(new Id(lex));
    }
    (lex)->getNextToken(RIGHT_PAREN);
}