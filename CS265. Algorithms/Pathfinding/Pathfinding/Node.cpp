//
//  Node.cpp
//  Pathfinding
//

#include "Node.h"

Node::Node()
{
    m_bIsVisited = false;
}


Node::Node(std::string label)
{
    m_strlabel = label;
    m_bIsVisited = false;
}

void Node::addAdjNodes(int count, ...)
{
    va_list args;
    va_start(args, count);
    
    for (int i = 0; i < count; i++)
    {
        m_adjNodes.push_back(va_arg(args, Node*));
    }
    va_end(args);
}
