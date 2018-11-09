#ifndef PARSER_PREDICATE_H
#define PARSER_PREDICATE_H

#include "lexer_lexer.h"
#include <vector>
//#include "parser_parser.h"

#include "parser_parameter.h"
#include "parser_id.h"
#include "parser_string.h"
#include "parser_expression.h"
#include <string>

using namespace std;

class Predicate {
  public:
  Predicate(){};
  Predicate(Lexer* lex, vector<Parameter*>* myVecParam);
  virtual ~Predicate();
  
  string toString();
  
  
  Parameter* createParameter(Lexer* lex, vector<Parameter*>* myVecParam);
  Parameter* createExpression(Lexer* lex, vector<Parameter*>* myVecParam);
  tokenTypeDef expressionOperator(Lexer* lex, vector<Parameter*>* myVecParam);


  //Parameter* myExp = NULL;
  //Parameter* expressionParameter1 = NULL;
  //Parameter* expressionParameter2 = NULL;
  Parameter* myPara = NULL;
  Id* predicateId = NULL;
  vector<Parameter*> predicateVec;
  
};
#endif
