#ifndef OFFLINEFEEDER_HPP
#define OFFLINEFEEDER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include "feeder.hpp"
#include "node.hpp"
#include "edge.hpp"
#include "xmlreader.hpp"
//#include "xmlwriter.hpp"

template<class NodeType>
class OfflineFeeder : public Feeder
{
public:
    OfflineFeeder();

    OfflineFeeder(std::map<int,NodeType*>* mapping_){

        mapping = mapping_;

    }

    OfflineFeeder(const std::string& filename)
    {

        /* XML import */
        XmlReader xmlreader(filename);
    //    mapping = xmlreader.parseSocialGraph();
        mapping = xmlreader.parseGraph<NodeType>();
        std::cout << "OfflineFeed built from XML File : " << filename  << std::endl;

    }

    void exportToXml(const std::string& filename)
    {
        std::cout << "Writing xml " << std::endl;


//        XmlWriter writer(filename);
//        writer.write(this);

    }

    std::map<int,NodeType*>* getMapping()
    {
        return mapping;
    }

    Node* getNode(int inNodeID)
    {

        return mapping->at(inNodeID);

    }

    void getSuccessors(Node* inCurrentNode,std::vector<Edge *>* inEdgeSuccessors)
    {
        *inEdgeSuccessors = *(((NodeType*)inCurrentNode)->getSuccessors());
    }

private:
    std::map<int,NodeType*>* mapping;

};





#endif // OFFLINEFEEDER_HPP
