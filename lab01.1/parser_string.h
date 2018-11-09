#ifndef PARSER_STRING_H
#define PARSER_STRING_H

#include "lexer_lexer.h"

#include "parser_parameter.h"
#include <string>
#include <vector>
using namespace std;

class String:public Parameter{
    public:
    String(Lexer* lex);
    ~String(){};
    string toString();
    
    Token myStringToken;
};

#endif
