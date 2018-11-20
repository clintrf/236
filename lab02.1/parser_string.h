#ifndef PARSER_STRING_H
#define PARSER_STRING_H

#include "lexer_lexer.h"

#include "parser_parameter.h"
#include <string>
#include <vector>
using namespace std;

class String:public Parameter{
    public:
    String(Lexer* lex){
      Parameter::stringFlag = 1;
      myStringToken = (lex)->getNextToken(STRING);
    };
    ~String(){};
    // string toString(){
    //   stringstream ss;
    //   ss << this->myStringToken.getTokenValue();
    //   return ss.str();
    // };
    Token getMyStringToken(){return myStringToken;};
    Token myStringToken;
};

#endif
