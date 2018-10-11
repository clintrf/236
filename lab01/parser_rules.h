#ifndef PARSER_RULES_H
#define PARSER_RULES_H


#include "lexer_lexer.h"

#include "parser_rule.h"
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
