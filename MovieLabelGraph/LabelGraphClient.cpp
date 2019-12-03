#include <iostream>
#include "LabeledGraph.h"

int main() {
  using namespace std;
  LabeledGraph slalanneLabelGraph("movies_short.txt");

//take input queries from users

bool play = true;

/*
while(play){

  cout<<"Enter the name of an actor or a movie:\n";
  cout<<"Enter STOP to stop the program.\n";

  std::string query = "";
  cin>> query;
  if (query == "STOP" || query == "stop") play = false;

  cout<<"Here are neighbors of "<<query<<":\n";
  slalanneLabelGraph.print_edges(query);

}

*/

slalanneLabelGraph.print_edges("Braid, Hilda");
 
}