#include "parser_facts.h"
#include <string>

using namespace std;

Facts::Facts(Lexer* lex){
    (lex)->getNextToken(FACTS);
    (lex)->getNextToken(COLON);
    while ((lex)->tokenList.back().getTokenType() == ID){
        factsVec.push_back(new Fact(lex));
    } 
}

string Facts::toString(){
    stringstream ss;
    for (int i = 0;i < factsVec.size(); i++){
        ss << "  " << this->factsVec[i]->factId->id.getTokenValue() << "(";
        ss << this->factsVec[i]->factVec[0]->myStringToken.getTokenValue();
        for(int j = 1; j < this->factsVec[i]->factVec.size(); j++){
            
            if (j != this->factsVec[i]->factVec.size()){
                ss<< ",";
            }
            ss << this->factsVec[i]->factVec[j]->toString();
        }
        ss << ")." << endl;
    }
    return ss.str();
}