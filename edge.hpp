#ifndef EDGE_HPP
#define EDGE_HPP

#include "node.hpp"

class Edge
{
public:
    Edge();
    Edge(Node *source_, Node*target_);

    Node* getSource();
    Node* getTarget();

private:
    Node *source;
    Node *target;

};

#endif // EDGE_HPP
