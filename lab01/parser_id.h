#ifndef PARSER_ID_H
#define PARSER_ID_H

#include "lexer_lexer.h"
#include "lexer_token.h"
#include "parser_parameter.h"
#include <string>
#include <vector>
using namespace std;

class Id:public Parameter{
    public:
    Id(Lexer* lex);
    ~Id(){};
    string toString();
    
    Token id;
};
    
#endif
