#ifndef PARSER_EXPRESSION_H
#define PARSER_EXPRESSION_H

#include "lexer_lexer.h"

#include "parser_parameter.h"
#include "parser_predicate.h"
#include <string>
#include <vector>
using namespace std;

class Expression:public Parameter{
    public:
    Expression(Lexer* lex){};
    Expression(Parameter* a, tokenTypeDef b, Parameter* c){
      this->expressionParameter1 = a;
      this->expressionOperator = b;
      this->expressionParameter2 = c;
    };
    ~Expression();
    string toString(){
      stringstream ss;
      ss << "(";
      ss << expressionParameter1->toString();
      if(expressionOperator == ADD){
          ss << "+";
      }
      else{
          ss << "*";
      }
      ss << expressionParameter2->toString();
      ss << ")";
      return ss.str();
    };



    Parameter* expressionParameter1;
    tokenTypeDef expressionOperator;
    Parameter* expressionParameter2;

};
#endif
