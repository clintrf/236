#ifndef PARSER_RULES_H
#define PARSER_RULES_H


#include "lexer_lexer.h"

#include "parser_rule.h"
#include "parser_predicate.h"
#include "parser_headPredicate.h"
#include "parser_predicate.h"
#include <string>
#include <vector>
using namespace std;

class Rules{
    public:
    Rules(Lexer* lex, vector<Rule*>* myVecRule,
    vector<Predicate*>* myVecPredicate,
    vector<HeadPredicate*>* myVecHeadPredicate,
    vector<Parameter*>* myVecParam){
      (lex)->getNextToken(RULES);
      (lex)->getNextToken(COLON);
      while ((lex)->tokenList.back().getTokenType() == ID) {
          Rule* r1 = new Rule(lex, myVecPredicate, myVecHeadPredicate, myVecParam);
          this->rulesVec.push_back(r1);
          myVecRule->push_back(r1);
      }
    };
    
    ~Rules(){};
    string toString(){
      stringstream ss;
      for (unsigned int i = 0; i < rulesVec.size(); i++){
          ss << "  " << this->rulesVec[i]->ruleHeadPredicate->toString();
          ss << this->rulesVec[i]->ruleVec[0]->toString();
          for(unsigned int j = 1; j < this->rulesVec[i]->ruleVec.size(); j++){

              if (j != this->rulesVec[i]->ruleVec.size()){
                  ss<< ",";
              }
              ss << this->rulesVec[i]->ruleVec[j]->toString();
          }
          ss << "." << endl;
      }
      return ss.str();
    };

    vector<Rule*> rulesVec;

};

#endif
