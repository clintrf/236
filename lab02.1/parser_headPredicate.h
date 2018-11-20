#ifndef PARSER_HEADPREDICATE_H
#define PARSER_HEADPREDICATE_H

#include "lexer_lexer.h"
#include "parser_id.h"
#include "parser_predicate.h"
#include <string>
#include <vector>
using namespace std;

class HeadPredicate{
    public:
    HeadPredicate(Lexer* lex, vector<Parameter*>* myVecParam){
      headPredicateId = new Id(lex);
      myVecParam->push_back(headPredicateId);

      (lex)->getNextToken(LEFT_PAREN);

      Id* i1 = new Id(lex);
      headPredicateIdVec.push_back(i1);
      myVecParam->push_back(i1);

      while((lex)->tokenList.back().getTokenType() == COMMA){
          (lex)->tokenList.pop_back();
          Id* i2 = new Id(lex);
          headPredicateIdVec.push_back(i2);
          myVecParam->push_back(i2);
      }
      (lex)->getNextToken(RIGHT_PAREN);
    };

    ~HeadPredicate(){};

    string toString(){
      stringstream ss;
      ss << this->headPredicateId->id.getTokenValue() << "(";
      ss << this->headPredicateIdVec[0]->id.getTokenValue();
      for(unsigned int i = 1; i < this->headPredicateIdVec.size(); i++){
          if (i != this->headPredicateIdVec.size()){
              ss<< ",";
          }
          ss << this->headPredicateIdVec[i]->toString();
      }
      ss << ") :- ";
      return ss.str();
    };

    Id* headPredicateId;
    vector<Id*> headPredicateIdVec;

};

#endif
