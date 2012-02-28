#include "offlinesocialfeeder.hpp"
#include "xmlwriter.hpp"
#include "socialnode.hpp"

using namespace std;

OfflineSocialFeeder::OfflineSocialFeeder(std::map<int,SocialNode*>* mapping_){

    mapping = mapping_;

}

OfflineSocialFeeder::OfflineSocialFeeder(const string& filename)
{

    /* XML import */
    XmlReader xmlreader(filename);
//    mapping = xmlreader.parseSocialGraph();
    mapping = xmlreader.parseGraph<SocialNode>();
    cout << "OfflineSOcialFeeder built from XML File : " << filename  << endl;

}

void OfflineSocialFeeder::exportToXml(const std::string& filename)
{
    cout << "Writing xml " << endl;

    XmlWriter writer(filename);
    writer.write(this);

}

std::map<int,SocialNode*>* OfflineSocialFeeder::getMapping()
{
    return mapping;
}

Node* OfflineSocialFeeder::getNode(int inNodeID)
{

    Node* shit = mapping->at(inNodeID);
    return mapping->at(inNodeID);

}

void OfflineSocialFeeder::getSuccessors(Node* inCurrentNode,std::vector<Edge *>* inEdgeSuccessors)
{
    *inEdgeSuccessors = *(((SocialNode*)inCurrentNode)->getFriends());
}
