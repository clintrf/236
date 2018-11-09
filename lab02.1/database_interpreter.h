#ifndef DATABASE_INTERPRETER_H
#define DATABASE_INTERPRETER_H

using namespace std;

#include <string>
#include <map>
#include <vector>
#include <sstream>

#include "database_relation.h"
#include "database_database.h"
#include "database_datalogProgram.h"

class Interpreter { //this is like the interpreter
    public:
        Interpreter(int n);
        Interpreter(Database dataLog);
        ~Interpreter(){delete ss;};

        void createTestRelation(string name);
	    Database db;
    	ostream* out;
    	stringstream* ss = new stringstream();
    	
        // void printRelations(){ 
        //     cout << "Relations: " << endl;

        //     for (Database::iterator it=db.begin(); it!=db.end(); ++it){
        //         cout << it->first << " => " << endl;
        //         cout << it->second.toString();
        //     }
        // };
        string printRelations(){ 
            stringstream ss;
            ss << "Relations: " << endl;

            for (Database::iterator it=db.begin(); it!=db.end(); ++it){
                ss << it->first << " => " << endl;
                ss << it->second.toString();
            }
            return ss.str();
        };
};
#endif