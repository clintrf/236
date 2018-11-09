#ifndef DATABASE_TUPLE_H
#define DATABASE_TUPLE_H

#include <iostream>
#include <set>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Tuple: public vector<string> {
    public:
        string const toString(){
            stringstream ss;
            for (unsigned int i = 0; i<this->size(); i++){
                ss << this->at(i) << ' ';
            }
            ss << endl;
            return ss.str();
        };
};

#endif 