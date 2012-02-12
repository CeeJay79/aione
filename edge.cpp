#include "edge.hpp"

Edge::Edge()
{

}

Edge::Edge(Node *source_, Node*target_){
    source = source_;
    target = target_;
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
