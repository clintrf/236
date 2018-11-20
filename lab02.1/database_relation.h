#ifndef DATABASE_RELATION_H_
#define DATABASE_RELATION_H_

#include <iostream>
#include <set>
#include <string>
#include <list>
#include <sstream>
#include <map>

#include "database_tuple.h"
#include "database_sscheme.h"

using namespace std;

class Relation {
public:
	string name;
	SScheme scheme;
	set<Tuple> truths;

	Relation(string name, SScheme scheme) {
		this->name = name;
		this->scheme = scheme;
	}
	Relation() {this->name = "";};
	~Relation(){};

	void setName(string name){this->name = name;};
	void setScheme(SScheme scheme){this->scheme = scheme;};
	void setTruths(set<Tuple> truths){this->truths = truths;};

	string getName() {return name;};
	SScheme getScheme() {return scheme;};
	set<Tuple> getTruths() {return truths;};
	int getSize() {return truths.size();};


	void addTuple(Tuple truth) {truths.insert(truth);};

	Relation select(int position, string value){
		Relation temp(name, scheme);

		for (const Tuple& t : truths) {
			if (value == t[position]) {
				temp.addTuple(t);
			}
		}
		return temp;
	};
	Relation select(vector<list<int>>& locations){
			Relation r(name, scheme);
			for (const Tuple& t : truths) {
				bool add = true;
				if (locations.empty()) {
					r.addTuple(t);
				}
				else{
					int i = 0;
					for (const list<int>& l : locations) {
						list<int> temp = l;
						while (!temp.empty()) {
							int first = temp.front();
							temp.pop_front();
							if (t[first] != t[i]) {
								add = false;
								break;
							}
						}
						i++;
					}
					if (add) {
						r.addTuple(t);
					}
				}
			}
			return r;
	};

	Relation project(std::vector<int>& locations){
			if (locations.size() == 0){return  Relation();};
			SScheme header;
			SScheme temp;
			for (int i : locations) {
				temp.push_back(scheme[i]);
			}
			header = temp;
			Relation r(this->name, header);

			for (const Tuple& t : truths) {
				Tuple projected;
				for (int i : locations) {
					projected.push_back(t[i]);
				}
				r.addTuple(projected);
			}
			return r;
	};

	Relation rename(string s,int position){
			Relation r;
			SScheme temp = this->scheme;
			temp[position] = s;
			r.setName(name);
			r.setScheme(temp);
			r.setTruths(truths);
			return r;
	};

	string toString(){
		stringstream ss;
		if (getName() == "") {
			return ss.str();
		}

		for (Tuple t : truths) {
			if (t.size() > 0)
				ss << "  ";
			for (unsigned int i = 0; i < t.size(); i++) {
				ss << scheme[i] << "=" << t[i];
				if (i < t.size() - 1)
					ss << " ";
			}
			if (t.size() > 0)
				ss << endl;
		}
		return ss.str();
	};

};

#endif /* RELATION_H_ */
