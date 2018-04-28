#ifndef LEXER_H
#define LEXER_H

#include "token.h"
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
    //string printP();
    
    string typeToString(tokenTypeDef typeDef);
    string single_line_comment();
    string multi_line_comment();    
    string identifierString();
    tokenTypeDef identifierType(string tempString);
    string stringInput();
    
    void setLineCounter();
    void evalCurrLineNum();
    void correctCurrLineNum();
    int getCurrLineNum();
    
    bool setEofFlag();
    vector<Token> getTokenList();
    tokenTypeDef gettokenTypeDef(tokenTypeDef typeTemp);
    
    map<string, tokenTypeDef> keywords = {{"Schemes", SCHEMES}, {"Facts", FACTS}, {"Rules", RULES}, {"Queries", QUERIES}};
    
    //funtion for Lab 2
    Token getNextToken(tokenTypeDef tokenType);
    //vector<Token*> pTokenList();
    void clearComments();
    

    vector<Token> tokenList;//list of all the tokens found
    //vector<Token*> tokenP;//list of all the tokens found
    istream* inFile;
    
private:    
    int lineCounter = 0;
    int currLineNum = 1;
    bool eofFlag = false;
};

#endif