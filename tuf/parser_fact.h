#ifndef PARSER_FACT_H
#define PARSER_FACT_H

#include "lexer_lexer.h"
#include "parser_string.h"
#include "parser_id.h"
#include "parser_parameter.h"
#include <string>
#include <vector>
using namespace std;

class Fact{
    public:
    Fact(Lexer* lex, vector<Parameter*>* myVecParam);
    ~Fact();
    
    Id* factId;
    vector<String*> factVec;

};
#endif
