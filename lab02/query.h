#ifndef QUERY_H
#define QUERY_H

#include "lexer.h"
#include "predicate.h"
#include <string>
#include <vector>
using namespace std;

class Query:public Predicate{
    public:
    Query(Lexer* lex);
    ~Query(){};
    
    Predicate* myQueriesPredicate;
    
    string toString();
    
//      Query is a Predicate
// 	Query(Lex lex)
// 		calls: Predicate.predicate(lex)
};

#endif
