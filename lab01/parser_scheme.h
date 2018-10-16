#ifndef PARSER_SCHEME_H
#define PARSER_SCHEME_H

#include "lexer_lexer.h"
#include "parser_id.h"
#include <string>
#include <vector>
using namespace std;

class Scheme{
    public:
    Scheme(Lexer* lex);
    ~Scheme();
    
    Id* schemeId;
    vector<Id*> columnNames; //not empty
// 	Scheme(Lex lex)
// 	calls:new Id(lex)

};

#endif
