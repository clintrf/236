#include "parser_parameter.h"

Parameter::Parameter(Lexer* lex){}

Parameter* Parameter::createParameter(Lexer* lex){
    if((lex)->tokenList.back().getTokenType() == STRING){
        return 0;
    }
    else if ((lex)->tokenList.back().getTokenType() == ID){
        return 0;
    }
    else{
    return 0;
    }
}

string Parameter::toString(){
        if(stringFlag == 1){
            return "string";
        }
        else if (idFlag == 1){
            return "id";
        }
        else{
            return "exp";
        }
}

