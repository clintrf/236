#ifndef PARSER_HEADPREDICATE_H
#define PARSER_HEADPREDICATE_H

#include "lexer_lexer.h"
#include "parser_id.h"
#include <string>
#include <vector>
using namespace std;

class HeadPredicate{
    public:
    HeadPredicate(Lexer* lex);
    ~HeadPredicate(){};
    string toString();
    
    Id* headPredicateId;
    vector<Id*> headPredicateIdVec;
    
//     is a Predicate
// 	HeadPredicate(Lex lex)
// 		calls: Predicate.predicate(lex)
};

#endif
