#ifndef PARSER_PREDICATE_H
#define PARSER_PREDICATE_H

#include "lexer_lexer.h"
#include <vector>
#include "parser_parameter.h"
#include "parser_id.h"
#include "parser_string.h"
#include "parser_expression.h"
#include <string>

using namespace std;

class Predicate {
  public:
  Predicate(){};
  Predicate(Lexer* lex);
  virtual ~Predicate();
  
  string toString();
  
  
  Parameter* createParameter(Lexer* lex);
  Parameter* createExpression(Lexer* lex);


  Parameter* myExp;
  Parameter* expressionParameter1;
  Parameter* expressionParameter2;
  Parameter* myPara;
  Id* predicateId;
  vector<Parameter*> predicateVec;
  
  
//   	Id predicateId
// 	vector<Parameter> parameters //not empty
// 	Rule(Lex lex)
// 		calls:new Id(lex)
// 		calls:Parameter.createParameter(lex)
};
#endif
