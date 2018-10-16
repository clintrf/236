#include "parser_predicate.h"


using namespace std;

Predicate::Predicate(Lexer* lex){
    predicateId = new Id(lex);
    (lex)->getNextToken(LEFT_PAREN);
    predicateVec.push_back(createParameter(lex));
    
    while((lex)->tokenList.back().getTokenType() == COMMA){
        (lex)->tokenList.pop_back();
        predicateVec.push_back(createParameter(lex));
    }
    (lex)->getNextToken(RIGHT_PAREN);
}

Predicate::~Predicate(){
    delete predicateId;
    delete myPara;
    delete myExp;
    delete expressionParameter1;
    delete expressionParameter2;
    for (unsigned int i = 0;i < predicateVec.size(); i++){
        delete predicateVec[i];
    }
}

Parameter* Predicate::createParameter(Lexer* lex){
    
    if((lex)->tokenList.back().getTokenType() == STRING){
        this->myPara = new String(lex);
        return this->myPara;
    }
    else if ((lex)->tokenList.back().getTokenType() == ID){
        this->myPara = new Id(lex);
        return this->myPara;
    }
    else{
        this->myPara = createExpression(lex);
        return this->myPara;
    }
    
}

Parameter* Predicate::createExpression(Lexer* lex){
    
    tokenTypeDef expressionOperator;

    
    (lex)->getNextToken(LEFT_PAREN);
    this->expressionParameter1 = createParameter(lex);
    expressionOperator = (lex)->tokenList.back().getTokenType();
    (lex)->tokenList.pop_back();
    this->expressionParameter2 = createParameter(lex);
    (lex)->getNextToken(RIGHT_PAREN);
    
    this->myExp = new Expression(expressionParameter1,expressionOperator,expressionParameter2);
    
    return this->myExp;
}

string Predicate::toString(){
    stringstream ss;
    ss << predicateId->id.getTokenValue() << "(";
    ss << predicateVec[0]->toString();
    for (unsigned int i = 1;i < predicateVec.size(); i++){

        if (i != predicateVec.size()){
            ss<< ",";
        }
                ss << predicateVec[i]->toString();
    }
    ss << ")";
    return ss.str();
}

