#include "parser_parser.h"
#include <set>
#include <string>

using namespace std;

set <string> domain;
set<string>::iterator it;

Parser::Parser(Lexer* lex){
	Lexer* lex2 = lex;
        //domainAdd(lex2);
    mySchemes = new Schemes(lex);
    myFacts = new Facts(lex);
    domainAdd(lex2);
    myRules = new Rules(lex);
    myQueries = new Queries(lex);
    (lex)->getNextToken(END_OF_FILE);
    
}

Parser::~Parser(){
	delete myQueries;
	delete mySchemes;
    delete myFacts;
    delete myRules;
}

string Parser::toString(){
    //if (this->errorToken != NULL) return "Failure!\n  " + this->errorToken->toString();
	stringstream ss;
	string out = "Success!\n";
	ss << mySchemes->schemesVec.size();
	out += "Schemes(" + ss.str() + "):\n";
	ss.str("");
	out += this->mySchemes->toString();
	
	ss.str("");
	ss << myFacts->factsVec.size();
	out += "Facts(" + ss.str() + "):\n";
	ss.str("");
	out += this->myFacts->toString();
	
	ss.str("");
	ss << myRules->rulesVec.size();
	out += "Rules(" + ss.str() + "):\n";
	ss.str("");
	out += this->myRules->toString();
	
	ss.str("");
	ss << myQueries->queriesVec.size();
	out += "Queries(" + ss.str() + "):\n";
	ss.str("");
	out += this->myQueries->toString();
	
	ss.str("");
	ss << domain.size();
	out += "Domain(" + ss.str() + "):\n";
	ss.str("");
	out += printDomain();
	
	return out;
}

string Parser::printDomain(){
	
	//myStringToken.getTokenValue();
	
	stringstream ss;
	for(it =  domain.begin();it != domain.end(); it++){
		ss << "  " << *it << endl;
	}
	return ss.str();
}

void Parser::domainAdd(Lexer* lex){
        for(unsigned int i = 0; i < myFacts->factsVec.size(); i++){
            for(unsigned int  j = 0; j < myFacts->factsVec[i]->factVec.size(); j++){
                domain.insert(myFacts->factsVec[i]->factVec[j]->myStringToken.getTokenValue());
            }
        }
}
