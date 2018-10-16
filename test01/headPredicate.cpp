#include "headPredicate.h"

HeadPredicate::HeadPredicate(Lexer* lex){
    headPredicateId = new Id(lex);
    (lex)->getNextToken(LEFT_PAREN);
    headPredicateIdVec.push_back(new Id(lex));
    while((lex)->tokenList.back().getTokenType() == COMMA){
        (lex)->tokenList.pop_back();
        headPredicateIdVec.push_back(new Id(lex));
    }
    (lex)->getNextToken(RIGHT_PAREN);
}

string HeadPredicate::toString(){
    stringstream ss;
    ss << this->headPredicateId->id.getTokenValue() << "(";
    ss << this->headPredicateIdVec[0]->id.getTokenValue();
    for(unsigned int i = 1; i < this->headPredicateIdVec.size(); i++){
        if (i != this->headPredicateIdVec.size()){
            ss<< ",";
        }
        ss << this->headPredicateIdVec[i]->toString();
    }
    ss << ") :- ";
    return ss.str();
}