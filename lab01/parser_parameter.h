#ifndef PARSER_PARAMETER_H
#define PARSER_PARAMETER_H

#include "lexer_lexer.h"
#include "lexer_token.h"


#include <string>
#include <vector>
using namespace std;

class Parameter{
    public:
    Parameter(){};
    Parameter(Lexer* lex);
    ~Parameter(){};
    
    int stringFlag;
    int idFlag;
    int expressionFlag;
    
    virtual string toString() = 0 ;
    
    static Parameter* createParameter(Lexer* lex);
    
    
    
    
//     Parameter is an abstract class
// 	static Parameter createParameter(Lex lex)
// 		calls: new Id(lex)
// 		calls: new String(lex)
// 		calls: new Expression(lex)
};
#endif
