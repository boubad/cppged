#pragma once
#ifndef STRINGCONSTANTS_H
#define STRINGCONSTANTS_H
/////////////////////////////////////
#include "mydefs.h"
///////////////////////////////////////
namespace infoged {
class stringconstants {
private:
  stringconstants() = delete;
  stringconstants(const stringconstants &other) = delete;
  stringconstants &operator=(const stringconstants &other) = delete;

public:
  static const int MAX_LEVEL_VALUE;
  static const size_t LINE_MAX_LENGTH;
  static const size_t ID_MAX_LENGTH;
  static const size_t VALUE_LENGTH_THRESHOLD;
  static const size_t TAG_MAX_LENGTH;
  //
  static const char_type AROBAS;
  static const char_type ZERO;
  static const char_type ONE;
  static const char_type NINE;
  static const char_type CR;
  static const char_type CHAR_SPACE;
  static const char_type LF;
  static const char_type UNDERSCORE;
  //
  static const string EMPTY;
  static const string SLASH;
  static const string SPACE;
  static const string TAB;
  static const string COLON;
  static const string WHITECHARS;
  static const string ALPHA;
  static const string ELIPSIS;
  static const string NEWLINE;
  //
  static const string NUMBER_PATTERN;
  //
  static const string STR_QINC;
  static const string STR_QQUESTION;
  //
  static const string STR_INC;
  static const string STR_UNKNOWN;
  static const string STR_QUESTION;
  static const string STR_UNKN;
  static const string STR_LINE_DUMP;
  static const string STR_LINE_COLON;
  static const string STR_LINE_ERRORS;
  static const string STR_LINE_NONCOMPLIANTS;
  static const string STR_MISSING_ENTITY;
  static const string STR_NOTREFERENCED_ENTITY;
  //

  static const string ERR_EMPTY_LINE;
  static const string ERR_LINE_TOO_LONG;
  static const string ERR_CANNOT_DECODE;
  static const string ERR_INVALID_LEVEL;
  static const string ERR_INVALID_ID;
  static const string ERR_INVALID_TAG;
  static const string ERR_NONSTANDART_TAG;
  static const string ERR_INVALID_LINESEQUENCE;
  static const string ERR_INVALID_VALUELENGTH;
  //

}; // class stringconstants
} // namespace infoged
//////////////////////////
#endif
