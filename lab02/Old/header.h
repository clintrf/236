//Create a relation object that includes methods implementing...
//select, project, and rename operations.
#ifndef DATABASE_HEADER_H
#define DATABASE_HEADER_H

#include <iostream>
using namespace std;

#include <string>
#include <map>
#include <vector>
#include <sstream>

#include "Relation.h"
//#include "Scheme.h"
//#include "Tuple.h"
#include "DataLog.h"
//#include "Predicate.h"

class Header {
    public:
    
        map<string, Relation> relations;
    	ostream* out;
    	vector<Predicate> queries;
    	stringstream* ss = new stringstream();
    public:
    	Database(DataLog dataLog, ostream* out);
    	~Database() {
    		delete ss;
    	}
    private:
    	void printRelations();
    	void evaluateQueries();
    	void select(Relation &relation, Scheme &query);
    	void project(Relation &relation, Scheme &query);
    	void rename(Relation &relation, Scheme &query);
        
    
    Header(){};
    ~Header(){};
    
    //header:vec<string>
    //  vec<string>
    
    
    //Row class NOT IN HEADER
    //vec<string>
}


