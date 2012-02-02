#include "xmlwriter.hpp"

#include <iostream>
#include <fstream>
#include <map>
#include "socialnode.hpp"
#include "edge.hpp"
#include <vector>
#include <sstream>

using namespace rapidxml;
using namespace std;


XmlWriter::XmlWriter(const std::string& filename_)
{
    filename = filename_;
}

void XmlWriter::write(OfflineSocialFeeder* graph_){

    rapidxml::xml_document<> doc;

    /* xml declaration */
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(decl);

    // root graphml node
    xml_node<>* graphml = doc.allocate_node(node_element, "graphml");
    graphml->append_attribute(doc.allocate_attribute("xlmns", "http://graphml.graphdrawing.org/xmlns"));
    //graphml->append_attribute(doc.allocate_attribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance"));
    //graphml->append_attribute(doc.allocate_attribute("xsi:schemaLocation", "http://graphml.graphdrawing.org/xmlns http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd"));

    doc.append_node(graphml);

    // Graph node
    xml_node<>* graph = doc.allocate_node(node_element, "graph");
    graph->append_attribute(doc.allocate_attribute("id","SocialGraph"));
    graph->append_attribute(doc.allocate_attribute("edgedefault","undirected"));
    graphml->append_node(graph);

    /* Looping over nodes and edges */
    std::map<int,SocialNode*>* mapping = graph_->getMapping();
    std::map<int,SocialNode*>::iterator it;


    for(it = mapping->begin(); it != mapping->end(); it++) {

        SocialNode *node = it->second;
        stringstream ss2;
        ss2 << '"' << node->getNodeID() << '"';
        string s = ss2.str();
        xml_node<>* nnode = doc.allocate_node(node_element,"node");
        nnode->append_attribute(doc.allocate_attribute("id",s.c_str()));
        graph->append_node(nnode);

    }


    for(it = mapping->begin(); it != mapping->end(); it++) {

        SocialNode *node = it->second;
        stringstream ss2;
        ss2 << node->getNodeID();
        vector<Edge *>* friends = node->getFriends();
        /* Looping over edges for a particular node */
        int len = friends->size();

        for(int i = 0; i<len; i++){

            std::stringstream ss1;
            ss1 << (*friends)[i]->getTarget()->getNodeID();

            xml_node<>* ed = doc.allocate_node(node_element,"edge");
            ed->append_attribute(doc.allocate_attribute("source",ss2.str().c_str()));
            ed->append_attribute(doc.allocate_attribute("target",ss1.str().c_str()));
            graph->append_node(ed);

        }
    }

    std::string xml_as_string;

    // watch for name collisions here, print() is a very common function name!
    rapidxml::print(std::back_inserter(xml_as_string), doc);

    /* Writing the file */
    writeFile(xml_as_string);

}

void XmlWriter::writeFile(const string& str){

    ofstream myfile(filename.c_str());
    myfile << str;
    myfile.close();

}

