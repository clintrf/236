#include "parser_rule.h"

Rule::Rule(Lexer* lex){
    this->ruleHeadPredicate = new HeadPredicate(lex);
    (lex)->getNextToken(COLON_DASH);
    
    ruleVec.push_back(new Predicate(lex));
    while((lex)->tokenList.back().getTokenType() == COMMA){
        (lex)->tokenList.pop_back();
        while((lex)->tokenList.back().getTokenType() == ID){
            
            ruleVec.push_back(new Predicate(lex));
        }
    }
    (lex)->getNextToken(PERIOD);
};

Rule::~Rule(){
    delete this->ruleHeadPredicate;
    for (unsigned int i = 0;i < ruleVec.size(); i++){
        delete ruleVec[i];
    }   
}

string Rule::toString(){
    cout << "nothing in rule toString" << endl;
    return 0;
}
