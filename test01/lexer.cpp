#include <iostream>
#include "lexer.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm> 
using namespace std;

Lexer::Lexer(istream* fileName){
  this->inFile = fileName;
  analysisFile();
  //pTokenList();
  reverse(tokenList.begin(),tokenList.end());
  clearComments();
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
        if(this->inFile->peek() == '-'){
          this->inFile->get();
          tokenList.push_back(Token(COLON_DASH,getCurrLineNum(), ":-"));
          break;
        }
        else {
          tokenList.push_back(Token(COLON,getCurrLineNum(), ":" ));
          break;
        }
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
        if (this->inFile->peek() == '|') {
          this->inFile->get();
          tokenList.push_back(Token(gettokenTypeDef(COMMENT),getCurrLineNum(), this->multi_line_comment()));
        } 
        else {
          tokenList.push_back(Token(COMMENT,getCurrLineNum(), this->single_line_comment()));
        }
        correctCurrLineNum();
        break;
      default:
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
        break;
    }
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
// string Lexer::printP(){
//   stringstream sTemp;
//   for(int i = 0; i < this->tokenP.size(); i++){
//       sTemp << "(" << typeToString(tokenP[i]->tokenType) << ",\"" << tokenP[i]->tokenValue << "\"," << tokenP[i]->tokenLineNum << ")" << std::endl;
//   }
//   sTemp << "Total Tokens = " << tokenP.size();
//   return sTemp.str();
// }

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
vector<Token> Lexer::getTokenList(){
  return tokenList;
}

// vector<Token*> Lexer::pTokenList(){
//   for(int i =0; i < tokenList.size(); i++){
//     if(tokenList[i].getTokenType() == COMMENT){
//       i++;
//     }
//     tokenP.push_back(new Token(tokenList[i]));
//   }
//   return tokenP;
// }

Token Lexer::getNextToken(tokenTypeDef tokenType){
  Token result = tokenList.back();
  tokenTypeDef resultType = result.getTokenType();
  if((resultType == EOF && tokenType != EOF) || resultType != tokenType){
  
    throw result;
  }

  tokenList.pop_back(); 
  return result;
}

void Lexer::clearComments(){
  int commentFlag = 0;
  vector<Token> tmp;
  for(unsigned int i =0; i < tokenList.size(); i++){
    commentFlag = 0;
    if(tokenList[i].getTokenType() == COMMENT){
      commentFlag = 1;
    }
    if(commentFlag == 0){
      tmp.push_back(Token(tokenList[i]));
    }
  }
  tokenList.clear();
  tokenList = tmp;
}