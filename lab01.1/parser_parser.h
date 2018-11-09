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



#include <vector>


using namespace std;

class Parser{
    public:
    Parser(){};
    Parser(Lexer* lex);
    ~Parser();
    string toString();

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
    
    string printDomain();
    string catchOut;
    int failFlag = 1;
    void domainAdd(Lexer* lex);
    void clearMemory();
};

#endif
