#include "xmlreader.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

#include "edge.hpp"


using namespace std;
using namespace rapidxml;

XmlReader::XmlReader(const std::string& filename){

    /* Reading Xml file as a string */

     std::ifstream ifs(filename.c_str());

     if (!ifs){

         cerr << "Unable to open file " << filename << endl;

     }

     std::string stri((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

     ifs.close();

     /* Storing the string for printing purposes */
     str = stri.c_str();



}

void XmlReader::print(){

    cout << str << endl;

}

std::map<int,SocialNode*>* XmlReader::parseSocialGraph(){

    std::map<int,SocialNode*>* mapping = new std::map<int,SocialNode*>();

        // (input_xml contains the above XML)

        // make a safe-to-modify copy of input_xml
        // (you should never modify the contents of an std::string directly)
        vector<char> xml_copy(str.begin(), str.end());
        xml_copy.push_back('\0');

        // only use xml_copy from here on!
        // we are choosing to parse the XML declaration
        // parse_no_data_nodes prevents RapidXML from using the somewhat surprising
        // behavior of having both values and data nodes, and having data nodes take
        // precedence over values when printing
        // >>> note that this will skip parsing of CDATA nodes <<<
        doc.parse<parse_declaration_node | parse_no_data_nodes>(&xml_copy[0]);

        // alternatively, use one of the two commented lines below to parse CDATA nodes,
        // but please note the above caveat about surprising interactions between
        // values and data nodes (also read http://www.ffuts.org/blog/a-rapidxml-gotcha/)
        // if you use one of these two declarations try to use data nodes exclusively and
        // avoid using value()
        //doc.parse<parse_declaration_node>(&xml_copy[0]); // just get the XML declaration
        //doc.parse<parse_full>(&xml_copy[0]); // parses everything (slowest)

        // since we have parsed the XML declaration, it is the first node
        // (otherwise the first node would be our root node)
        string encoding = doc.first_node()->first_attribute("encoding")->value();
        // encoding == "utf-8"

        cout << encoding;

        // we didn't keep track of our previous traversal, so let's start again
        // we can match nodes by name, skipping the xml declaration entirely
        xml_node<>* cur_node = doc.first_node("graphml")->first_node("graph");
//        string graphID = cur_node->first_attribute("id")->value();

//        cout << "Graph ID : " << graphID << endl;

        cur_node = cur_node->first_node("node");

        /* Looping over the nodes */
        for (cur_node;cur_node && strcmp(cur_node->name(),"node") == 0; cur_node = cur_node->next_sibling()){

            // String to integer ID
            int idd;
            istringstream ss(cur_node->first_attribute("id")->value());
            ss >> idd;

           // cout << cur_node->name() << "  : " << idd << endl;

            // Create mapping entry between ID and Node CLass Instance
            mapping->insert(pair<int,SocialNode*>(idd,new SocialNode(idd)));


        }



        /* Looping over the edges */
        for (cur_node;cur_node &&  strcmp(cur_node->name(),"edge") == 0; cur_node = cur_node->next_sibling()){

            // String to integer ID
            int sourceid, targetid;
            istringstream ss1(cur_node->first_attribute("source")->value());
            ss1 >> sourceid;
            istringstream ss2(cur_node->first_attribute("target")->value());
            ss2 >> targetid;

           // cout << cur_node->name() << " : " << cur_node->first_attribute("source")->value() << " to " << cur_node->first_attribute("target")->value()  << endl;



            // Retrives node point from map
            SocialNode *sourceNode = mapping->at(sourceid);
            SocialNode *targetNode = mapping->at(targetid);
            /* Adds friend to friendlist */
            Edge *edge = new Edge(sourceNode,targetNode);
            edge->setCost(1);
            sourceNode->addFriend(edge);



        }

        cout << "XML import completed" << endl;


        return mapping;


}
