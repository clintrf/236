#ifndef SCHEME_H
#define SCHEME_H

#include "lexer.h"
#include "id.h"
#include <string>
#include <vector>
using namespace std;

class Scheme{
    public:
    Scheme(Lexer* lex);
    ~Scheme(){};
    
    Id* schemeId;
    vector<Id*> columnNames; //not empty
// 	Scheme(Lex lex)
// 	calls:new Id(lex)

};

#endif
