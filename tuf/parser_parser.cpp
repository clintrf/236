#include "parser_parser.h"
#include <set>
#include <string>

using namespace std;

set <string> domain;
set<string>::iterator it;

Parser::Parser(Lexer* lex){
	
	try{
		Lexer* lex2 = lex;
	    
	    myVecScheme.push_back(NULL);
    	myVecFact.push_back(NULL);
	    myVecRule.push_back(NULL);
	    myVecQuery.push_back(NULL);
	    
	    myVecPredicate.push_back(NULL);
	    myVecHeadPredicate.push_back(NULL);
	    myVecParam.push_back(NULL);
	    
	    mySchemes = new Schemes(lex, &myVecScheme, &myVecParam);
	    myFacts = new Facts(lex, &myVecFact, &myVecParam);
	    domainAdd(lex2);
	    myRules = new Rules(lex, &myVecRule , &myVecPredicate, &myVecHeadPredicate, &myVecParam);
	    myQueries = new Queries(lex, &myVecQuery , &myVecPredicate, &myVecParam);
	    
	    (lex)->getNextToken(END_OF_FILE);
	    failFlag = 0;
	    
	}catch(Token token){
		//cout << "Failure!" << endl;
        //cout << "  " << token.toString();
        
        catchOut += "Failure!\n";
        catchOut += "  " ;
        catchOut += token.toString();
        
        failFlag = 1;
	}
}

Parser::~Parser(){}

string Parser::toString(){
	string out;
    if(failFlag == 0){
		stringstream ss;
		out = "Success!\n";
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
    }
	return out;
}

string Parser::printDomain(){
	
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

void Parser::clearMemory(){

	delete mySchemes;

	delete myFacts;

	delete myRules;

	delete myQueries;

    for (unsigned int i = 0;i < myVecScheme.size(); i++){
        delete myVecScheme[i];
    }

    for (unsigned int i = 0;i < myVecFact.size(); i++){
        delete myVecFact[i];
    }

    for (unsigned int i = 0;i < myVecRule.size(); i++){
        delete myVecRule[i];
    }

    for (unsigned int i = 0;i < myVecQuery.size(); i++){
        delete myVecQuery[i];
    }

    for (unsigned int i = 0;i < myVecPredicate.size(); i++){
        delete myVecPredicate[i];
    }

    for (unsigned int i = 0;i < myVecHeadPredicate.size(); i++){
        delete myVecHeadPredicate[i];
    }

    for (unsigned int i = 0;i < myVecParam.size(); i++){
        delete myVecParam[i];
    }

}

vector<Scheme*> Parser::getSchemes() {
  return mySchemes->schemesVec;
}

vector<Fact*> Parser::getFacts() {
  return myFacts->factsVec;
}

vector<Rule*> Parser::getRules() {
  return myRules->rulesVec;
}

vector<Query*> Parser::getQueries() {
  return myQueries->queriesVec;
}
