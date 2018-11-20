#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include <iostream>
#include "lexer_lexer.h"



#include "parser_schemes.h"
#include "parser_facts.h"
#include "parser_rules.h"
#include "parser_queries.h"

#include "parser_scheme.h"
#include "parser_fact.h"
#include "parser_rule.h"
#include "parser_query.h"

#include "parser_predicate.h"
#include "parser_headPredicate.h"
#include "parser_parameter.h"

#include "database_dataLog.h"


#include <vector>
#include <set>
#include <string>

using namespace std;

set <string> domain;
set<string>::iterator it;

class Parser{
    public:
      Schemes* mySchemes = NULL;
      Facts* myFacts = NULL;
      Rules* myRules = NULL;
      Queries* myQueries = NULL;

      vector<Scheme*> myVecScheme;
      vector<Fact*> myVecFact;
      vector<Rule*> myVecRule;
      vector<Query*> myVecQuery;
      vector<Predicate*> myVecPredicate;
      vector<HeadPredicate*> myVecHeadPredicate;
      vector<Parameter*> myVecParam;

      string catchOut;
      int failFlag = 1;

      DataLog dataLog;

      DataLog getDataLog() {
        return dataLog;
      }

      Parser(){};
      Parser(Lexer* lex){

        try{
          Lexer* lex2 = lex;

            myVecScheme.push_back(NULL);
            myVecFact.push_back(NULL);
            myVecRule.push_back(NULL);
            myVecQuery.push_back(NULL);

            myVecPredicate.push_back(NULL);
            myVecHeadPredicate.push_back(NULL);
            myVecParam.push_back(NULL);

            mySchemes = new Schemes(lex, &myVecScheme, &myVecParam);
            myFacts = new Facts(lex, &myVecFact, &myVecParam);
            domainAdd(lex2);
            myRules = new Rules(lex, &myVecRule , &myVecPredicate, &myVecHeadPredicate, &myVecParam);
            myQueries = new Queries(lex, &myVecQuery , &myVecPredicate, &myVecParam);


            for(unsigned int i = 0; i<mySchemes->schemesVec.size(); i++){
              dataLog.addScheme(mySchemes->schemesVec[i]);
            }
            for(unsigned int i = 0; i<myFacts->factsVec.size(); i++){
              dataLog.addFact(myFacts->factsVec[i]);
            }
            for(unsigned int i = 0; i<myRules->rulesVec.size(); i++){
              dataLog.addRule(myRules->rulesVec[i]);
            }
            for(unsigned int i = 0; i<myQueries->queriesVec.size(); i++){
              dataLog.addQuery(myQueries->queriesVec[i]);
            }


            (lex)->getNextToken(END_OF_FILE);
            failFlag = 0;

        }catch(Token token){
          //cout << "Failure!" << endl;
              //cout << "  " << token.toString();

              catchOut += "Failure!\n";
              catchOut += "  " ;
              catchOut += token.toString();

              failFlag = 1;
        }
      };
      ~Parser(){};

      vector<Scheme*> getSchemes(){return (mySchemes->schemesVec);};
      vector<Fact*> getFacts(){return myFacts->factsVec;};
      vector<Rule*> getRules(){return myRules->rulesVec;};
      vector<Query*> getQueries(){return myQueries->queriesVec;};


      void domainAdd(Lexer* lex){
        for(unsigned int i = 0; i < myFacts->factsVec.size(); i++){
            for(unsigned int  j = 0; j < myFacts->factsVec[i]->factVec.size(); j++){
                domain.insert(myFacts->factsVec[i]->factVec[j]->myStringToken.getTokenValue());
            }
        }
      };

      string printDomain(){
        stringstream ss;
        for(it =  domain.begin();it != domain.end(); it++){
          ss << "  " << *it << endl;
        }
        return ss.str();
      };

      string toString(){
        string out;
          if(failFlag == 0){
          stringstream ss;
          out = "Success!\n";
          ss << mySchemes->schemesVec.size();
          out += "Schemes(" + ss.str() + "):\n";
          ss.str("");
          out += this->mySchemes->toString();

          ss.str("");
          ss << myFacts->factsVec.size();
          out += "Facts(" + ss.str() + "):\n";
          ss.str("");
          out += this->myFacts->toString();

          ss.str("");
          ss << myRules->rulesVec.size();
          out += "Rules(" + ss.str() + "):\n";
          ss.str("");
          out += this->myRules->toString();

          ss.str("");
          ss << myQueries->queriesVec.size();
          out += "Queries(" + ss.str() + "):\n";
          ss.str("");
          out += this->myQueries->toString();

          ss.str("");
          ss << domain.size();
          out += "Domain(" + ss.str() + "):\n";
          ss.str("");
          out += printDomain();
          }
        return out;
      };

      void clearMemory(){
        delete mySchemes;
        delete myFacts;
        delete myRules;
        delete myQueries;
        for (unsigned int i = 0;i < myVecScheme.size(); i++){delete myVecScheme[i];};
        for (unsigned int i = 0;i < myVecFact.size(); i++){delete myVecFact[i];};
        for (unsigned int i = 0;i < myVecRule.size(); i++){delete myVecRule[i];};
        for (unsigned int i = 0;i < myVecQuery.size(); i++){delete myVecQuery[i];};
        for (unsigned int i = 0;i < myVecPredicate.size(); i++){delete myVecPredicate[i];};
        for (unsigned int i = 0;i < myVecHeadPredicate.size(); i++){delete myVecHeadPredicate[i];};
        for (unsigned int i = 0;i < myVecParam.size(); i++){delete myVecParam[i];};
      };

};

#endif
