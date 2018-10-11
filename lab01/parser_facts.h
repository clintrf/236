#ifndef PARSER_FACTS_H
#define PARSER_FACTS_H

#include "lexer_lexer.h"

#include "parser_fact.h"
#include <string>
#include <vector>
using namespace std;

class Facts{
    public:
    Facts(Lexer* lex);
    ~Facts(){};
    string toString();
    
    vector<Fact*> factsVec;
    
//     vector<Fact> facts
// 	Facts(Lex lex)
// 	calls:new Fact(lex)
};

#endif
