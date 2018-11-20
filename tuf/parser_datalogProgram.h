#ifndef PARSER_DATALOGPROGRAM_H
#define PARSER_DATALOGPROGRAM_H

#include "lexer_lexer.h"

#include <string>

using namespace std;

class DatalogProgram{
    public:
    DatalogProgram(Lexer lex);
    ~DatalogProgram(){};
    string toString();
    
};
#endif
