#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H

#include "lexer.h"

#include <string>

using namespace std;

class DatalogProgram{
    public:
    DatalogProgram(Lexer lex);
    ~DatalogProgram(){};
    string toString();
    
};
#endif
