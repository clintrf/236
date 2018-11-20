#ifndef PARSER_PARAMETER_H
#define PARSER_PARAMETER_H

#include "lexer_lexer.h"
#include "lexer_token.h"


#include <string>
#include <vector>
using namespace std;

class Parameter{
    public:
    Parameter(){};
    Parameter(Lexer* lex){
      this->token = lex->tokenList.back();
    };
    virtual ~Parameter(){};

    int stringFlag;
    int idFlag;
    int expressionFlag;
    Token token;

    virtual string toString(){
      return token.getLiteral();
//      if(stringFlag == 1){return "string";}
//      else if (idFlag == 1){return "id";}
//      else{return "exp";}
    };// = 0;

    static Parameter* createParameter(Lexer* lex){
      if((lex)->tokenList.back().getTokenType() == STRING){return 0;}
      else if ((lex)->tokenList.back().getTokenType() == ID){return 0;}
      else{return 0;}
    };

    int getLine() {
      return token.getLine();
  	}
  	string getLiteral() {
  		return token.getLiteral();
  	}
  	string getName() {
  		return token.getName();
  	}

};
#endif
