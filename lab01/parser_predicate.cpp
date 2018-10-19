#include "parser_predicate.h"



using namespace std;

Predicate::Predicate(Lexer* lex, vector<Parameter*>* myVecParam){
    
    predicateId = new Id(lex);
    myVecParam->push_back(predicateId);
    
    (lex)->getNextToken(LEFT_PAREN);
    predicateVec.push_back(createParameter(lex, myVecParam));
    
    while((lex)->tokenList.back().getTokenType() == COMMA){
        (lex)->tokenList.pop_back();
        predicateVec.push_back(createParameter(lex, myVecParam));
    }
    (lex)->getNextToken(RIGHT_PAREN);
}

Predicate::~Predicate(){}

Parameter* Predicate::createParameter(Lexer* lex, vector<Parameter*>* myVecParam){
    
    if((lex)->tokenList.back().getTokenType() == STRING){
        this->myPara = new String(lex);
        myVecParam->push_back(myPara);
        return this->myPara;
    }
    else if ((lex)->tokenList.back().getTokenType() == ID){
        this->myPara = new Id(lex);
        myVecParam->push_back(myPara);
        return this->myPara;
    }
    else{
        this->myPara = createExpression(lex, myVecParam);
        myVecParam->push_back(myPara);
        return this->myPara;
    }
    
}

Parameter* Predicate::createExpression(Lexer* lex, vector<Parameter*>* myVecParam){
    
    tokenTypeDef expressionOperator;

    
    (lex)->getNextToken(LEFT_PAREN);
    this->expressionParameter1 = createParameter(lex, myVecParam);
    expressionOperator = (lex)->tokenList.back().getTokenType();
    (lex)->tokenList.pop_back();
    this->expressionParameter2 = createParameter(lex, myVecParam);
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

