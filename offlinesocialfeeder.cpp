#include "offlinesocialfeeder.hpp"

using std::string;

OfflineSocialFeeder::OfflineSocialFeeder(const string& filename)
{

    /* XML import */
    XmlReader xmlreader(filename);
    mapping = xmlreader.parseSocialGraph();

}
