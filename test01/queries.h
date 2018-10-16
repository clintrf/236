#ifndef QUERIES_H
#define QUERIES_H

#include "lexer.h"
#include "query.h"
#include <string>
#include <vector>
using namespace std;

class Queries{
    public:
    Queries(Lexer* lex);
    ~Queries(){};
    
    string toString();
    
    vector<Query*> queriesVec;
// 	Queries(Lex lex)
// 	calls: new Query(lex)
};

#endif
