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
      vector<Parameter*>* myVecParam){
        myQueriesPredicate = new Predicate(lex, myVecParam );
        myVecPredicate->push_back(myQueriesPredicate);
        (lex)->getNextToken(Q_MARK);
      };

    ~Query(){};

    Predicate getPredicate(){return *myQueriesPredicate;};

    Predicate* myQueriesPredicate;

};

#endif
