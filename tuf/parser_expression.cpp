#include "parser_expression.h"

Expression::Expression(Lexer* lex){}
Expression::~Expression(){}

Expression::Expression(Parameter* a, tokenTypeDef b, Parameter* c){
    
    this->expressionParameter1 = a;
    this->expressionOperator = b;
    this->expressionParameter2 = c;
    
}

// Expression::Expression(Lexer* lex, vector<Parameter*>* myVecParam){
//     tokenTypeDef expressionOperator;
    
//     (lex)->getNextToken(LEFT_PAREN);
//     expressionParameter1 = createParameter(lex, myVecParam);
//     expressionOperator = (lex)->tokenList.back().getTokenType();

//     (lex)->tokenList.pop_back();
    
//     this->expressionParameter2 = createParameter(lex, myVecParam);
//     (lex)->getNextToken(RIGHT_PAREN);
    
//     //this->myExp = new Expression(expressionParameter1,expressionOperator,expressionParameter2);
//     //return this->myExp;
    
// }

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