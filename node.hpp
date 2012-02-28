#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>

class Edge;

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

    void addSuccessor(Edge *);
    std::vector<Edge*>* getSuccessors();

    double getCurrentCost();
    double getHeuristicValue();
    void   setParent(Node*);
    void   setCurrentCost(double);
    void   setHeuristicValue(double);

    bool isExplored();
    void setExplored(bool a);

    virtual std::string toXML() = 0;

    // change this shit
    Node* parentNode;
    int   nodeID;

protected:

    double realCostToGetHere;
    double heuristicValue;
    bool explored;

    std::vector<Edge*> successors;// This is to be used with Offline nodes or to store succesors of online nodes

    NodeType type;
};

#endif // NODE_HPP
