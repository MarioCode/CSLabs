//
//  Node.h
//  Pathfinding
//

#ifndef Node_h
#define Node_h

#include <string>
#include <list>
#include <iostream>

class Node
{
public:
    Node();
    Node(std::string label);
    void addAdjNodes(int count, ...);
    
    //Data members
    std::string m_strlabel;
    std::list <Node*> m_adjNodes;
    bool m_bIsVisited;
};

#endif /* Node_h */
