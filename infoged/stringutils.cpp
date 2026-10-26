
/////////////////////////
#include "stringutils.h"
#include "stringconstants.h"
/////////////////////////////
#include <cassert>
#include <regex>

///////////////////////////////
namespace infoged
{
  string stringutils::uppercase(const string &sx)
  {
    string s(sx);
    for (auto &c : s)
    {
      c = static_cast<char_type>(
          std::toupper(static_cast<unsigned_char_type>(c)));
    }
    return s;
  } // _uppercase
  // Function to trim whitespace from both ends
  string stringutils::trim(const string &s)
  {
    auto it = s.begin();
    while (it != s.end())
    {
      if (!std::isspace(static_cast<unsigned_char_type>(*it)))
      {
        break;
      }
      ++it;
    }
    if (it == s.end())
    {
      return string();
    }
    auto jt = s.end();
    --jt;
    while (it != jt)
    {
      if (!std::isspace(static_cast<unsigned_char_type>(*jt)))
      {
        break;
      }
      --jt;
    }
    string sret = s.substr(it - s.begin(), jt - it + 1);
    return sret;
  } // _trim
  void stringutils::splitlinevalue(const string &line, stringvector &values,
                                   size_t threshold)
  {
    values.clear();
    string sline = stringutils::trim(line);
    if (sline.empty())
    {
      return;
    }
    if (sline.length() <= threshold)
    {
      while (!sline.empty())
      {
        auto pos = sline.find(stringconstants::LF);
        if (pos == string::npos)
        {
          values.push_back(sline);
          return;
        }
        string sli = sline.substr(0, pos);
        sline = sline.substr(pos + 1);
        if (!sli.empty())
        {
          values.push_back(sli);
        }
      }
      return;
    }
    stringvector xvalues;
    size_t start = 0;
    while (start < sline.length())
    {
      size_t end = start + threshold;
      if (end > sline.length())
      {
        end = sline.length();
      }
      string scur = sline.substr(start, end - start);
      xvalues.push_back(scur);
      start = end;
    }
    const size_t n = xvalues.size();
    for (size_t i = 0; i < n; i++)
    {
      string ival = xvalues[i];
      while (!ival.empty())
      {
        auto pos = ival.find(stringconstants::LF);
        if (pos == string::npos)
        {
          values.push_back(ival);
          ival.clear();
        }
        string sli = ival.substr(0, pos);
        ival = ival.substr(pos + 1);
        if (!sli.empty())
        {
          values.push_back(sli);
        }
      }
    } // i
  } // _split
  bool stringutils::isPointer(const string &s)
  {
    string ss = stringutils::trim(s);
    if (ss.length() > 2)
    {
      return ss.front() == stringconstants::AROBAS && ss.back() == stringconstants::AROBAS;
    }
    return false;
  } // isPointer
  bool stringutils::isTag(const string &s)
  {
    string ss = stringutils::trim(s);
    if (ss.empty())
    {
      return false;
    }
    for (const auto &c : ss)
    {
      if (!std::isalpha(static_cast<unsigned_char_type>(c)) &&
          c != stringconstants::UNDERSCORE &&
          !std::isdigit(static_cast<unsigned_char_type>(c)))
      {
        return false;
      }
    }
    return true;
  }
  bool stringutils::isCompliantTag(const string &s)
  {
    string ss = stringutils::trim(s);
    if (ss.empty())
    {
      return false;
    }
    for (const auto &c : ss)
    {
      if (!std::isalpha(static_cast<unsigned_char_type>(c)))
      {
        return false;
      }
    }
    return true;
  }
  bool stringutils::isNumber(const string &s)
  {
    string ss = stringutils::trim(s);
    if (ss.empty())
    {
      return false;
    }
    std::regex pattern(stringconstants::NUMBER_PATTERN);
    return std::regex_match(ss, pattern);
  } // isNumber
  //
  bool stringutils::parseStream(istream &in, std::list<string> &lines)
  {
    lines.clear();
    string line;
    while (getline(in, line).good())
    {
      string s = stringutils::trim(line);
      lines.push_back(s);
    }
    return !lines.empty();
  } // parseStream
  bool stringutils::parseFile(const string &filepath, std::list<string> &lines)
  {
    lines.clear();
    ifstream in(filepath);
    if (!in.is_open())
    {
      return false;
    }
    stringutils::parseStream(in, lines);
    in.close();
    return true;
  }
  //
} // namespace infoged
/////////////////////////////////
