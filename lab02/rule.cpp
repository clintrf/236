#include "rule.h"

Rule::Rule(Lexer* lex){
    ruleHeadPredicate = new HeadPredicate(lex);
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

string Rule::toString(){
    
}
