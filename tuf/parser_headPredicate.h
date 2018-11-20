#ifndef PARSER_HEADPREDICATE_H
#define PARSER_HEADPREDICATE_H

#include "lexer_lexer.h"
#include "parser_id.h"
#include "parser_predicate.h"
#include <string>
#include <vector>
using namespace std;

class HeadPredicate{
    public:
    HeadPredicate(Lexer* lex, vector<Parameter*>* myVecParam);
    ~HeadPredicate();
    string toString();
    
    Id* headPredicateId;
    vector<Id*> headPredicateIdVec;
    
};

#endif
