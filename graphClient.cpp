#include <iostream>
#include "Graph.h"

using namespace std;


int main(){
    Graph slalanneGraph;
    
    //add 5 vertices (0,4)
    for(int i=0; i<5; i++){
        slalanneGraph.add_vertex();
    }

    slalanneGraph.add_edge(0,4);
    slalanneGraph.add_edge(0,2);
    slalanneGraph.add_edge(1,4);
    slalanneGraph.add_edge(2,3);
    slalanneGraph.add_edge(2,4);

    cout<<slalanneGraph;

    
    return 0;
}