#ifndef PARSER_FACT_H
#define PARSER_FACT_H

#include "lexer_lexer.h"
#include "parser_string.h"
#include "parser_id.h"
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
