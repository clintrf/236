#include "parser_queries.h"

Queries::Queries(Lexer* lex){
    (lex)->getNextToken(QUERIES);
    (lex)->getNextToken(COLON);
    do {
        queriesVec.push_back(new Query(lex));
    } while ((lex)->tokenList.back().getTokenType() == ID);
}

Queries::~Queries(){
    for (unsigned int i = 0;i < queriesVec.size(); i++){
        delete queriesVec[i];
    }
}

string Queries::toString(){
    stringstream ss;
    for (unsigned int i = 0;i < queriesVec.size(); i++){
        ss << "  " << this->queriesVec[i]->myQueriesPredicate->toString();
        ss << "?" << endl;
    }
    return ss.str();
}

