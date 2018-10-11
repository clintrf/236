#include <iostream>
#include "lexer_token.h"
#include "lexer_lexer.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

Lexer::Lexer(istream* fileName){
  this->inFile = fileName;
}

void Lexer::analysisFile(){
  char currChar;
  while (true){
    currChar = this->inFile->get();
    if (this->inFile->eof()){
      tokenList.push_back(Token(END_OF_FILE,getCurrLineNum(),""));
      break;
    }     
    if(isspace(currChar)){
      if(currChar == '\n'){
        currLineNum++;
      }
      continue;
    }
    switch(currChar){
      case ',':
        tokenList.push_back(Token(COMMA,getCurrLineNum(), ","));
        break;
      case '.':
        tokenList.push_back(Token(PERIOD,getCurrLineNum(), "."));
        break;
      case '?':
        tokenList.push_back(Token(Q_MARK,getCurrLineNum(), "?"));
        break;
      case '(':
        tokenList.push_back(Token(LEFT_PAREN,getCurrLineNum(), "("));
        break;
      case ')':
        tokenList.push_back(Token(RIGHT_PAREN,getCurrLineNum(), ")"));
        break;
      case ':':
        colonCase();
        break;
      case '*':
        tokenList.push_back(Token(MULTIPLY,getCurrLineNum(), "*"));
        break;
      case '+':
        tokenList.push_back(Token(ADD,getCurrLineNum(), "+"));
        break;
      case '\'':
        tokenList.push_back(Token(gettokenTypeDef(STRING),getCurrLineNum(), this->stringInput()));
        correctCurrLineNum();
        break;
      case '#':
        tagCase();
        break;
      default:
        defaultIfCase(currChar);
        break;
    }
  }
}

void Lexer::colonCase(){
  if(this->inFile->peek() == '-'){
    this->inFile->get();
    tokenList.push_back(Token(COLON_DASH,getCurrLineNum(), ":-"));
  }
  else {
    tokenList.push_back(Token(COLON,getCurrLineNum(), ":" ));
  }
}

void Lexer::tagCase(){
  if (this->inFile->peek() == '|') {
    this->inFile->get();
    tokenList.push_back(Token(gettokenTypeDef(COMMENT),getCurrLineNum(), this->multi_line_comment()));
  } 
  else {
    tokenList.push_back(Token(COMMENT,getCurrLineNum(), this->single_line_comment()));
  }
  correctCurrLineNum();
}

void Lexer::defaultIfCase(char currChar){
  if(isalpha(currChar)){
    this->inFile->putback(currChar);
    string tempString = this->identifierString();
    tokenTypeDef tempTokenType = identifierType(tempString);
    tokenList.push_back(Token(tempTokenType,getCurrLineNum(), tempString));
  }
  else{
    string undefinedString = "";
    undefinedString += currChar;
    tokenList.push_back(Token(UNDEFINED,getCurrLineNum(), undefinedString ));
  }  
}

string Lexer::print(){
  stringstream sTemp;
  for(unsigned int i = 0; i <tokenList.size(); i++){
      sTemp << "(" << typeToString(tokenList.at(i).tokenType) << ",\"" << tokenList.at(i).tokenValue << "\"," << tokenList.at(i).tokenLineNum << ")" << std::endl;
  }
  sTemp << "Total Tokens = " << tokenList.size();
  return sTemp.str();
}

string Lexer::typeToString(tokenTypeDef typeDef){
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

string Lexer::single_line_comment(){
  string startString = "#";
  char currChar;
  while(true){
    currChar = this->inFile->get();
    if(this->inFile->eof()){
      break;
    }
    if( currChar == '\n'){
      setLineCounter();
      currLineNum++;
      break;
    }
    startString += currChar;
  }
  evalCurrLineNum();
  return startString;
}
string Lexer::multi_line_comment(){
  string startString = "#|";
  char currChar;
  while (true){
    
    currChar = this->inFile->get();
    if(this->inFile->eof()){
      setEofFlag();
      evalCurrLineNum();
      return startString;
    }
    if(currChar == '|' && this->inFile->peek() == '#'){
      this->inFile->get();
      startString += "|#";
      evalCurrLineNum();
      return startString;
    }
    if (currChar =='\n'){
      setLineCounter();
      currLineNum++;
    }
    startString += currChar;
  }
}    
string Lexer::identifierString(){  
  string startString = "";
  while (isalpha(this->inFile->peek()) || isalnum(this->inFile->peek())) {
    startString += this->inFile->get();
  }
  
  return startString;
}
tokenTypeDef Lexer::identifierType(string tempString){
  if (this->keywords.find(tempString) != this->keywords.end()) {
    return keywords[tempString];
  } 
  else {
    return ID;
  }
}
string Lexer::stringInput(){ 
  string startString = "'";
  char currChar;
  while(true){
    currChar = this->inFile->get();
    if(this->inFile->eof()){
      setEofFlag();
      evalCurrLineNum();
      return startString;
    }
    if(currChar == '\''){
      if(this->inFile->peek() == '\''){
        startString += currChar;
        currChar = this->inFile->get();
      }
      else{
        startString += '\'';
        evalCurrLineNum();
        return startString;
      }
    }
    if(currChar == '\n'){
      setLineCounter();
      currLineNum++;
    }
    startString += currChar;
  }
}
void Lexer::setLineCounter(){
  lineCounter++;
}
void Lexer::evalCurrLineNum(){
  currLineNum -= lineCounter;
}
void Lexer::correctCurrLineNum(){
  while(lineCounter != 0){
    currLineNum++;
    lineCounter--;
  }
}
int Lexer::getCurrLineNum(){
  return currLineNum;
}
bool Lexer::setEofFlag(){
  eofFlag = true;
  return eofFlag;
}
tokenTypeDef Lexer::gettokenTypeDef(tokenTypeDef typeTemp){
  if(eofFlag){
    return UNDEFINED;
    eofFlag = false;
  }
  else{
    return typeTemp;
  }
}