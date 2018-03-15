//
//  main.cpp
//  ColorGraph
//

#include <iostream>
#include "Node.h"
#include <vector>

int main()
{
  //Create a list of nodes.
  std::list<Node> nodes;
  std::list<Node> adjNodes;

  Node a("a"), b("b"), c("c"), d("d"), e("e"), f("f");
  
  //Add adjacent nodes to all my nodes.
  a.setAdjNodes(adjNodes = {b, c, e});
  b.setAdjNodes(adjNodes = {a, c, d});
  d.setAdjNodes(adjNodes = {b, c, f});
  f.setAdjNodes(adjNodes = {d, c, e});
  e.setAdjNodes(adjNodes = {a, c, f});
  c.setAdjNodes(adjNodes = {a, b, d, e, f});
  
  nodes = {a, b, c, d, e, f};
  
  // Iterate through all the nodes and set the appropriate color
  for (std::list<Node>::iterator itr = nodes.begin(); itr != nodes.end(); itr++)
  {
    // Set the color
    itr->setColor();
    
    // I go through the list again from the nodes and look at the neighbors.
    for (auto itr_2 = nodes.begin(); itr_2 != nodes.end(); itr_2++) {
      
      // And these neighbors I set my own color.
      for (auto itr_3 = itr_2->m_adjNodes.begin(); itr_3 != itr_2->m_adjNodes.end(); itr_3++) {
        if (itr_3->m_label == itr->m_label) {
          itr_3->m_color = itr->m_color;
        }
      }
      
    }
    
    //print out all the node colors
    std::cout << itr->m_label << ": " << itr->m_color << "\n";
  }

  return 0;
}
