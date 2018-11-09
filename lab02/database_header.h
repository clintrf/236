#ifndef DATABASE_HEADER_H
#define DATABASE_HEADER_H

#include <vector>
#include <string>

using namespace std;

class Header: public vector<string> {
    public:
        Header(){};
        ~Header(){};
};

#endif