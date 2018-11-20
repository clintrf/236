#ifndef DATABASE_FACT_H
#define DATABASE_FACT_H

#include <vector>
#include <string>
#include <sstream>
#include "lexer_token.h"

using namespace std;

class Fact: public vector<string> {
    public:
        Fact(){};
        Fact(string factName) : name(move(factName)){};
        Fact(string factName, string value){this->name=factName;list.emplace_back(value);};
        Fact(string factName, vector<string> values) : name(move(fact_name)), list(move(values)) {};
        ~Fact(){};
        
        void add(string value){list.emplace_back(value);};
        void setName(string factName){this->name=factName;};
        void getName(){return this->name;};
        vector<string> getList(){return list;};
        
        string toString(){
            stringstream ss;
            for(unsigned int i = 0, max = list.size(); i < max; i++){
                ss << list[i];
                if(i != max) ss << ",";
            }
            ss << ").";
            return ss.str();
        };
        
        string name;
        vector<string> list;
        
};

#endif