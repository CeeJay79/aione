#ifndef XMLREADER_HPP
#define XMLREADER_HPP

#include <string>
#include <vector>
#include "rapidxml.hpp"
#include "edge.hpp"
#include "node.hpp"
#include <map>

/* Includes related to node models */
#include "socialnode.hpp"

class XmlReader
{
public:
    XmlReader(const std::string& filename);

    void print();


    std::map<int,SocialNode*>* parseSocialGraph();

private:

    std::string str;

    rapidxml::xml_document<> doc;



};
#endif // XMLREADER_HPP
