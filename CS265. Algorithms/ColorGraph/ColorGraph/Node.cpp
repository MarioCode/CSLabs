//
//  Node.cpp
//  ColorGraph
//

#include "Node.h"

// Default constructor
Node::Node()
{
  //Nothing to do.
  m_color = nullptr;
  m_label = nullptr;
}

// Constructor with parameter
Node::Node(std::string label)
{
  m_label = label;
  m_color = "empty";
}

// Destructor
Node::~Node()
{
  //Nothing to do.
}


///////////////////////////////////////////
///////////////////////////////////////////


// Setting of neighbors
void Node::setAdjNodes(std::list<Node> &adjNodes) {
  
  // Get a list of neighbors
  // And set the colors
  for (std::list<Node>::iterator itr = adjNodes.begin(); itr != adjNodes.end(); itr++) {
    m_adjNodes.push_back(itr->m_label);
  }
}


// Setting the color node
void Node::setColor()
{
  //Initializ a list of available colors
  std::list<std::string> colors;
  colors.push_back("blue");
  colors.push_back("red");
  colors.push_back("orange");
  colors.push_back("green");
  
  //iterate through all the adjacent nodes
  for (std::list<Node>::iterator itr = m_adjNodes.begin(); itr != m_adjNodes.end(); itr++)
  {
    // if one of the  adjacent nodes has colors
    if (itr->m_color != "empty")
    {
      //remove the color from the list of avaliable colors.
      colors.remove(itr->m_color);
    }
  }
  //set the color with the first avaliable color.
  m_color = *colors.begin();
}
