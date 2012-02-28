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
        doc.parse<parse_declaration_node | parse_no_data_nodes>(&xml_copy[0]);


        string encoding = doc.first_node()->first_attribute("encoding")->value();
        // encoding == "utf-8"

        cout << encoding;

        xml_node<>* cur_node = doc.first_node("graphml")->first_node("graph");

        cur_node = cur_node->first_node("node");

        /* Looping over the nodes */
        for (cur_node;cur_node && strcmp(cur_node->name(),"node") == 0; cur_node = cur_node->next_sibling()){

            // String to integer ID
            int idd;
            istringstream ss(cur_node->first_attribute("id")->value());
            ss >> idd;

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
            Edge *edge1 = new Edge(sourceNode,targetNode);
            Edge *edge2 = new Edge(targetNode,sourceNode);
            edge1->setCost(1);
            edge2->setCost(1);
            sourceNode->addFriend(edge1);
            targetNode->addFriend(edge2);



        }

        cout << "XML import completed" << endl;


        return mapping;


}
