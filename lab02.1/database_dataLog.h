#ifndef DATABASE_DATALOG_H_
#define DATABASE_DATALOG_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>

#include "lexer_token.h"
// #include "parser_parameter.h"
// #include "parser_predicate.h"
// #include "parser_rule.h"
#include "parser_parser.h"
#include "parser_schemes.h"
#include "parser_scheme.h"
#include "parser_facts.h"
#include "parser_fact.h"
#include "parser_rules.h"
#include "parser_rule.h"
#include "parser_queries.h"
#include "parser_query.h"


using namespace std;

class DataLog {
public:

	DataLog(Schemes scheme, Facts fact, Rules rule, Queries query){
		this->schemes = scheme;
		this->facts = fact;
		this->rules = rule;
		this->queries = query;
	}

	void addScheme(Scheme* scheme) {
		schemes.push_back(scheme);
	}
	void addFact(Fact* fact) {
		facts.push_back(fact);
	}
	void addRule(Rule* rule) {
		rules.push_back(rule);
	}
	void addQuery(Query* querie) {
		queries.push_back(querie);
	}
	void addToDomain(string id) {
		domain.insert(id);
	}
	vector<Scheme*> getSchemes() {
		return schemes.returnSchemes();
	}
	vector<Fact*> getFacts() {
		return facts.returnFacts();
	}
	vector<Rule*> getRules() {
		return rules;
	}
	vector<Query*> getQueries() {
		return queries;
	}
	set<string> getDomain() {
		return domain;
	}
	string toString(){
		stringstream ss;
		//cout << "schemes" << endl;
		ss << "Schemes(" << schemes.size() << "):\n";
		for (int i = 0; i < schemes.size(); i++) {
			ss << "  " << schemes[i]->toString() << '\n';
		}
		//cout << "facts" << endl;
		ss << "Facts(" << facts.size() << "):\n";
		for (int i = 0; i < facts.size(); i++) {
			ss << "  " << facts[i]->toString() << "\n";
		}
		//cout << "rules" << endl;
		ss << "Rules(" << rules.size() << "):\n";
		for (int i = 0; i < rules.size(); i++) {
			ss << "  " << rules[i]->toString();
		}
		//cout << "Queries" << endl;
		ss << "Queries(" << queries.size() << "):\n";
		for (int i = 0; i < queries.size(); i++) {
			ss << "  " << queries[i]->toString() << "\n" ;
		}
		//cout << "Domain" << endl;
		ss << "Domain(" << domain.size() << "):\n";
		for (set<string>::iterator i = domain.begin(); i != domain.end(); i++) {
			ss << "  " << *i << '\n';
		}
		return ss.str();
	};
	// vector<Predicate> schemes;
	// vector<Predicate> facts;
	// vector<Rule> rules;
	// vector<Predicate> queries;
	// set<string> domain;

	Facts myFacts;

	Schemes schemes;
	Facts facts;
	Rules rules;
	Queries queries;
	set<string> domain;
};

#endif /* DATALOG_H_ */
