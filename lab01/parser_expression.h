#ifndef PARSER_EXPRESSION_H
#define PARSER_EXPRESSION_H

#include "lexer_lexer.h"

#include "parser_parameter.h"
#include <string>
#include <vector>
using namespace std;

//enum Operator {ADD, MULTIPLY};

class Expression:public Parameter{
    public:
    Expression(Lexer* lex);
    Expression(Parameter* a, tokenTypeDef b, Parameter* c);
    ~Expression();
    string toString();
    
    
    
    Parameter* expressionParameter1;
    tokenTypeDef expressionOperator;
    Parameter* expressionParameter2;
    
    
//     	Parameter parameter1
// 	Operator operator
// 	Parameter parameter2
// 	Expression(Lex lex)
// 		calls: Parameter.createParameter(lex)
// enum Operator PLUS, STAR
    
};
#endif
