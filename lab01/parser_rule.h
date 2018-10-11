#ifndef PARSER_RULE_H
#define PARSER_RULE_H

#include "lexer_lexer.h"
#include "parser_headPredicate.h"
#include "parser_predicate.h"
#include <string>
#include <vector>
using namespace std;

class Rule{
    public:
    Rule(Lexer* lex);
    ~Rule(){};
    
    string toString();
    
    //Id* ruleId;
    HeadPredicate* ruleHeadPredicate;
    
    vector<Predicate*> ruleVec;
    
    
//     HeadPredicate head
// 	vector<Predicate> predicates //not empty
// 	Rule(Lex lex)
// 		calls:new HeadPredicate(lex)
// 		calls:new Predicate(lex)
};

#endif
