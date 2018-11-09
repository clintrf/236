#ifndef DATABASE_DATABASE_H
#define DATABASE_DATABASE_H

#include <string>
#include <vector>
#include <set>

#include "database_relation.h"

using namespace std;

class Database : public map<string, Relation> {
public:
	Database(){};
	~Database(){};
	
};
#endif