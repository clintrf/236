#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include <iostream>
#include "lexer_lexer.h"

#include "parser_schemes.h"
#include "parser_facts.h"
#include "parser_rules.h"
#include "parser_queries.h"

// #include "datalogProgram.h"
// #include "expression.h"
// #include "headPredicate.h"
// #include "id.h"
// #include "parameter.h"
// #include "predicate.h"
// #include "string.h"

// #include "scheme.h"
// #include "fact.h"
// #include "rule.h"
// #include "query.h"
#include <vector>

using namespace std;

class Parser{
    public:
    Parser(){};
    Parser(Lexer* lex);
    ~Parser();
    string toString();
    
    
    Schemes* mySchemes;
    Facts* myFacts;
    Rules* myRules;
    Queries* myQueries;
    
    string printDomain();
    void domainAdd(Lexer* lex);
};

#endif
