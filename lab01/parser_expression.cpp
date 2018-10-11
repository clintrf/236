#include "parser_expression.h"

Expression::Expression(Lexer* lex){
    //(lex)->getNextToken(LEFT_PAREN);
    //expressionParameter1 = Parameter::createParameter(lex);
    //expressionOperator = (lex)->tokenList.back().getTokenType();
    //(lex)->tokenList.pop_back();
    //expressionParameter2 = new Parameter(lex);
    //expressionParameter2 = Parameter->createParameter(lex);
    //(lex)->getNextToken(RIGHT_PAREN);
}
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