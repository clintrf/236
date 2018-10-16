#ifndef FACT_H
#define FACT_H

#include "lexer.h"
#include "string.h"
#include "id.h"
#include <string>
#include <vector>
using namespace std;

class Fact{
    public:
    Fact(Lexer* lex);
    ~Fact(){};
    
    Id* factId;
    vector<String*> factVec;
    
//     Id factId
// 	vector<String> strings //not empty
// 	Fact(Lex lex)
// 		calls: new Id(lex)
// 		calls: new String(lex)
};
#endif
