#ifndef FEEDER_HPP
#define FEEDER_HPP


#include <vector>
#include "node.hpp"
#include "edge.hpp"


class Feeder
{
public:
    Feeder();

    virtual Node* getNode(int) = 0;
    virtual void  getSuccessors(Node*,std::vector <Edge*>*) = 0;

private:
};

#endif // FEEDER_HPP
