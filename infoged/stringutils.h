#pragma once
#ifndef STRINGUTILS_H
#define STRINGUTILS_H
///////////////////////////////
#include "mydefs.h"
///////////////////////
namespace infoged {
class stringutils {
private:
  stringutils() = delete;
  stringutils(const stringutils &other) = delete;
  stringutils &operator=(const stringutils &other) = delete;

public:
  static string trim(const string &s);
  static string uppercase(const string &s);
  static void splitlinevalue(const string &line, stringvector &values,
                             size_t threshold = 220);
  static bool isPointer(const string &s);
  static bool isTag(const string &s);
  static bool isCompliantTag(const string &s);
  static bool isNumber(const string &s);
  //
  static bool parseStream(istream &in, stringlist &lines);
  static bool parseFile(const string &filepath, stringlist &lines);
};
} // namespace infoged
/////////////////////////////////
#endif //  STRINGUTILS_H
