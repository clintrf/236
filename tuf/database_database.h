#ifndef DATABASE_DATABASE_H
#define DATABASE_DATABASE_H

#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

#include "database_relation.h"
#include "parser_parser.h"


using namespace std;

class Database : public map<string, Relation> {
public:
	Database(vector<HScheme> schemes, vector<Fact> facts){add(move(schemes));add(move(facts));};
	Database(vector<HScheme> schemes){add(move(schemes));};
	~Database(){};
	
	map<string, Relation> rMap;
		
	Relation stgSelect(Relation &relation, Query query){
		map<int,string> constants;
		map<string, vector<int>> variables;
		Predicate predicate = query.getPredicate();
		vector<Parameter> params = predicate.getParamList();
			for (int i = 0, max = static_cast<int>(params.size()); i < max; i++) {
			if (params[i].getType() == "STRING") {
			  constants.emplace(i, params[i].getValue());
			}
			if (params[i].getType() == "ID") {
			  string value = params[i].getValue();
			  const iter = variables.find(value);
			  if (iter != variables.end()) {variables.at(value).emplace_back(i);};
			  else {variables.emplace(params[i].getValue(), vector<int>{i});};
			}
		}
		
		// Select Constants
		for (const &c : constants) {
		relation = relation.select(c.first, c.second);
		}
		
		// Select Variables
		for (const &v : variables) {
			vector<int> positions = v.second;
			if (positions.size() > 1) {relation = relation.select(positions);};
		}
		return relation;
	};
	
	Relation stgProject(Relation &relation, Query query){
		Predicate predicate = query.get_predicate();
		vector<Parameter> params = predicate.getParamList();
		
		vector<int> positions;
		vector<string> variableNames;
		for (size_t i = 0, max = params.size(); i < max; i++) {
			if (params[i].getType() == "ID") {
				string value = params[i].getValue();
				bool found = find(variableNames.begin(), variableNames.end(), value) != variableNames.end();
				if (!found) {
					variable_names.emplace_back(value);
					positions.emplace_back(i);
				}
			}
		}
		relation = relation.project(positions);
	};
	
	Relation stgRename(Relation &relation, Query query){
		Predicate predicate = query.get_predicate();
		std::vector<Parameter> params = predicate.get_param_list();
		
		// Find unique variable ordering
		vector<string> variableNames;
		for (const &p : params) {
			if (p.getType() == "ID") {
				string value = p.getValue();
				bool found = find(variableNames.begin(), variableNames.end(), value) != variableNames.end();
				if (!found) variableNames.emplace_back(value);
    		}
		}

		for (unsigned int i = 0, max = variableNames.size(); i < max; i++) {
    		relation = relation.rename(static_cast<int>(i), variableNames[i]);
		}
		return relation;
	};
	
	void add(HScheme scheme){
		string relationName = scheme.getName();
		List headers = scheme.getList();
		if(!exists(relationName)){
			Relation newRelation(relationName, headers);
			this->rMap.emplace(RelationName, newRelations);
		}
	};
	void add(Fact fact){
		const relationName=fact.getName();
		if(exists(relationName)){
			this->rMap.at(relationName).add(fact.getList());
		}
	};
	void add(vector<HScheme> schemes){for(const &s : schemes){add(s);};};
	void add(vector<Fact> facts){for(const &f : facts){add(f);};};
	
	Relation eval(Query){
		string relationName=query.getPredicate().getId();
		Relation relation = look_up(relationName);
		relation=stgSelect(relation,query);
		relation=stgProject(relation,query);
		relation=stgRename(relation,query);
		return relation;
	};
	
	vector<Relation> eval(vector<Query> queries){
		vector<Relation> relations;
		for(const &q : queries){
			relations.emplace_back(eval(query));
		}
		return relations
	};
	
	bool exists(string relationName){
		const iter = this->rMap.find(relationName);
		return iter != this->rMap.end();
	};
	Relation look_up(string relationName){
		if(exists(relationName)){return this->rMap.at(relationName);};
		else{return Relation();};
	};
	string toString(){
		stringstream ss;
		for(const &r :this->rMap){
			ss << relation.first << endl;
			ss << relation.second.toString() << endl;
		}
		return ss.str();
	};
};
#endif