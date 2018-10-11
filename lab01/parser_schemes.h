#ifndef PARSER_SCHEMES_H
#define PARSER_SCHEMES_H

#include "lexer_lexer.h"

#include "parser_scheme.h"
#include <string>
#include <vector>
using namespace std;

class Schemes{
    public:
    Schemes(Lexer* lex);
    ~Schemes(){};
    string toString();
    
    vector<Scheme*> schemesVec;
    
//     vector<Scheme> schemes -- not empty
// 	Schemes(Lex lex)
// 	calls: new Scheme(lex)
};

#endif
