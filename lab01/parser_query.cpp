#include "parser_query.h"
#include "parser_predicate.h"

Query::Query(Lexer* lex){
    myQueriesPredicate = new Predicate(lex);
    (lex)->getNextToken(Q_MARK);
};

Query::~Query(){
delete myQueriesPredicate;
}