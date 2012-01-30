#include "edge.hpp"

Edge::Edge()
{

}

Edge::Edge(Node *source_, Node*target_){
    source = source_;
    target = target_;
}

Edge::Node* getSource(){
    return source;
}

Edge::Node* getTarget(){
    return target;
}
