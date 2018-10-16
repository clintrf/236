#include "rules.h"
#include <string>

Rules::Rules(Lexer* lex){
    (lex)->getNextToken(RULES);
    (lex)->getNextToken(COLON);
    while ((lex)->tokenList.back().getTokenType() == ID) {
        rulesVec.push_back(new Rule(lex));
    }
};

string Rules::toString(){
    stringstream ss;
    for (unsigned int i = 0; i < rulesVec.size(); i++){
        ss << "  " << this->rulesVec[i]->ruleHeadPredicate->toString();
        ss << this->rulesVec[i]->ruleVec[0]->toString();
        for(unsigned int j = 1; j < this->rulesVec[i]->ruleVec.size(); j++){
            
            if (j != this->rulesVec[i]->ruleVec.size()){
                ss<< ",";
            }
            ss << this->rulesVec[i]->ruleVec[j]->toString();
        }
        ss << "." << endl;
    }
    return ss.str();
}