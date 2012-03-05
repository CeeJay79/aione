#include "mechanicalnode.hpp"

MechanicalNode::MechanicalNode(int id_):
    Node(id_)
{
}

void MechanicalNode::setPos(double x, double y, double z){

    pos[0] = x;
    pos[1] = y;
    pos[2] = z;

}
