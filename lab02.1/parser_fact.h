#ifndef PARSER_FACT_H
#define PARSER_FACT_H

#include "lexer_lexer.h"
#include "parser_string.h"
#include "parser_id.h"
#include "parser_parameter.h"
#include <string>
#include <vector>
using namespace std;

class Fact{
    public:
    Fact(Lexer* lex, vector<Parameter*>* myVecParam){
      factId = new Id(lex);
      myVecParam->push_back(factId);

      (lex)->getNextToken(LEFT_PAREN);
      String* s1 = new String(lex);
      factVec.push_back(s1);
      myVecParam->push_back(s1);


      while((lex)->tokenList.back().getTokenType() == COMMA){
          (lex)->tokenList.pop_back();
          String* s2 = new String(lex);
          factVec.push_back(s2);
          myVecParam->push_back(s2);
      }
      (lex)->getNextToken(RIGHT_PAREN);
      (lex)->getNextToken(PERIOD);
    };
    ~Fact(){};


    Id* factId;
    vector<String*> factVec;

    string toString(){
      stringstream ss;
      ss << factId->getLiteral() << '(';
      for (int i=0; i < factVec.size(); i++) {
        ss << factVec[i]->toString();
        if (i < factVec.size()-1)
          ss << ',';
      }
      ss << ")";
      return ss.str();
    };

};
#endif
