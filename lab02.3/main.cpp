#include <iostream>
//#include <string>
//#include <map>

#include "./Interpreter.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  std::string fileName = argv[1];
  
  ofstream output;
  string fileName1 = "in.out." +fileName;
  output.open(fileName1);
  if (argc < 1) {
    output << "Missing input file argument" << std::endl;
    return 0;
  }
  std::string inputFileName = std::string(fileName);
  Interpreter interpreter(inputFileName);

  auto db = interpreter.build();
//  output << "Database:" << std::endl << db.str();

  auto queries = interpreter.getQueries();
  auto results = db.eval(queries);
  for (int i = 0, max = static_cast<int>(results.size()); i < max; i++) {
    if (i != 0) output << std::endl;
    output << queries[i].str() << " ";
    int size = results[i].size();
    if (size == 0) {
      output << "No";
    } else {
      output << "Yes(" << size << ")";
    }
    if (!results[i].vacant() && !results[i].empty()) {
      output << std::endl << results[i].str();
    }
  }

  return 0;
}