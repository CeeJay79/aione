#include "edge.hpp"

Edge::Edge()
{

}

Edge::Edge(Node *source_, Node*target_){
    source = source_;
    target = target_;
    explored = 0;
}

Node *Edge::getSource(){
    return source;
}

Node* Edge::getTarget(){
    return target;
}

double Edge::getCost()
{
    return cost;
}

void Edge::setCost(double cost_)
{
    cost = cost_;
}
