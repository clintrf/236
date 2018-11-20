#ifndef LEXER_TOKEN_H
#define LEXER_TOKEN_H

#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

enum tokenTypeDef {
  COMMA,
	PERIOD,
	Q_MARK,
	LEFT_PAREN,
	RIGHT_PAREN,
	COLON,
	COLON_DASH,
	MULTIPLY,
	ADD,
	SCHEMES,
	FACTS,
	RULES,
	QUERIES,
	ID,
	STRING,
	COMMENT,
	WHITESPACE,
	UNDEFINED,
	END_OF_FILE
};

class Token{
  public:
    Token(){};
  // Token(int token_line_num = -1, string token_value = "", string name = "UNDEFINED") {
  //     this->tokenLineNum = token_line_num;
  //     this->tokenValue = token_value;
  //     this->tokenType = stringToType(name);
  // }
  Token(tokenTypeDef token_type, int token_line_num, string token_value){
      this->tokenType = token_type;
      this->tokenValue = token_value;
      this->tokenLineNum = token_line_num;
  };

  ~Token(){};

  tokenTypeDef getTokenType(){return tokenType;};
  string getTokenValue(){return tokenValue;};
  int getTokenLineNum(){return tokenLineNum;};

  int getLine(){return tokenLineNum;};
  string getLiteral(){return tokenValue;};
  string getName(){return typeToString(tokenType);};

  bool isType(string name){
      if (name == this->getName()){return true;};
      return false;
  };

  string typeToString(tokenTypeDef typeDef){
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
  };
  // tokenTypeDef stringToType(string  s){
  //     tokenTypeDef stringType;
  //     if(s == "COMMA"){stringType = COMMA;};
  //     if(s == "PERIOD"){stringType = PERIOD;};
  //     if(s == "Q_MARK"){stringType = Q_MARK;};
  //     if(s == "LEFT_PAREN"){stringType = LEFT_PAREN;};
  //     if(s == "RIGHT_PAREN"){stringType = RIGHT_PAREN;};
  //     if(s == "COLON"){stringType = COLON;};
  //     if(s == "COLON_DASH"){stringType = COLON_DASH;};
  //     if(s == "MULTIPLY"){stringType = MULTIPLY;};
  //     if(s == "ADD"){stringType = ADD;};
  //     if(s == "SCHEMES"){stringType = SCHEMES;};
  //     if(s == "FACTS"){stringType = FACTS;};
  //     if(s == "RULES"){stringType = RULES;};
  //     if(s == "QUERIES"){stringType = QUERIES;};
  //     if(s == "ID"){stringType = ID;};
  //     if(s == "STRING"){stringType = STRING;};
  //     if(s == "COMMENT"){stringType = COMMENT;};
  //     if(s == "WHITESPACE"){stringType = WHITESPACE;};
  //     if(s == "UNDEFINED"){stringType = UNDEFINED;};
  //     if(s == "EOF"){stringType = END_OF_FILE;};
  //
  //     return stringType;
  // };

  string toString(){
      stringstream ss;
      ss << "(" << typeToString(tokenType) << ",\"" << tokenValue << "\"," << tokenLineNum << ")" << std::endl;
      return ss.str();
  };

  map<string, tokenTypeDef> keywords = {{"Schemes", SCHEMES}, {"Facts", FACTS}, {"Rules", RULES}, {"Queries", QUERIES}};
  tokenTypeDef tokenType;
  string tokenValue;
  int tokenLineNum;


};

#endif
