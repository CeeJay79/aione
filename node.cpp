#include "node.hpp"

Node::Node()
{
    parentNode = NULL;
    realCostToGetHere = 0;
}

Node::Node(int inNodeID)
{
    nodeID = inNodeID;
    parentNode = NULL;
    realCostToGetHere = 0;
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

double Node::getCurrentCost()
{
    return realCostToGetHere;
}

void Node::setCurrentCost(double inCost)
{
    realCostToGetHere = inCost;
}

void Node::setHeuristicValue(double inHeuristicValue)
{
    heuristicValue = inHeuristicValue;
}

double Node::getHeuristicValue()
{
    return heuristicValue;
}

void Node::setParent(Node* inParentNode)
{
    parentNode = inParentNode;
}
