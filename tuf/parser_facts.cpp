#include "parser_facts.h"
#include <string>

using namespace std;

Facts::Facts(Lexer* lex, vector<Fact*>* myVecFact, vector<Parameter*>* myVecParam){
    (lex)->getNextToken(FACTS);
    (lex)->getNextToken(COLON);
    while ((lex)->tokenList.back().getTokenType() == ID){
        Fact* f1 = new Fact(lex, myVecParam);
        factsVec.push_back(f1);
        myVecFact->push_back(f1);
    } 
}

Facts::~Facts(){}


string Facts::toString(){
    stringstream ss;
    for (unsigned int i = 0;i < factsVec.size(); i++){
        ss << "  " << this->factsVec[i]->factId->id.getTokenValue() << "(";
        ss << this->factsVec[i]->factVec[0]->myStringToken.getTokenValue();
        for(unsigned int j = 1; j < this->factsVec[i]->factVec.size(); j++){
            
            if (j != this->factsVec[i]->factVec.size()){
                ss<< ",";
            }
            ss << this->factsVec[i]->factVec[j]->toString();
        }
        ss << ")." << endl;
    }
    return ss.str();
}