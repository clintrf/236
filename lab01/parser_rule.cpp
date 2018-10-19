#include "parser_rule.h"

Rule::Rule(Lexer* lex, vector<Predicate*>* myVecPredicate,
    vector<HeadPredicate*>* myVecHeadPredicate,
    vector<Parameter*>* myVecParam){
        
    
    this->ruleHeadPredicate = new HeadPredicate(lex, myVecParam);
    myVecHeadPredicate->push_back(ruleHeadPredicate);
    
    (lex)->getNextToken(COLON_DASH);
    
    Predicate* p1 = new Predicate(lex, myVecParam);
    ruleVec.push_back(p1);
    myVecPredicate->push_back(p1);
    
    while((lex)->tokenList.back().getTokenType() == COMMA){
        (lex)->tokenList.pop_back();
        while((lex)->tokenList.back().getTokenType() == ID){
            Predicate* p2 = new Predicate(lex, myVecParam);
            ruleVec.push_back(p2);
            myVecPredicate->push_back(p2);
        }
    }
    (lex)->getNextToken(PERIOD);
};

Rule::~Rule(){}

string Rule::toString(){
    cout << "nothing in rule toString" << endl;
    return 0;
}
