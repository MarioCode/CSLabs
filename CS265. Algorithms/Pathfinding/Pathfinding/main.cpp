//
//  main.cpp
//  Pathfinding
//

#include <iostream>
#include <stack>

#include "Node.h"

int main(int argc, const char * argv[]) {
    
    //Create Nodes
    
    Node* a = new Node("a");
    Node* b = new Node("b");
    Node* c = new Node("c");
    Node* d = new Node("d");
    Node* e = new Node("e");
    Node* f = new Node("f");
    Node* g = new Node("g");
    Node* h = new Node("h");
    
    //Add adj Nodes
    a->addAdjNodes(2, b, f);
    b->addAdjNodes(3, a, c, d);
    d->addAdjNodes(2, e, g);
    f->addAdjNodes(2, a, h);
    
    std::string findingNode = "g";
    std::stack<Node*> route;
    
    //Start with a
    a->m_bIsVisited = true;
    route.push(a);
    
    std::cout << "Path: ";
    
    while (1)
    {
        //Get the parent
        Node* parent = route.top();
        
        //Get first non-visited child
        std::list<Node*>::iterator itr;
        for (itr = parent->m_adjNodes.begin(); itr != parent->m_adjNodes.end(); itr++)
        {
            if (!(*itr)->m_bIsVisited)
            {
                //Mark it as visited
                (*itr)->m_bIsVisited = true;
                
                //Throw it on the stack
                route.push(*itr);
                
                //Continue
                break;
            }
        }
        
        // If the top of the stack
        if (route.top()->m_strlabel == findingNode)
        {
            // If it is our end point
            // print the route in the stack
            while (!route.empty())
            {
                std::cout << route.top()->m_strlabel << " -> ";
                route.pop();
            }
            
            // break
            // We are done
            break;
        }
        // Oterwise take it off the stack
        bool hasUnvisited = false;
        
        for (itr = route.top()->m_adjNodes.begin(); itr != route.top()->m_adjNodes.end(); itr++)
        {
            if (!(Node*)(*itr)->m_bIsVisited)
            {
                hasUnvisited = true;
            }
        }
        
        if (!hasUnvisited)
        {
            route.pop();
            if (route.empty())
            {
                std::cout << "No route found\n";
            }
        }
    }
    std::cout << "End\n";
    
    return 0;
}
