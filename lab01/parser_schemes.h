#ifndef PARSER_SCHEMES_H
#define PARSER_SCHEMES_H

#include "lexer_lexer.h"
#include "parser_scheme.h"
#include "parser_parameter.h"
#include <string>
#include <vector>
using namespace std;

class Schemes{
    public:
    Schemes(Lexer* lex, vector<Scheme*>* myVecScheme, vector<Parameter*>* myVecParam );
    ~Schemes();
    string toString();
    
    vector<Scheme*> schemesVec;
};

#endif
