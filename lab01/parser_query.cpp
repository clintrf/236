#include "parser_query.h"
#include "parser_predicate.h"

Query::Query(Lexer* lex, vector<Predicate*>* myVecPredicate,
    vector<Parameter*>* myVecParam){
        
    myQueriesPredicate = new Predicate(lex, myVecParam );
    myVecPredicate->push_back(myQueriesPredicate);
    (lex)->getNextToken(Q_MARK);
};

Query::~Query(){}