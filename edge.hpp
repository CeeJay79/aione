#ifndef EDGE_HPP
#define EDGE_HPP

#include "node.hpp"

class Edge
{
public:
    Edge();
    Edge(Node* source_, Node* target_);

    Node*  getSource();
    Node*  getTarget();
    double getCost();

private:
    double cost;
    Node *source;
    Node *target;

};

#endif // EDGE_HPP
