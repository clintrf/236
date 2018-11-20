//Create a relation object that includes methods implementing...
//select, project, and rename operations.
#ifndef DATABASE_RELATION_H
#define DATABASE_RELATION_H

#include <iostream>
#include <set>
#include <string>
#include <list>
#include <sstream>
#include <map>
#include "database_tuple.h"
#include "database_scheme.h"

using namespace std;

class Relation {
    public:
        Relation(string name, HScheme header){
            this->name = name;
            this->header = header;
            this->matched = false;
        };
        Relation(){this->name = "";};
        ~Relation(){};
        
        void setName(string name){this->name = name;};
        string getName(){return name;};
        
        //void setHeader(vector<string>& head){this->header = head;};
        void setScheme(HScheme header){this->header = header;};
        HScheme getScheme(){return header;};
        
        void setTruths(set<Tuple> truths){this->truths = truths;};
        set<Tuple> getTruths(){return truths;};
        
        bool operator<(Relation& other){return name < other.getName();};
    	void setMatched(bool match){this->matched = match;};
    	bool match(){return matched;};
    	
    	vector<int> findMatches(vector<string> sch){
    	    vector<int> results;
        	vector<string> curr = this->header;
        	for (unsigned int i = 0;i < sch.size();++i) {
        		for (unsigned int j = 0;j < curr.size();++j) {
        			if (sch[i] == curr[j]) {
        				results.push_back(j);
        				break;
        			}
        		}
        	}
        	return results;
    	};
    	
    	Relation select(int position, string value){
        	Relation temp(name, header);
        
        	for (const Tuple& t : truths) {
        		if (value == t[position]) {
        			temp.addTuple(t);
        		}
        	}
        	return temp;
    	};
    	Relation select(vector<list<int>>& locations){
        	Relation r(name, header);
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
        	if (locations.size() == 0) return  Relation();
        	HScheme h;
        	//vector<string> temp;
        	HScheme temp;
        	for (int i : locations) {
        		temp.push_back(header[i]);
        	}
        	h = temp;
        	Relation r(name, h);
        
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
        	HScheme temp = header;
        	temp[position] = s;
        	r.setName(name);
        	r.setScheme(temp);
        	r.setTruths(truths);
        	return r;
    	};
        
        
        
        
        int size(){return truths.size();};
        void addTuple(Tuple truth){truths.insert(truth);};
        
        
        string name;
        HScheme header;
        set<Tuple> truths;
        bool matched;
        

        string toString() {
        	stringstream ss;
        	if (getName() == "") {
        		return ss.str();
        	}
        
        	for (const Tuple& t : truths) {
        		ss<<" ";
        		for (unsigned int i = 0;i < t.size();i++) {
        			HScheme header = getScheme();
        			ss << " " << header[i] << "=" << t[i];
        			if (i == t.size() - 1) {
        				ss << endl;
        			}
        		}
        	}
        	return ss.str();
        };
};

#endif
