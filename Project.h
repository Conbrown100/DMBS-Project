#ifndef PROJECT_H
#define PROJECT_H

#include <vector>
#include <fstream>
using namespace std;
#include "Record.h"
#include "Operator.h"
#include "FileReader.h"

class Project : public Operator {
  public:

    FileReader readFile; 
    Operator* input;
    vector<string> field_names;

    // Project constructors
    Project(string fileName, vector<string> fieldNames) {
      readFile = FileReader(fileName);
      input = &readFile;
      field_names = fieldNames;

      //call over to FileReader with filename??
      // Implement this
    }
    Project(Operator *op, vector<string> fieldNames) {
      
      input = op;
    }



    void open() {
      input->open();
      // Implement this
    }

    vector<Record> next() {
      vector<Record> outPage;
      outPage = input->next();
      for(int i = 0; i < outPage.size(); i++){
        outPage[i].keepAttrNames(field_names);
      }

      return outPage;
    }

    void close() {
      input->close();
    }
};

#endif
