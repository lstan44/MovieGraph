#include <iostream>
#include "LabeledGraph.h"

int main() {
  using namespace std;
  LabeledGraph slalanneLabelGraph;

 slalanneLabelGraph.add_vertex("Chris Pratt");
 slalanneLabelGraph.add_vertex("Zoe Saldana");
 slalanneLabelGraph.add_vertex("Sam Worthington");
 slalanneLabelGraph.add_vertex("Michelle Rodriguez");
 slalanneLabelGraph.add_vertex("Avatar");
 slalanneLabelGraph.add_vertex("Guardian of the Galaxy");
 slalanneLabelGraph.add_vertex("Vin Diesel");
 slalanneLabelGraph.add_vertex("The fate of the Furious");

 slalanneLabelGraph.add_edge("Chris Pratt","Guardian of the Galaxy");
 slalanneLabelGraph.add_edge("Zoe Saldana","Guardian of the Galaxy");
 slalanneLabelGraph.add_edge("Zoe Saldana","Avatar");
 slalanneLabelGraph.add_edge("Sam Worthington","Avatar");
 slalanneLabelGraph.add_edge("Michelle Rodriguez","Avatar");
 slalanneLabelGraph.add_edge("Michelle Rodriguez","The fate of the Furious");
 slalanneLabelGraph.add_edge("Vin Diesel","Guardian of the Galaxy");
 slalanneLabelGraph.add_edge("Vin Diesel","The fate of the Furious");


cout<<slalanneLabelGraph;
 
}