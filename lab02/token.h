#ifndef TOKEN_H
#define TOKEN_H

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
        Token(tokenTypeDef token_type, int token_line_num, string token_value);
        ~Token(){};
        
        tokenTypeDef getTokenType();
        string getTokenValue();
        int getTokenLineNum();
        
        string toString();

		map<string, tokenTypeDef> keywords = {{"Schemes", SCHEMES}, {"Facts", FACTS}, {"Rules", RULES}, {"Queries", QUERIES}};
        string typeToString(tokenTypeDef typeDef);
        
        tokenTypeDef tokenType;
        string tokenValue;
        int tokenLineNum;
        
};

#endif