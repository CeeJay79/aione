#ifndef XMLWRITER_HPP
#define XMLWRITER_HPP

#include <string>
#include "offlinesocialfeeder.hpp"
#include "rapidxml.hpp"

class XmlWriter
{
public:
    XmlWriter(const std::string& filename);

    write(OfflineSocialFeeder* graph_);

private:
    std::string filename;
};

#endif // XMLWRITER_HPP
