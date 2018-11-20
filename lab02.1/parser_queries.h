#ifndef PARSER_QUERIES_H
#define PARSER_QUERIES_H

#include "lexer_lexer.h"
#include "parser_query.h"
#include <string>
#include <vector>
using namespace std;

class Queries{
    public:
      Queries(Lexer* lex, vector<Query*>* myVecQuery,
      vector<Predicate*>* myVecPredicate,
      vector<Parameter*>* myVecParam){
        (lex)->getNextToken(QUERIES);
        (lex)->getNextToken(COLON);
        do {
            Query* q1 = new Query(lex, myVecPredicate, myVecParam);
            queriesVec.push_back(q1);
            myVecQuery->push_back(q1);

        } while ((lex)->tokenList.back().getTokenType() == ID);
      };
    ~Queries(){};

    string toString(){
      stringstream ss;
        for (unsigned int i = 0;i < queriesVec.size(); i++){
            ss << "  " << this->queriesVec[i]->myQueriesPredicate->toString();
            ss << "?" << endl;
        }
        return ss.str();
      };

    vector<Query*> queriesVec;

};

#endif
