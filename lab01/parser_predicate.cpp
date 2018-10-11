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

Parameter* Predicate::createParameter(Lexer* lex){
    Parameter* myPara;
    if((lex)->tokenList.back().getTokenType() == STRING){
        myPara = new String(lex);
        return myPara;
    }
    else if ((lex)->tokenList.back().getTokenType() == ID){
        myPara = new Id(lex);
        return myPara;
    }
    else{
        myPara = createExpression(lex);
        return myPara;
    }
    
}

Parameter* Predicate::createExpression(Lexer* lex){
    Parameter* expressionParameter1;
    tokenTypeDef expressionOperator;
    Parameter* expressionParameter2;
    Parameter* myExp;
    
    (lex)->getNextToken(LEFT_PAREN);
    expressionParameter1 = createParameter(lex);
    expressionOperator = (lex)->tokenList.back().getTokenType();
    (lex)->tokenList.pop_back();
    expressionParameter2 = createParameter(lex);
    (lex)->getNextToken(RIGHT_PAREN);
    
    myExp = new Expression(expressionParameter1,expressionOperator,expressionParameter2);
    
    return myExp;
}

string Predicate::toString(){
    stringstream ss;
    ss << predicateId->id.getTokenValue() << "(";
    ss << predicateVec[0]->toString();
    for (int i = 1;i < predicateVec.size(); i++){

        if (i != predicateVec.size()){
            ss<< ",";
        }
                ss << predicateVec[i]->toString();
    }
    ss << ")";
    return ss.str();
}

