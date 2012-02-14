#include "xmlwriter.hpp"

#include <iostream>
#include <fstream>
#include <map>
#include "socialnode.hpp"
#include "edge.hpp"
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

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

    // Keys for color blue
    xml_node<>* keyb = doc.allocate_node(node_element,"key");
    keyb->append_attribute(doc.allocate_attribute("attr.name","b"));
    keyb->append_attribute(doc.allocate_attribute("attr.type","int"));
    keyb->append_attribute(doc.allocate_attribute("for","node"));
    keyb->append_attribute(doc.allocate_attribute("id","b"));
    // Keys for color red
    xml_node<>* keyr = doc.allocate_node(node_element,"key");
    keyr->append_attribute(doc.allocate_attribute("attr.name","r"));
    keyr->append_attribute(doc.allocate_attribute("attr.type","int"));
    keyr->append_attribute(doc.allocate_attribute("for","node"));
    keyr->append_attribute(doc.allocate_attribute("id","r"));
    // Keys for color green
    xml_node<>* keyg = doc.allocate_node(node_element,"key");
    keyg->append_attribute(doc.allocate_attribute("attr.name","g"));
    keyg->append_attribute(doc.allocate_attribute("attr.type","int"));
    keyg->append_attribute(doc.allocate_attribute("for","node"));
    keyg->append_attribute(doc.allocate_attribute("id","g"));

    // Graph node
    xml_node<>* graph = doc.allocate_node(node_element, "graph");
    graph->append_attribute(doc.allocate_attribute("id","SocialGraph"));
    graph->append_attribute(doc.allocate_attribute("edgedefault","undirected"));
    graphml->append_node(graph);


    graph->append_node(keyb);
    graph->append_node(keyr);
    graph->append_node(keyg);

    /* Looping over nodes and edges */
    std::map<int,SocialNode*>* mapping = graph_->getMapping();
    std::map<int,SocialNode*>::iterator it;

    std::map<int,char*> strids;

    for(it = mapping->begin(); it != mapping->end(); it++) {

        SocialNode *node = it->second;
        char *buf = (char*)malloc(20*sizeof(char));
        sprintf(buf, "%d", node->getNodeID());
        strids.insert(pair<int,char*>(node->getNodeID(),buf));
        std::cout << buf << std::endl;
        xml_node<>* nnode = doc.allocate_node(node_element,"node");
        nnode->append_attribute(doc.allocate_attribute("id",buf));
        graph->append_node(nnode);

        // Color explored nodes
//        xml_node<>* color = doc.allocate_node(node_element,"data");
//        color->append_attribute(doc.allocate_attribute("key","r"));
//        color->value() = "0";
//        keyg->append_attribute(doc.allocate_attribute("attr.type","int"));
//        <data key="r">0</data>
//         <data key="g">0</data>
//         <data key="b">255</data>

    }


    for(it = mapping->begin(); it != mapping->end(); it++) {

        SocialNode *node = it->second;
        vector<Edge *>* friends = node->getFriends();
        /* Looping over edges for a particular node */
        int len = friends->size();

        for(int i = 0; i<len; i++){


            xml_node<>* ed = doc.allocate_node(node_element,"edge");
            ed->append_attribute(doc.allocate_attribute("source",strids.at((*friends)[i]->getSource()->getNodeID())));
            ed->append_attribute(doc.allocate_attribute("target",strids.at((*friends)[i]->getTarget()->getNodeID())));
            graph->append_node(ed);

            cout << ed->first_attribute("source")->value() << std::endl;

        }
    }

    std::string xml_as_string;

    // watch for name collisions here, print() is a very common function name!
    rapidxml::print(std::back_inserter(xml_as_string), doc);

    strids.clear();
    cout << xml_as_string;
    /* Writing the file */
    writeFile(xml_as_string);

}

void XmlWriter::writeFile(const string& str){

    ofstream myfile(filename.c_str());
    myfile << str;
    myfile.close();

}

