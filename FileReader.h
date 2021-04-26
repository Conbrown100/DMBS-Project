#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
#include "Record.h"
#include "Operator.h"


//if getline fails then I can close()
//if getline == false break loop
//if getline == 0 then maybe 
//if getline <= 0 break

// This function takes in a string with items delimited by commas
// and returns a vector of those items.
// Example - input: "str1,str2,str3,str4"
//          output: {"str1", "str2", "str3", "str4"}
vector<string> split(string line) {
  vector<string> v;
  string s;
  istringstream is(line);
  while (getline(is, s, ',')){
    v.push_back(s);
  }
  return v;
}


class FileReader : public Operator {

  private:
    fstream dbFile;
    string fileName;
    vector<string> fieldNames;
    vector<string> attrNames;
    vector<string> attrType;
    vector<string> attrValues;

  public:


    FileReader(string file_Name){
      fileName = file_Name;
    }

    FileReader(){
    }



    void open() {
      dbFile.open(fileName);
      string line;
      getline(dbFile, line);
      //store whole first line of names into attrNames
      attrNames = split(line);

      getline(dbFile, line);
      //store whole second line of types into attrType
      attrType = split(line);

      //dumby data of ----------- read out now ready for real data
      getline(dbFile, line);
    }

    
    vector<Record> next() {

      int index = 0;

      vector<Record> outPage;
      string line;
      while(getline(dbFile, line)){
        if(line.empty())
          break;
        if(outPage.size() == pageSize)
          break;
        attrValues = split(line);
        //leaves off last bit of data not sure
        vector<string> attrValues = split(line);
        outPage.push_back(Record(attrNames, attrType, attrValues));
        index ++;
      }
      // Return an empty vector if no more pages exist
      return outPage;
    }

    void close() {
      dbFile.close();
      cout << " I am closed " << endl;
    }
};

#endif

