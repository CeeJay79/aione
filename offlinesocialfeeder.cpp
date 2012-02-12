#include "offlinesocialfeeder.hpp"
#include "xmlwriter.hpp"

using namespace std;

OfflineSocialFeeder::OfflineSocialFeeder(std::map<int,SocialNode*>* mapping_){

    mapping = mapping_;

}

OfflineSocialFeeder::OfflineSocialFeeder(const string& filename)
{

    /* XML import */
    XmlReader xmlreader(filename);
    mapping = xmlreader.parseSocialGraph();

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
    return mapping->at(inNodeID);
}

void OfflineSocialFeeder::getSuccessors(Node* inCurrentNode,std::vector<Edge *>& inEdgeSuccessors)
{
    inEdgeSuccessors = *(((SocialNode*)inCurrentNode)->getFriends());
}
