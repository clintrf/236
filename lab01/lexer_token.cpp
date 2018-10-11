#include <sstream>
#include "lexer_token.h"
#include <string>

using namespace std;

Token::Token(tokenTypeDef token_type, int token_line_num, string token_value){
    this->tokenType = token_type;
    this->tokenValue = token_value;
    this->tokenLineNum = token_line_num;
};
string Token::printTokens(){
    stringstream ss;
    ss << "(" << tokenType << ",\"" << tokenValue << "\"," << tokenLineNum << ")" << std::endl;
    string s;
    //s = to_string(ss);
    return s;
};




tokenTypeDef Token::getTokenType(){
    return tokenType;
};
string Token::getTokenValue(){
    return tokenValue;
};
int Token::getTokenLineNum(){
    return tokenLineNum;
};
