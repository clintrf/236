#ifndef ID_H
#define ID_H

#include "lexer.h"
#include "token.h"
#include "parameter.h"
#include <string>
#include <vector>
using namespace std;

class Id:public Parameter{
    public:
    Id(Lexer* lex);
    ~Id(){};
    string toString();
    
    Token id;
};
    
#endif
