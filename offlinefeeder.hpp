#ifndef OFFLINEFEEDER_HPP
#define OFFLINEFEEDER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include "feeder.hpp"
#include "node.hpp"
#include "edge.hpp"

class OfflineFeeder : public Feeder
{
public:
    OfflineFeeder();

    virtual Node* getNode(int) = 0;
    virtual void  getSuccessors(Node*,std::vector<Edge*>*) = 0;
};

#endif // OFFLINEFEEDER_HPP
