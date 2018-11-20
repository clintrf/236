#ifndef PARSER_QUERY_H
#define PARSER_QUERY_H

#include "lexer_lexer.h"
#include "parser_predicate.h"
#include <string>
#include <vector>
using namespace std;

class Query:public Predicate{
    public:
    Query(Lexer* lex, vector<Predicate*>* myVecPredicate,
    vector<Parameter*>* myVecParam);
    ~Query();
    
    Predicate getPredicate(){
        return *myQueriesPredicate;
    };
    
    Predicate* myQueriesPredicate;
    
    string toString();

};

#endif
