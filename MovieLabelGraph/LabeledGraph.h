#ifndef LABELED_GRAPH_H
#define LABELED_GRAPH_H

#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "StringLib.cpp"

class LabeledGraph {
public:

    // CONSTRUCTOR
    LabeledGraph(string filename)  {
      nedges = 0;

      ifstream ifs(filename);
      stringstream bf;
      bf<<ifs.rdbuf();
      this->movietext= bf.str();

      StringLib stLib;

      vector<string>moviesAndActors = stLib.strSplit('\n',this->movietext);
      vector<string>allVertices = stLib.strSplit('/',this->movietext);
      
      //for(auto v:allVertices) add_vertex(v);

      vector<string> tmp;
      for(auto m:moviesAndActors){
       tmp = stLib.strSplit('/',m);
      this->movielist.push_back(tmp[0]); // in case a list of all the movies is needed
        for(int i = 1; i<tmp.size(); i++){
          add_edge(tmp[0], tmp[i]);
        }
        tmp.clear();
      }

      //  for(auto m: this->movielist){
      //    print_edges(m);
      //   }
    }

    // MODIFICATION MEMBER FUNCTIONS
    //adds a vertex with a specifc label
    void add_vertex(std::string vlabel);

    //adds an edge from vertex with source label to vertex with target label
    void add_edge(std::string source, std::string target);

    void print_edges(std::string source);
    // CONSTANT MEMBER FUNCTIONS
    int V( ) const { return vertices.size(); } //number of vertices
    int E( ) const { return nedges; }       //number of edges
    bool contains(std::string vlabel) const;     //does graph contain vertex with label vlabel?
    std::set<int> neighbors(int v) const;  //returns the vertices adjacent to vertex v
    std::string label(int v) const;     //returns the label of vertex v
    int index(std::string vlabel);           //returns the index of the vertex with label vlabel

    // OVERLOADED OUTPUT OPERATOR
    friend std::ostream& operator<< (std::ostream &out, LabeledGraph &g);

private:
  int nedges;
  std::vector<std::set<int> > vertices;
  std::vector<std::string> labels;
  std::map<std::string, int> indexedLabels;
  std::string movietext;
  std::vector<string> movielist;
};

#endif
