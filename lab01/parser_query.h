#ifndef PARSER_QUERY_H
#define PARSER_QUERY_H

#include "lexer_lexer.h"
#include "parser_predicate.h"
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
