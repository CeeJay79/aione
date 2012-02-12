#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>

enum NodeType
{
    GENERIC,
    SOCIAL_NODE,
    MECHANICAL_NODE,
    ELECTRICAL_NODE
};

class Node
{
public:
    Node();
    Node(int id_);

    int  getNodeID();
    void setNodeID(int);
    void setNodeType(NodeType);

    double getCurrentCost();
    double getHeuristicValue();
    void   setParent(Node*);
    void   setCurrentCost(double);
    void   setHeuristicValue(double);

    virtual std::string toXML() = 0;

    // change this shit
    Node* parentNode;
    int   nodeID;

protected:




    double realCostToGetHere;
    double heuristicValue;

    NodeType type;
};

#endif // NODE_HPP
