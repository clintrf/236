#ifndef PARSER_SCHEME_H
#define PARSER_SCHEME_H

#include "lexer_lexer.h"
#include "parser_id.h"
#include "parser_parameter.h"
#include <string>
#include <vector>
using namespace std;

class Scheme{
    public:
    Id* schemeId;
    vector<Id*> columnNames;

    Scheme(Lexer* lex, vector<Parameter*>* myVecParam){

      schemeId = new Id(lex);
      myVecParam->push_back(schemeId);

      (lex)->getNextToken(LEFT_PAREN);
      Id* i1 = new Id(lex);
      columnNames.push_back(i1);
      myVecParam->push_back(i1);

      while((lex)->tokenList.back().getTokenType() == COMMA){
          (lex)->tokenList.pop_back();

          Id* i2 = new Id(lex);
          columnNames.push_back(i2);
          myVecParam->push_back(i2);
      }
      (lex)->getNextToken(RIGHT_PAREN);
    };
    ~Scheme(){};

    Id* getId(){return schemeId;};

    string toString(){
      stringstream ss;
      ss << schemeId->getLiteral() << '(';
      for (int i=0; i < columnNames.size(); i++) {
        ss << columnNames[i]->toString();
        if (i < columnNames.size()-1)
          ss << ',';
      }
      ss << ")";
      return ss.str();
    };

};

#endif
