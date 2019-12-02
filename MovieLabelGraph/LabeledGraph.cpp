#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "LabeledGraph.h"

using namespace std;


void LabeledGraph::print_edges(std::string source){
  int idx = index(source);
  std::set<int> _edges = neighbors(idx);
  cout<<source <<":\n";

  std::set<int>::iterator it;

  for(it = _edges.begin(); it != _edges.end(); it++){
    cout<<"\t"<<label(*(it))<<std::endl;
  }
}

void LabeledGraph::add_vertex(string vlabel){
  labels.push_back(vlabel);
  indexedLabels.insert(pair<string, int>(vlabel, V()));
  set<int> s;
  vertices.push_back(s);
}

void LabeledGraph::add_edge(string source, string target){
    if (!contains(source))
      add_vertex(source);
    if (!contains(target))
      add_vertex(target);
    vertices[indexedLabels[source]].insert(indexedLabels[target]);
    vertices[indexedLabels[target]].insert(indexedLabels[source]);
    nedges++;
}

bool LabeledGraph::contains(string vlabel) const {
  return indexedLabels.find(vlabel) != indexedLabels.end();
}

set<int> LabeledGraph::neighbors(int v) const{
    return vertices[v];
}

string LabeledGraph::label(int v) const {
    return labels[v];
}

int LabeledGraph::index(string vlabel) {
    if(contains(vlabel)){
    return indexedLabels[vlabel];
    }
    return -1;
}

ostream& operator<< (ostream &out, LabeledGraph &g) {
  set<int>::iterator it;
  std::cout<<"=============================================\n";
  std::cout<<"Graph Summary: "
          <<g.V() <<" vertices, "
          <<g.E() <<" edges.\n";
  std::cout<<"=============================================\n";



  for(int i = 0; i< g.V(); i++){
    string currentLabel = g.label(i);
    cout<<currentLabel <<":\n";

    int idx = g.index(currentLabel);
    set<int>currentNeighbors;
    if(idx >-1) currentNeighbors = g.neighbors(idx);
    for(it = currentNeighbors.begin(); it != currentNeighbors.end(); it++){
      cout<<"\t"<<g.label(*(it))<<endl;
    }

  }

  
  return out;
}
