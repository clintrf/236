#pragma once
#include "lexer_token.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Lexer {
public:
    Lexer(istream* fileName);
    ~Lexer(){};
    void analysisFile();
    string print();
    
    string typeToString(tokenTypeDef typeDef);
    string single_line_comment();
    string multi_line_comment();    
    string identifierString();
    tokenTypeDef identifierType(string tempString);
    string stringInput();
    
    void colonCase();
    void tagCase();
    void defaultIfCase(char currChar);
    
    void setLineCounter();
    void evalCurrLineNum();
    void correctCurrLineNum();
    int getCurrLineNum();
    
    bool setEofFlag();
    tokenTypeDef gettokenTypeDef(tokenTypeDef typeTemp);
    
    map<string, tokenTypeDef> keywords = {{"Schemes", SCHEMES}, {"Facts", FACTS}, {"Rules", RULES}, {"Queries", QUERIES}};
    
private:
    vector<Token> tokenList;                      //list of all the tokens found
    istream* inFile;
    
    int lineCounter = 0;
    int currLineNum = 1;
    bool eofFlag = false;
};