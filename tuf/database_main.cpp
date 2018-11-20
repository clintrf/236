#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "lexer_lexer.h"
#include "parser_parser.h"
#include "database_interpreter.h"


using namespace std;

int main(int argc, char* argv[]){
    ifstream input;
    string fileName = argv[1];
    
    ofstream output;
    string newFileName = "in.out." + fileName;
    output.open(newFileName);
    
    if(argc > 0){
        input.open (argv[1]);
        if(!input.good()){
            cout << "Error opening file " << endl;
            return 0;
        }

        Lexer lex = Lexer(&input);
        Parser parsed = Parser(&lex);
        Interpreter interp = Interpreter(&parsed);
        
        Database db = interp.buildDatabase();
        vector<Query> queries = interp.getQueries();
        Relation results = db.eval(queries);
        
        for (int i = 0, max = static_cast<int>(results.size()); i < max; i++) {
            if (i != 0){output << endl;};
            
            output << queries[i].str() << " ";
            
            if (results[i].size() == 0){output << "No";};
            else {output << "Yes(" << size << ")";};
            
            if (!results[i].vacant() && !results[i].empty()) {
                output << endl << results[i].str();
            }
        }
        parsed.clearMemory();
    }
    return 0;
}
