#ifndef STRING_LIB_H
#define STRING_LIB_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class StringLib{

public:
StringLib(){
   
}

string getWord(vector<char> &letters){
string res = "";
    for(auto i:letters){
        res += i;
    }
    letters.clear();

    return res;
}

vector<string> strSplit(char delim,string f){
  this->text = f;
  vector<string>words;
  vector<char>letters;
  for(int i=0; i<this->text.length(); i++){
    if(this->text[i] != delim){
      letters.push_back(this->text[i]);
    }
    if(this->text[i] == delim || this->text[i+1] == '\0'){
      words.push_back(getWord(letters));
    }
  }

return words;
}

private:
string text;


};

#endif