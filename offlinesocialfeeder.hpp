#ifndef OFFLINESOCIALFEEDER_HPP
#define OFFLINESOCIALFEEDER_HPP

#include "offlinefeeder.hpp"
#include "edge.hpp"
#include "socialnode.hpp"
#include "xmlreader.hpp"
#include "map"
#include <string>

class OfflineSocialFeeder : public OfflineFeeder
{
public:
    OfflineSocialFeeder(const std::string& filename);

    void exportToXml(const std::string& filename);

    std::map<int,SocialNode*>* getMapping();

    Node* getNode(int);
    void  getSuccessors(Node *, std::vector<Edge *> *);

private:
    std::map<int,SocialNode*>* mapping;


};

#endif // OFFLINESOCIALFEEDER_HPP

