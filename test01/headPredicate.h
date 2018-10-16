#ifndef HEADPREDICATE_H
#define HEADPREDICATE_H

#include "lexer.h"
#include "id.h"
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
