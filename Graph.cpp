#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Graph.h"
#include <cassert>

using namespace std;

void Graph::add_vertex(){
  set<int> s;
  edges.push_back(s);
}

void Graph::add_edge(int source, int target){
    assert (contains(source) && contains(target));
    edges[source].insert(target);
    edges[target].insert(source);
    nedges++;
}

set<int> Graph::neighbors(int v) const{
    assert (contains(v));
    return edges[v];
}

bool Graph::contains(int v) const{
  return v < V();
}

ostream& operator<< (ostream &out, const Graph &g) {
  
cout<<"==========================================="<<std::endl;
cout<<"Graph Summary: "<<g.V()
    <<" vertices, "
    <<g.E()
    <<" edges."<<std::endl;

cout<<"==========================================="<<std::endl;
std::set<int>::iterator it;
for(int i = 0; i< g.V(); i++){
  cout<<i <<" -->  ";
  std::set<int> n1 = g.neighbors(i);
  for(it = n1.begin(); it != n1.end(); it++){
  cout<<*(it)<<"\t";
}
cout<<std::endl;
}
  return out;
}
