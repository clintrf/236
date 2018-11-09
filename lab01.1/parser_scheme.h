#ifndef PARSER_SCHEME_H
#define PARSER_SCHEME_H

#include "lexer_lexer.h"
#include "parser_id.h"
#include "parser_parameter.h"
#include <string>
#include <vector>
using namespace std;

class Scheme{
    public:
    Scheme(Lexer* lex, vector<Parameter*>* myVecParam);
    ~Scheme();
    
    Id* schemeId;
    vector<Id*> columnNames;

};

#endif
