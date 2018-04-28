#ifndef FACTS_H
#define FACTS_H

#include "lexer.h"

#include "fact.h"
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
