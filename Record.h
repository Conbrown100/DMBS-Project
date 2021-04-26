#ifndef RECORD_H
#define RECORD_H

#include <iostream>
using namespace std;

class Record {


public:
  vector<string> Names;
  vector<string> Types;
  vector<string> Values;

  Record(vector<string> attrNames, vector<string> attrType, vector<string> attrValue){
    Names = attrNames;
    Types = attrType;
    Values = attrValue;
  }
  friend ostream& operator<< (ostream& os, const Record& r) {

    for(int i = 0; i < r.Values.size(); i++)
      os << r.Values[i] << " ";

    return os;
  }

  void removeAttrNames(string name){
    for(int i = 0; i < Names.size(); i++){
      if(Names[1] == name){
        Names.erase(Names.begin()+1);
        Types.erase(Types.begin()+1);
        Values.erase(Values.begin()+1);
        break;
      }
    }
  }

  void keepAttrNames(vector<string> field_names){
    vector<string> toRemove;
    for(int i = 0; i < Names.size(); i++){
      if(contains(field_names, Names[i]) == false)
        toRemove.push_back(Names[i]);
    }
    for(int i = 0; i < toRemove.size(); i++)
      removeAttrNames(toRemove[i]);
  }

  bool contains(vector<string> attrs, string attr){
    for(int i = 0; i < attrs.size(); i++){
      if(attrs[i] == attr){
        return true;
      }
    }
    return false;
  }
};

#endif

