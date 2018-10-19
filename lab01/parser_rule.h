#ifndef PARSER_RULE_H
#define PARSER_RULE_H

#include "lexer_lexer.h"
#include "parser_predicate.h"
#include "parser_headPredicate.h"
#include "parser_parameter.h"

#include <string>
#include <vector>
using namespace std;

class Rule{
    public:
    Rule(Lexer* lex, vector<Predicate*>* myVecPredicate,
    vector<HeadPredicate*>* myVecHeadPredicate,
    vector<Parameter*>* myVecParam);
    ~Rule();
    
    string toString();

    HeadPredicate* ruleHeadPredicate = NULL;
    
    vector<Predicate*> ruleVec;
    
};

#endif
