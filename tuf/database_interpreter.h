#ifndef DATABASE_INTERPRETER_H
#define DATABASE_INTERPRETER_H

using namespace std;

#include <string>
#include <map>
#include <vector>
#include <sstream>

//#include "database_relation.h"
#include "database_database.h"
#include "database_datalogProgram.h"

class Interpreter { 
    public:
        Interpreter(Parser* parsed){
            
            //DatalogProgram dlp(parsed);
            //Database database = Database(dlp);
            
            scheme = parsed.getSchemes();
            fact = parsed.getFacts();
            query = parsed.getQueries()
        };
        ~Interpreter(){};
        
        Database buildDatabase(){ return Database(scheme,fact);};
        vector<Scheme*> getSchemes(){return scheme;};
        vector<Fact*> getFacts(){return fact;}
        vector<Query*> getQueries(){return query;};
        
        vector<Scheme*> scheme;
        vector<Fact*> fact;
        vector<Query*> query;
        
	    Database db;
	    
        // string printRelations(){ 
        //     stringstream ss;
        //     ss << "Relations: " << endl;

        //     for (Database::iterator it=db.begin(); it!=db.end(); ++it){
        //         ss << it->first << " => " << endl;
        //         ss << it->second.toString();
        //     }
        //     return ss.str();
        // };
};
#endif