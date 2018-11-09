#include "parser_schemes.h"
#include <string>


using namespace std;

Schemes::Schemes(Lexer* lex, vector<Scheme*>* myVecScheme, vector<Parameter*>* myVecParam ){
    (lex)->getNextToken(SCHEMES);
    (lex)->getNextToken(COLON);
    do {
        Scheme* s1 = new Scheme(lex,myVecParam);
        schemesVec.push_back(s1);
        myVecScheme->push_back(s1);
        
    } while ((lex)->tokenList.back().getTokenType() == ID);
}

Schemes::~Schemes(){}
string Schemes::toString(){
    stringstream ss;
    for (unsigned int i = 0;i < schemesVec.size(); i++){
        ss << "  " << this->schemesVec[i]->schemeId->id.getTokenValue() << "(";
        for(unsigned int j = 0; j < this->schemesVec[i]->columnNames.size(); j++){
            ss << this->schemesVec[i]->columnNames[j]->id.getTokenValue();
            if (j != this->schemesVec[i]->columnNames.size()-1){
                ss<< ",";
            }
        }
        ss << ")" << endl;
    }
    return ss.str();
}