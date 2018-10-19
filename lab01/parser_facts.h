#ifndef PARSER_FACTS_H
#define PARSER_FACTS_H

#include "lexer_lexer.h"

#include "parser_fact.h"
#include "parser_parameter.h"
#include <string>
#include <vector>
using namespace std;

class Facts{
    public:
    Facts(Lexer* lex, vector<Fact*>* myVecFact, vector<Parameter*>* myVecParam);
    ~Facts();
    string toString();
    
    vector<Fact*> factsVec;
};

#endif
