#include "schemes.h"
#include <string>

using namespace std;

Schemes::Schemes(Lexer* lex){
    (lex)->getNextToken(SCHEMES);
    (lex)->getNextToken(COLON);
    do {
        schemesVec.push_back(new Scheme(lex));
    } while ((lex)->tokenList.back().getTokenType() == ID);
}
string Schemes::toString(){
    stringstream ss;
    for (int i = 0;i < schemesVec.size(); i++){
        ss << "  " << this->schemesVec[i]->schemeId->id.getTokenValue() << "(";
        for(int j = 0; j < this->schemesVec[i]->columnNames.size(); j++){
            ss << this->schemesVec[i]->columnNames[j]->id.getTokenValue();
            if (j != this->schemesVec[i]->columnNames.size()-1){
                ss<< ",";
            }
        }
        ss << ")" << endl;
    }
    return ss.str();
}