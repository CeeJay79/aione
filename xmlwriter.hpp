#ifndef XMLWRITER_HPP
#define XMLWRITER_HPP

#include <string>
#include "offlinesocialfeeder.hpp"
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

class XmlWriter
{
public:
    XmlWriter(const std::string& filename);

    void write(OfflineSocialFeeder* graph_);

private:
    rapidxml::xml_document<> doc;

    std::string filename;

    void writeFile(const std::string& filename_);
};

#endif // XMLWRITER_HPP
