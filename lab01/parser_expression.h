#ifndef PARSER_EXPRESSION_H
#define PARSER_EXPRESSION_H

#include "lexer_lexer.h"

#include "parser_parameter.h"
#include <string>
#include <vector>
using namespace std;

class Expression:public Parameter{
    public:
    Expression(Lexer* lex);
    Expression(Parameter* a, tokenTypeDef b, Parameter* c);
    ~Expression();
    string toString();
    
    
    
    Parameter* expressionParameter1;
    tokenTypeDef expressionOperator;
    Parameter* expressionParameter2;
    
};
#endif
