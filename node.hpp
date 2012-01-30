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

    virtual std::string toXML() = 0;

protected:
    int nodeID;
    NodeType type;
};

#endif // NODE_HPP
