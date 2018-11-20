#ifndef PARSER_ID_H
#define PARSER_ID_H

#include "lexer_lexer.h"
#include "lexer_token.h"
#include "parser_parameter.h"
#include <string>
#include <vector>
using namespace std;

class Id:public Parameter{
    public:
    Id(Lexer* lex){
      Parameter::idFlag = 1;
      id = (lex)->getNextToken(ID);
    };
    virtual ~Id(){};
    string toString(){
      stringstream ss;
      ss << this->id.getTokenValue();
      return ss.str();
    };

    Token id;
};

#endif
