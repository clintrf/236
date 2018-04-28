#ifndef RULES_H
#define RULES_H


#include "lexer.h"

#include "rule.h"
#include <string>
#include <vector>
using namespace std;

class Rules{
    public:
    Rules(Lexer* lex);
    ~Rules(){};
    string toString();
    
    vector<Rule*> rulesVec;
    
//     vector<Rule> rules
// 	Rules(Lex lex)
// 	calls:new Rule(lex);
};

#endif
