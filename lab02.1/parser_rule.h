#ifndef PARSER_RULE_H
#define PARSER_RULE_H

#include "lexer_lexer.h"
#include "parser_predicate.h"
#include "parser_headPredicate.h"
#include "parser_parameter.h"

#include <string>
#include <vector>
using namespace std;

class Rule{
    public:
      Rule(Lexer* lex, vector<Predicate*>* myVecPredicate,
      vector<HeadPredicate*>* myVecHeadPredicate,
      vector<Parameter*>* myVecParam){
        this->ruleHeadPredicate = new HeadPredicate(lex, myVecParam);
        myVecHeadPredicate->push_back(ruleHeadPredicate);

        (lex)->getNextToken(COLON_DASH);

        Predicate* p1 = new Predicate(lex, myVecParam);
        ruleVec.push_back(p1);
        myVecPredicate->push_back(p1);

        while((lex)->tokenList.back().getTokenType() == COMMA){
            (lex)->tokenList.pop_back();
            while((lex)->tokenList.back().getTokenType() == ID){
                Predicate* p2 = new Predicate(lex, myVecParam);
                ruleVec.push_back(p2);
                myVecPredicate->push_back(p2);
            }
        }
        (lex)->getNextToken(PERIOD);
      };

    ~Rule(){};

    string toString(){
      cout << "nothing in rule toString" << endl;
      return 0;
    };

    HeadPredicate* ruleHeadPredicate = NULL;
    vector<Predicate*> ruleVec;

};

#endif
