#include "query.h"
#include "predicate.h"

Query::Query(Lexer* lex){
    myQueriesPredicate = new Predicate(lex);
    (lex)->getNextToken(Q_MARK);
};