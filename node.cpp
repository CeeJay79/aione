#include "node.hpp"

Node::Node()
{
}

Node::Node(int inNodeID)
{
    nodeID = inNodeID;
}

int Node::getNodeID()
{
    return nodeID;
}

void Node::setNodeID(int inID)
{
    nodeID = inID;
}

void Node::setNodeType(NodeType inType)
{
    type = inType;
}
