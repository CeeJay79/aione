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

