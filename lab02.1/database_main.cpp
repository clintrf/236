#include <string>
#include <fstream>
#include <iostream>

#include "lexer_token.h"
#include "lexer_lexer.h"
#include "parser_parser.h"
#include "database_database.h"

using namespace std;

int main(int argc, const char* argv[]) {
	ofstream outfile;
	ifstream inputfile;
	inputfile.open (argv[1]);
	outfile.open(argv[2]);

	Lexer lex = Lexer(&inputfile);
	//vector<Token> tokens = lex.getTokenList();
	// LexicalAnalyzer lexigraph(argv[1]);
	// vector<Token> tokens = lexigraph.getAllTokens();
	//reverse(tokens.begin(),tokens.end());

	Parser parser = Parser(&lex);
	//parser.parse();
	Database dataBase = Database(parser.getDataLog(), &outfile);


}
