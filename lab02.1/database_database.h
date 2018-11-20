/*
 * Database.h
 *
 *  Created on: Jul 22, 2015
 *      Author: jacobmb
 */

#ifndef DATABASE_DATABASE_H_
#define DATABASE_DATABASE_H_

using namespace std;

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <ostream>
#include <fstream>
#include <iostream>


#include "database_dataLog.h"
#include "database_relation.h"
#include "database_sscheme.h"
#include "database_tuple.h"

#include "parser_predicate.h"
#include "parser_parameter.h"

class Database {
public:
	map<string, Relation> relations;
	ostream* out;
	vector<Predicate> queries;
	stringstream* ss = new stringstream();

	Database(DataLog dataLog , ostream* out){
		this->out = out;
		vector<Scheme*> schemes = dataLog.getSchemes();
		for (int i = 0; i < schemes.size(); i++) {
			string name = schemes[i].getIDLiteral();
			vector<Parameter> parameters = schemes[i].getParamList();
			SScheme scheme;
			for (int j = 0; j < parameters.size(); j++)
				scheme.push_back(parameters[j].getLiteral());
			relations.emplace(name, Relation(name, scheme));
		}
		//*out << "Scheme Evaluation" << endl << endl;
		vector<Fact*> facts = dataLog.getFacts();
		for (int i = 0; i < facts.size(); i++) {
			string name = facts[i].getIDLiteral();
			vector<Parameter> parameters = facts[i].getParamList();
			Tuple tuple;
			for (int j = 0; j < parameters.size(); j++)
				tuple.push_back(parameters[j].getLiteral());
			relations.at(name).addTuple(tuple);
		}
		//*out << "Fact Evaluation" << endl << endl;
//printRelations();
		//TODO add rules to database
		//*out << "Query Evaluation" << endl << endl;
		queries = dataLog.getQueries();
		evaluateQueries();

	};
	~Database() {delete ss;};

	void printRelations(){
		for (map<string, Relation>::iterator mapit=relations.begin(); mapit != relations.end(); mapit++){
			*out << mapit->second.getName() << endl;
			SScheme scheme = mapit->second.getScheme();
			set<Tuple> tuples = mapit->second.getTruths();


			for (set<Tuple>::iterator setit = tuples.begin(); setit != tuples.end(); setit++) {
				*out << "  ";
				Tuple tuple = *setit;
				for (int i = 0; i < scheme.size(); i++) {
					*out << scheme[i] << '=' << tuple[i] << ' ';
				}
				*out << endl;
			}
			*out << endl;
		}
	};

	void evaluateQueries(){
		for (int i = 0; i < queries.size(); i++) {
			ss->str("");

			//build results relation filled with tuples that match the querie's name
			Relation results = relations.at(queries[i].getIDLiteral());

			//builds the scheme for the query
			vector<Parameter> parameters = queries[i].getParamList();
			SScheme scheme;
			for (Parameter param : parameters) {
				scheme.push_back(param.getLiteral());
			}
			*out << queries.at(i).toString() << "? ";

			select(results, scheme);
			//*ss << "select" << endl << results.toString();

			project(results, scheme);
			//*ss << "project" << endl << results.toString();

			rename(results, scheme);
			//*ss << "rename" << endl << results.toString();

			if (results.getTruths().size() > 0) {
				*out << "Yes(" << results.getTruths().size() << ')' << endl;

				//*out << ss->str() << endl;
				*out << results.toString();

			} else {
				*out << "No" << endl << endl;
			}
			ss->clear();
		}
	};

	void select(Relation &relation, SScheme &query){
		set<Tuple> tuples = relation.getTruths();
		set<Tuple> selection;
		for (Tuple tuple : tuples) {
			bool viable = true;
			map<string, string> usedVariables;
			for (int i = 0; i < query.size(); i++) {
				if (query.at(i).at(0) == '\'' && query.at(i) != tuple.at(i)) {

					viable = false;
					break;
				} else if (query.at(i).at(0) != '\'') {
					string var = "";
					try {
						//find if var was used before
						var = usedVariables.at(query.at(i));
					} catch (out_of_range &e) {
						//if not found in map, put it in
						usedVariables.emplace(query.at(i), tuple.at(i));
						var = tuple.at(i);
					}
					if (var != tuple.at(i)) {
						viable = false;
						break;
					}
				}
			}

			if (viable) {
				selection.insert(tuple);
			}
		}
		relation.setTruths(selection);
		//cout << relation.toString() << endl;
	};

	void project(Relation &relation, SScheme &query){
		SScheme scheme = relation.getScheme();
		set<Tuple> tuples = relation.getTruths();
		set<Tuple> newTuples;

		for (Tuple tuple : tuples) {
			set<string> usedVars;
			Tuple newTuple;
			for (int i = 0; i < query.size(); i++) {
				if (query.at(i).at(0) != '\''
						&& usedVars.find(query.at(i)) == usedVars.end()) {
					usedVars.insert(query.at(i));
					newTuple.push_back(tuple.at(i));
				}
			}
			newTuples.insert(newTuple);
		}
		for (int i = 0; i < query.size(); i++) {
			set<string> usedVars;
			if (query.at(i).at(0) == '\''
					&& usedVars.find(query.at(i)) == usedVars.end()) {
				usedVars.insert(query.at(i));
				query.erase(query.begin() + i);
				scheme.erase(scheme.begin() + i);
				i--;
			}
		}
		relation.setScheme(scheme);
		relation.setTruths(newTuples);
		//cout << relation.toString();
	};

	void rename(Relation &relation, SScheme &query){
		SScheme scheme = relation.getScheme();

		for (int i = 0; i < query.size(); i++) {
			if (query[i] != scheme[i]) {
				scheme[i] = query[i];
			}
		}
		relation.setScheme(scheme);
		//cout << relation.toString();
	};

};

#endif /* DATABASE_H_ */
