#ifndef MECHANICALNODE_HPP
#define MECHANICALNODE_HPP

#include "node.hpp"

class MechanicalNode : public Node
{
public:
    MechanicalNode();

    double pos[3];
};

#endif // MECHANICALNODE_HPP
