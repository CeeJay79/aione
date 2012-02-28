#ifndef XMLREADER_HPP
#define XMLREADER_HPP

#include <string>
#include <vector>
#include "rapidxml.hpp"
#include "edge.hpp"
#include "node.hpp"
#include <map>
#include "typeinfo"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

/* Includes related to node models */
#include "socialnode.hpp"
#include "mechanicalnode.hpp"

using namespace rapidxml;

class XmlReader
{
public:
    XmlReader(const std::string& filename);

    void print();

private:

    std::string str;

    rapidxml::xml_document<> doc;

public :

    template<class NodeType>
    std::map<int,NodeType*>* parseGraph(){

        // Common parsing code

        std::map<int,NodeType*>* mapping = new std::map<int,NodeType*>();

        // make a safe-to-modify copy of input_xml
        // (you should never modify the contents of an std::string directly)
        std::vector<char> xml_copy(str.begin(), str.end());
        xml_copy.push_back('\0');
        doc.parse<parse_declaration_node | parse_no_data_nodes>(&xml_copy[0]);


        std::string encoding = doc.first_node()->first_attribute("encoding")->value();
        // encoding == "utf-8"

        std::cout << encoding;

        xml_node<>* cur_node = doc.first_node("graphml")->first_node("graph");


                cur_node = cur_node->first_node("node");


                /* Looping over the nodes */
                for (cur_node;cur_node && strcmp(cur_node->name(),"node") == 0; cur_node = cur_node->next_sibling()){

                    // String to integer ID
                    int idd;
                    std::istringstream ss(cur_node->first_attribute("id")->value());
                    ss >> idd;

                    NodeType* newnode = new NodeType(idd);

                    mapping->insert(std::pair<int,NodeType*>(idd,newnode));

                    // Mechanical node : parsing X,Y,Z coordinates
                    if (typeid(NodeType) == typeid(MechanicalNode)){
                        double x,y,z;

                        x = atof(cur_node->first_attribute("x")->value());

                        y = atof(cur_node->first_attribute("y")->value());

                        z = atof(cur_node->first_attribute("z")->value());

                        std::cout << "ID : " << idd << "/ XX :" << x << "/ Y : " << y << " / Z : " << z << std::endl;

                        MechanicalNode* mechnode = (MechanicalNode *)newnode;
                        mechnode->setPos(x,y,z);
                    }




                }

                /* Looping over the edges */
                for (cur_node;cur_node &&  strcmp(cur_node->name(),"edge") == 0; cur_node = cur_node->next_sibling()){

                    // String to integer ID
                    int sourceid, targetid;
                    std::istringstream ss1(cur_node->first_attribute("source")->value());
                    ss1 >> sourceid;
                    std::istringstream ss2(cur_node->first_attribute("target")->value());
                    ss2 >> targetid;

                   // cout << cur_node->name() << " : " << cur_node->first_attribute("source")->value() << " to " << cur_node->first_attribute("target")->value()  << endl;

                    // Retrives node point from map

                       NodeType *sourceNode = mapping->at(sourceid);
                       NodeType *targetNode = mapping->at(targetid);


                    /* Adds friend to friendlist */
                    Edge *edge1 = new Edge(sourceNode,targetNode);
                    Edge *edge2 = new Edge(targetNode,sourceNode);
                    edge1->setCost(1);
                    edge2->setCost(1);
                    sourceNode->addSuccessor(edge1);
                    targetNode->addSuccessor(edge2);

                }



        std::cout << "XML import completed" << std::endl;


        return mapping;





    }


};
#endif // XMLREADER_HPP
