#include <vector>
#include <map>
#include <string>
#include <ostream>
#include <fstream>
#include <iostream>

#include "database_interpreter.h"
#include "database_header.h"
#include "database_tuple.h"

using namespace std;

Interpreter::Interpreter(int n){
    string name = "Test";
    createTestRelation(name);

    switch (n){
        case 0:{ // Does select work
            printRelations();
            
            db.at(name) = db.at(name).select(0,"'1'");
            printRelations();
        }
        break;
        
        case 1:{ // select with a list of indexes work           
            printRelations();
            
            list<int> first (0);
            list<int> second (1);
            vector<list<int>> temp{first,second};
            db.at(name) = db.at(name).select(temp);
            printRelations();
        }
        break;
        
        case 2:{ // does project work
            printRelations();
            
            vector<int> temp{1,2};
            db.at(name) = db.at(name).project(temp);
            printRelations(); 
        }
        break;
        
        case 3:{ // does rename work
            printRelations();
            string s = "First";
            db.at(name) = db.at(name).rename(s,0);
            printRelations();    
        }
        break;
        
        case 4:{ //test('1','1','1')
            printRelations();
            
            db.at(name) = db.at(name).select(0,"'1'");
            db.at(name) = db.at(name).select(1,"'1'");
            db.at(name) = db.at(name).select(2,"'1'");
            printRelations();
        }
        break;
        
        case 5:{ //test('5', anynum, somenum)
            printRelations();
            
            db.at(name) = db.at(name).select(0,"'5'");
            vector<int> temp3{1,2};
            db.at(name) = db.at(name).project(temp3);
            string s4 = "anynum";
            string s5 = "somenum";
            db.at(name) = db.at(name).rename(s4,0);
            db.at(name) = db.at(name).rename(s5,1);
            
            
            printRelations();
            
        }
        break;
        
        case 6:{ //test(what, why, '3')
            printRelations();
            
            db.at(name) = db.at(name).select(2,"'3'");
            vector<int> temp3{0,1};
            db.at(name) = db.at(name).project(temp3);
            string s6 = "what";
            string s7 = "why";
            db.at(name) = db.at(name).rename(s6,0);
            db.at(name) = db.at(name).rename(s7,1);
            
            
            printRelations();
        }
        break;
        
        case 7:{ // test(X,X,X)
            printRelations();
            
            list<int> first (1);
            list<int> second (2);
            list<int> third (3);
            vector<list<int>> temp{first,second,third};
            db.at(name) = db.at(name).select(temp);
            string s1 = "X";
            db.at(name) = db.at(name).rename(s1,0);
            vector<int> temp1{0};
            db.at(name) = db.at(name).project(temp1);
            
            printRelations();
            
        }
        break;
        
        case 8:{ // test(X,Y,Z)
            printRelations();
            string ss0 = "X";
            string ss1 = "Y";
            string ss2 = "Z";
            db.at(name) = db.at(name).rename(ss0,0);
            db.at(name) = db.at(name).rename(ss1,1);
            db.at(name) = db.at(name).rename(ss2,2);
            printRelations();
        }
        break;
        
        case 9:{// test(X,'6',Y)
            printRelations();
            
            db.at(name) = db.at(name).select(1,"'6'");
            
            list<int> first1 (0);
            list<int> second1 (1);
            vector<list<int>> temp1{first1};
            db.at(name) = db.at(name).select(temp1);
            
            string string1 = "'X'";
            string string2 = "'Y'";
            
            db.at(name) = db.at(name).rename(string1, 0);
            db.at(name) = db.at(name).rename(string2, 2);
            
            vector<int> temp2{0,2};
            db.at(name) = db.at(name).project(temp2);
            
            
            printRelations();
        }
        break;
    }
};


Interpreter::Interpreter(Database dataLog) {};

void Interpreter::createTestRelation(string name){
    // Create a Relation for all test cases
    
    //string name = "Nums";
    
    Header header;
    header.push_back("F");
    header.push_back("S");
    header.push_back("T");

    db.emplace(name, Relation(name, header));
    
    
    Tuple tuple00;
	tuple00.push_back("'1'");
	tuple00.push_back("'2'");
	tuple00.push_back("'3'");
	
	Tuple tuple01;
	tuple01.push_back("'5'");
	tuple01.push_back("'6'");
	tuple01.push_back("'7'");
	
	Tuple tuple02;
	tuple02.push_back("'1'");
	tuple02.push_back("'6'");
	tuple02.push_back("'3'");
	
	Tuple tuple03;
	tuple03.push_back("'5'");
	tuple03.push_back("'2'");
	tuple03.push_back("'7'");
	
	Tuple tuple04;
	tuple04.push_back("'1'");
	tuple04.push_back("'1'");
	tuple04.push_back("'1'");
	
    Tuple tuple05;
	tuple05.push_back("'2'");
	tuple05.push_back("'2'");
	tuple05.push_back("'2'");
	
	Tuple tuple06;
	tuple06.push_back("'1'");
	tuple06.push_back("'1'");
	tuple06.push_back("'2'");
	

	db.at(name).addTuple(tuple00);
	db.at(name).addTuple(tuple01);
	db.at(name).addTuple(tuple02);
	db.at(name).addTuple(tuple03);
	db.at(name).addTuple(tuple04);
	db.at(name).addTuple(tuple05);
	db.at(name).addTuple(tuple06);
};