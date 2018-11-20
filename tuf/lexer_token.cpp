#include <sstream>
#include "lexer_token.h"
#include <string>

using namespace std;

Token::Token(tokenTypeDef token_type, int token_line_num, string token_value){
    this->tokenType = token_type;
    this->tokenValue = token_value;
    this->tokenLineNum = token_line_num;
};
string Token::toString(){
    stringstream ss;
    ss << "(" << typeToString(tokenType) << ",\"" << tokenValue << "\"," << tokenLineNum << ")" << std::endl;
    //string s;
    //s = to_string(ss);
    return ss.str();
    
};


string Token::typeToString(tokenTypeDef typeDef){
      string stringType;
  switch (typeDef){
    case COMMA: stringType = "COMMA"; break;
    case PERIOD: stringType = "PERIOD"; break;
    case Q_MARK: stringType = "Q_MARK"; break;
    case LEFT_PAREN: stringType = "LEFT_PAREN"; break;
    case RIGHT_PAREN: stringType = "RIGHT_PAREN"; break;
    case COLON: stringType = "COLON"; break;
    case COLON_DASH: stringType = "COLON_DASH"; break;
    case MULTIPLY: stringType = "MULTIPLY"; break;
    case ADD: stringType = "ADD"; break;
    case SCHEMES: stringType = "SCHEMES"; break;
    case FACTS: stringType = "FACTS"; break;
    case RULES: stringType = "RULES"; break;
    case QUERIES: stringType = "QUERIES"; break;
    case ID: stringType = "ID"; break;
    case STRING: stringType = "STRING"; break;
    case COMMENT: stringType = "COMMENT"; break;
    case WHITESPACE: stringType = "WHITESPACE"; break;
    case UNDEFINED: stringType = "UNDEFINED"; break;
    case END_OF_FILE: stringType = "EOF"; break;
    default: stringType = "ERROR"; break;
  }
  return stringType;
}

tokenTypeDef Token::getTokenType(){
    return tokenType;
};
string Token::getTokenValue(){
    return tokenValue;
};
int Token::getTokenLineNum(){
    return tokenLineNum;
};
