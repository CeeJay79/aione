#include "xmlwriter.hpp"

#include <iostream>
#include <fstream>
#include <map>
#include "socialnode.hpp"
#include "edge.hpp"
#include <vector>

using namespace rapidxml;
using namespace std;


XmlWriter::XmlWriter(const std::string& filename_)
{
    filename_.copy(filename);
}

XmlWriter::write(OfflineSocialFeeder* graph_){

    /* xml declaration */
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(decl);

    // root graphml node
    xml_node<>* graphml = doc.allocate_node(node_element, "graphml");
    graphml->append_attribute(doc.allocate_attribute("xlmns", "http://graphml.graphdrawing.org/xmlns"));
    graphml->append_attribute(doc.allocate_attribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance"));
    graphml->append_attribute(doc.allocate_attribute("xsi:schemaLocation", "http://graphml.graphdrawing.org/xmlns http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd"));

    doc.append_node(graphml);

    // Graph node
    xml_node<>* graph = doc.allocate_node(node_element, "graph");
    graph->append_attribute(doc.allocate_attribute("id","SocialGraph"));
    graph->append_attribute(doc.allocate_attribute("edgedefault","undirected"));
    graphml->append_node(graph);

    /* Looping over nodes and edges */
    std::map<int,SocialNode*>* mapping;
    std::map<int,SocialNode*>::iterator it;

    for(it = mapping->begin(); it != mapping->end(); it++) {

        SocialNode *node = *(it);
        vector<Edge *>* friends = node->getFriends();
        /* Looping over edges for a particular node */
        int len = friends->size();

        for(int i = 0; i<len; i++){

            xml__
            graph->append_node(doc.allocate_node());

        }
    }


    /* Writing the file */
    writeFile(str);

}

XmlWrite::writeFile(const string& str){

    ofstream myfile;
    myfile.open(filename);
    myfile << str;
    myfile.close();

}

