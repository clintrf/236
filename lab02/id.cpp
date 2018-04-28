#include "id.h"

Id::Id(Lexer* lex){
    Parameter::idFlag = 1;
    id = (lex)->getNextToken(ID);
}
 string Id::toString(){
    stringstream ss;
    //ss << ',';
    ss << this->id.getTokenValue();
    return ss.str();
 }
 
//  string Parameter::toString(){
//     stringstream ss;
//     ss << ',';
//     ss << this->id.getTokenValue();
//     return ss.str();
//  }