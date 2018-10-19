#include "parser_expression.h"

Expression::Expression(Lexer* lex){}
Expression::~Expression(){}

Expression::Expression(Parameter* a, tokenTypeDef b, Parameter* c){
    
    this->expressionParameter1 = a;
    this->expressionOperator = b;
    this->expressionParameter2 = c;
    
}
string Expression::toString(){
    stringstream ss;
    ss << "(";
    ss << expressionParameter1->toString();
    if(expressionOperator == ADD){
        ss << "+";
    }
    else{
        ss << "*";
    }
    ss << expressionParameter2->toString();
    ss << ")";
    return ss.str();
}