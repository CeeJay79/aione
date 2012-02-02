#ifndef FEEDER_HPP
#define FEEDER_HPP

<<<<<<< HEAD
=======
#include <vector>
#include "node.hpp"
#include "edge.hpp"
>>>>>>> bd65862923163045acaf26ea2452138fc84c9c9f

class Feeder
{
public:
    Feeder();

<<<<<<< HEAD

=======
    virtual Node* getNode(int) = 0;
    virtual void  getSuccessors(Node*,std::vector <Edge*>&) = 0;
>>>>>>> bd65862923163045acaf26ea2452138fc84c9c9f

private:
};

#endif // FEEDER_HPP
