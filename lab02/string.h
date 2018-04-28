#ifndef STRING_H
#define STRING_H

#include "lexer.h"

#include "parameter.h"
#include <string>
#include <vector>
using namespace std;

class String:public Parameter{
    public:
    String(Lexer* lex);
    ~String(){};
    string toString();
    
    Token myStringToken;
};

#endif
