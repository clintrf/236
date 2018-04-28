#include "string.h"


String::String(Lexer* lex){
    Parameter::stringFlag = 1;
    myStringToken = (lex)->getNextToken(STRING);
}

string String::toString(){
    stringstream ss;
    //ss << ',';
    ss << this->myStringToken.getTokenValue();
    return ss.str();
}