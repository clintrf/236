#ifndef PREDICATE_H
#define PREDICATE_H

#include "lexer.h"
#include <vector>
#include "parameter.h"
#include "id.h"
#include "string.h"
#include "expression.h"
#include <string>

using namespace std;

class Predicate {
  public:
  Predicate(){};
  Predicate(Lexer* lex);
  ~Predicate(){};
  
  string toString();
  
  
  Parameter* createParameter(Lexer* lex);
  Parameter* createExpression(Lexer* lex);
  
  Id* predicateId;
  vector<Parameter*> predicateVec;
  
  
//   	Id predicateId
// 	vector<Parameter> parameters //not empty
// 	Rule(Lex lex)
// 		calls:new Id(lex)
// 		calls:Parameter.createParameter(lex)
};
#endif
