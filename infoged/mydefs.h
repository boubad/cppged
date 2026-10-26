#pragma once
#ifndef MYDEFS_H__
#define MYDEFS_H__
///////////////////////////
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <istream>
#include <fstream>
#include <sstream>
///////////////////////////
namespace infoged {
/////////////////////////////
using char_type = char;
using unsigned_char_type = unsigned char;
using string = std::string;
using ostream = std::ostream;
using istream = std::istream;
using ifstream = std::ifstream;
using ofstream = std::ofstream;
using istringstream = std::istringstream;
using ostringstream = std::ostringstream;
using stringstream = std::stringstream;
///////////////////////////
using stringvector = std::vector<string>;
using stringlist = std::list<string>;
using stringset = std::set<string>;
using stringmap = std::map<string, string>;
using stringmapvector = std::vector<stringmap>;
using intset = std::set<int>;
////////////////
} // namespace infoged
  //////////////////////////////
#endif // MYDEFS_H
