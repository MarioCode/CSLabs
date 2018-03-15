//
//  Node.h
//  ColorGraph
//

#ifndef Node_h
#define Node_h

#include <string>
#include <list>

class Node
{
public:
  // Init / Destructor
  Node();
  Node(std::string label);
  ~Node();
  
  //  Data Member
  std::string m_label;        // Node's name
  std::string m_color;        // Node's color
  std::list<Node> m_adjNodes; // Node's neighbors
  
  // Basic methods
  void setColor();                              // Setting the color node
  void setAdjNodes(std::list<Node> &adjNodes);  // Setting of neighbors
};

#endif /* Node_h */
