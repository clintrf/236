#ifndef PARSER_RULES_H
#define PARSER_RULES_H


#include "lexer_lexer.h"

#include "parser_rule.h"
#include "parser_predicate.h"
#include "parser_headPredicate.h"
#include "parser_predicate.h"
#include <string>
#include <vector>
using namespace std;

class Rules{
    public:
    Rules(Lexer* lex, vector<Rule*>* myVecRule,
    vector<Predicate*>* myVecPredicate,
    vector<HeadPredicate*>* myVecHeadPredicate,
    vector<Parameter*>* myVecParam);
    ~Rules();
    string toString();
    
    vector<Rule*> rulesVec;
    
};

#endif
