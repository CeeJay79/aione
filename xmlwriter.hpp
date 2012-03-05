#ifndef XMLWRITER_HPP
#define XMLWRITER_HPP

#include <string>

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "socialnode.hpp"
#include "offlinefeeder.hpp"

class XmlWriter
{
public:
    XmlWriter(const std::string& filename);

    void write(OfflineFeeder<SocialNode>* graph_);

private:
    std::string filename;

    void writeFile(const std::string& filename_);
};

#endif // XMLWRITER_HPP
