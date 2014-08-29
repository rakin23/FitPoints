//============================================================================
// Name        : FitPoints.cpp
// Author      : Andrew Snyder
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "rapidxml.hpp"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
using namespace rapidxml;

int main()
{
   xml_document<> doc;
   std::ifstream file("activity_575641024.tcx");
   std::stringstream buffer;
   buffer << file.rdbuf();
   file.close();
   std::string content(buffer.str());
   doc.parse<0>(&content[0]);
   xml_node<> *pRoot = doc.first_node();
   xml_node<> *pNode = pRoot->first_node();
   xml_attribute<> *pAttr = pNode->first_attribute("attribute");
   int nValue = atoi(pAttr->value());
   cout << nValue;

   // With the xml example above this is the <document/> node

   cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
   return 0;
}
