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
    Parameter* myPara = NULL;
    Id* predicateId = NULL;
    vector<Parameter*> predicateVec;

    Predicate(){};
    Predicate(Lexer* lex, vector<Parameter*>* myVecParam){
      predicateId = new Id(lex);
      myVecParam->push_back(predicateId);
      (lex)->getNextToken(LEFT_PAREN);
      predicateVec.push_back(createParameter(lex, myVecParam));
      while((lex)->tokenList.back().getTokenType() == COMMA){
          (lex)->tokenList.pop_back();
          predicateVec.push_back(createParameter(lex, myVecParam));
      }
      (lex)->getNextToken(RIGHT_PAREN);
    };
    virtual ~Predicate(){};

    Parameter* createParameter(Lexer* lex, vector<Parameter*>* myVecParam){
      if((lex)->tokenList.back().getTokenType() == STRING){
          this->myPara = new String(lex);
          myVecParam->push_back(myPara);
          return this->myPara;
      }
      else if ((lex)->tokenList.back().getTokenType() == ID){
          this->myPara = new Id(lex);
          myVecParam->push_back(myPara);
          return this->myPara;
      }
      else{
          this->myPara = createExpression(lex, myVecParam);
          myVecParam->push_back(myPara);
          return this->myPara;
      }
    };

    Parameter* createExpression(Lexer* lex, vector<Parameter*>* myVecParam){
      tokenTypeDef expressionOperator;
      (lex)->getNextToken(LEFT_PAREN);
      Parameter* expressionParameter1 = createParameter(lex, myVecParam);
      expressionOperator = (lex)->tokenList.back().getTokenType();
      (lex)->tokenList.pop_back();
      Parameter* expressionParameter2 = createParameter(lex, myVecParam);
      (lex)->getNextToken(RIGHT_PAREN);
      Expression* myExp = new Expression(expressionParameter1,expressionOperator,expressionParameter2);
      return myExp;
    };

    tokenTypeDef expressionOperator(Lexer* lex, vector<Parameter*>* myVecParam){
      tokenTypeDef expressionOperator1 = (lex)->tokenList.back().getTokenType();
      (lex)->tokenList.pop_back();
      return expressionOperator1;
    };

    string toString(){
      stringstream ss;
      ss << predicateId->id.getTokenValue() << "(";
      ss << predicateVec[0]->toString();
      for (unsigned int i = 1;i < predicateVec.size(); i++){

          if (i != predicateVec.size()){
              ss<< ",";
          }
                  ss << predicateVec[i]->toString();
      }
      ss << ")";
      return ss.str();
    };

    vector<Parameter> getParamList(){
      vector<Parameter> temp;
      for(unsigned int i=0; i<predicateVec.size(); i++){
        temp.push_back(*predicateVec[i]);
      }
      return temp;
    };

    int getIDLine() {
  		return predicateId->id.getLine();
  	}
  	string getIDLiteral() {
  		return predicateId->id.getLiteral();
  	}
  	string getIDName() {
  		return predicateId->id.getName();
  	}


};
#endif
