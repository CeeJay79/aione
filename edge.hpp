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
    int  getEdgeID();
    void setEdgeID(int);
    double getCost();
    void setCost(double cost_);
    bool explored;

private:
    int edgeID;
    double cost;
    Node *source;
    Node *target;
};

#endif // EDGE_HPP
