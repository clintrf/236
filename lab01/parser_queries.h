#ifndef PARSER_QUERIES_H
#define PARSER_QUERIES_H

#include "lexer_lexer.h"
#include "parser_query.h"
#include <string>
#include <vector>
using namespace std;

class Queries{
    public:
    Queries(Lexer* lex);
    ~Queries();
    
    string toString();
    
    vector<Query*> queriesVec;
// 	Queries(Lex lex)
// 	calls: new Query(lex)
};

#endif
