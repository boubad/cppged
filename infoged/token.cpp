
///////////////////////////
#include "token.h"
//////////////////////////
#include "stringutils.h"
////////////////////////
#include <cctype>
#include <cassert>
#include <fstream>
//////////////////////
namespace infoged
{
  ///////////////////////////
  static bool st_parseNextWord_(string &line, string &word)
  {
    word.clear();
    auto it = line.begin();
    // skip leading whitespace
    while (it != line.end() && std::isspace(static_cast<unsigned_char_type>(*it)))
    {
      ++it;
    }
    if (it == line.end())
    {
      return false;
    }
    auto end = it;
    // skip to end of word
    while (end != line.end() && !std::isspace(static_cast<unsigned_char_type>(*end)))
    {
      ++end;
    }
    word = line.substr(it - line.begin(), end - it);
    line.erase(it - line.begin(), end - it);
    line = stringutils::trim(line);
    return !word.empty();
  } // parseNextWord
  bool token::parseLine(const string &line, tokenPtrList &tokens)
  {
    tokens.clear();
    string trimmedLine = stringutils::trim(line);
    if (trimmedLine.empty())
    {
      return false;
    }
    const size_t n = trimmedLine.size();
    size_t pos = 0;
    // skip to first number
    while (pos < n)
    {
      if (std::isdigit(static_cast<unsigned_char_type>(trimmedLine[pos])))
      {
        break;
      }
      pos++;
    } // pos
    // no digit found
    if (pos == n)
    {
      return false;
    }
    string currentline = trimmedLine.substr(pos);
    // read first word; Must be a number
    string slevel;
    if (!st_parseNextWord_(currentline, slevel))
    {
      return false;
    }
    // ensure readen word is not the only word in the line
    if (currentline.empty() || slevel.empty())
    {
      return false;
    }
    // ensure first word is a number
    if (!stringutils::isNumber(slevel))
    {
      return false;
    }
    // convert first word to int
    const int level = std::stoi(slevel);
    // ensure level is non-negative
    if (level < 0)
    {
      return false;
    }
    // add level token
    tokens.push_back(std::make_shared<tokenLevel>(level));
    // read second word; Must be a tag or an id
    string idOrTag;
    if (!st_parseNextWord_(currentline, idOrTag))
    {
      // ensure readen word is not the only word in the line
      tokens.clear();
      return false;
    }
    if (stringutils::isPointer(idOrTag))
    {
      // readen word is a pointer (id)
      // ensure level is 0
      if (level != 0)
      {
        tokens.clear();
        return false;
      }
      // add id token
      tokens.push_back(std::make_shared<tokenId>(idOrTag));
      // read third word; Must be a tag
      string tag;
      if (st_parseNextWord_(currentline, tag))
      {
        if (!stringutils::isTag(tag))
        {
          // ensure readen word is a tag
          tokens.clear();
          return false;
        }
        // add tag token
        tokens.push_back(std::make_shared<tokenTag>(tag));
        // read fourth word; Must be a value and not a pointer
        string value;
        if (st_parseNextWord_(currentline, value))
        {
          if (stringutils::isPointer(value))
          {
            // ensure readen word is not a pointer
            tokens.clear();
            return false;
          }
          else
          {
            // add value token
            tokens.push_back(std::make_shared<tokenValue>(value));
          }
        }
        return true;
      }
      else
      {
        // ensure readen word is not the only word in the line
        tokens.clear();
        return false;
      }
    }
    // readen word must be a tag
    if (!stringutils::isTag(idOrTag))
    {
      tokens.clear();
      return false;
    }
    // add tag token
    tokens.push_back(std::make_shared<tokenTag>(idOrTag));
    // read third word; Must be a value or a pointer if not empty
    if (currentline.empty())
    {
      return true;
    }
    string value = currentline;
    if (stringutils::isPointer(value))
    {
      // add xref token
      tokens.push_back(std::make_shared<tokenXRef>(value));
    }
    else
    {
      // add value token
      tokens.push_back(std::make_shared<tokenValue>(value));
    }
    return true;
  } // parseLine
  /////////////////////////////
  tokensLine::tokensLine() : level_(-1)
  {
  }
  tokensLine::tokensLine(const token::tokenPtrList &tokens) : level_(-1)
  {
    for (const auto &o : tokens)
    {
      const token *p = o.get();
      assert(p != nullptr);
      if (!p->isValid())
      {
        continue;
      }
      switch (p->getType())
      {
      case tokentype::Level:
        level_ = p->getLevel();
        break;
      case tokentype::Tag:
        tag_ = p->getTag();
        break;
      case tokentype::Id:
        id_ = p->getId();
        break;
      case tokentype::Value:
        value_ = p->getValue();
        break;
      case tokentype::XRef:
        value_ = p->getXRef();
        break;
      default:
        break;
      } // t
    }
  }
  tokensLine::tokensLine(const tokensLine &other) : level_(other.level_), id_(other.id_), tag_(other.tag_), value_(other.value_)
  {
  }
  tokensLine &tokensLine::operator=(const tokensLine &other)
  {
    if (this != &other)
    {
      level_ = other.level_;
      tag_ = other.tag_;
      id_ = other.id_;
      value_ = other.value_;
    }
    return *this;
  }
  tokensLine::~tokensLine()
  {
  }
  int tokensLine::getLevel(void) const
  {
    return level_;
  }
  const string &tokensLine::getId(void) const
  {
    return id_;
  }
  const string &tokensLine::getTag(void) const
  {
    return tag_;
  }
  const string &tokensLine::getValue(void) const
  {
    return value_;
  }
  bool tokensLine::isValid(void) const
  {
    return level_ >= 0 && !tag_.empty();
  }
  istream &tokensLine::parseStream(istream &in, tokensLinesList &tokensLines)
  {
    tokensLines.clear();
    string line;
    while (getline(in, line))
    {
      token::tokenPtrList tokens;
      if (token::parseLine(line, tokens))
      {
        tokensLine oline(tokens);
        if (oline.isValid())
        {
          tokensLines.push_back(oline);
        }
      }
    }
    return in;
  } // parseStream
  bool tokensLine::parseFile(const string &filepath, tokensLinesList &tokensLines)
  {
    ifstream in(filepath);
    if (!in.is_open())
    {
      tokensLines.clear();
      return false;
    }
    tokensLine::parseStream(in, tokensLines);
    in.close();
    return !tokensLines.empty();
  } // parseFile
  bool tokensLine::parseEntities(const tokensLinesList &lines, tokensLinesArray &oAr)
  {
    oAr.clear();
    auto it = lines.begin();
    while (it != lines.end())
    {
      if ((*it).getLevel() == 0)
      {
        auto startIt = it++;
        while (it != lines.end() && (*it).getLevel() > 0)
        {
          ++it;
        }
        tokensLine::tokensLinesList xtokens(startIt, it);
        if (!xtokens.empty())
        {
          oAr.push_back(xtokens);
        }
      }
      else
      {
        ++it;
      }
    } // it
    return !oAr.empty();
  } // parseEntities
  ///////////////////////
  ////////////////////////
  token::token()
  {

  } //
  token::token(const token & /*other*/)
  {
  }
  token &token::operator=(const token & /*other*/)
  {
    return *this;
  }
  token::~token()
  {
  }
  int token::getLevel(void) const
  {
    return -1;
  }
  const string &token::getId(void) const
  {
    static const string emptystring_;
    return emptystring_;
  }
  const string &token::getTag(void) const
  {
    static const string emptystring_;
    return emptystring_;
  }
  const string &token::getXRef(void) const
  {
    static const string emptystring_;
    return emptystring_;
  }
  const string &token::getValue(void) const
  {
    static const string emptystring_;
    return emptystring_;
  }
  ///////////////////////////////
  tokenLevel::tokenLevel(int level) : level_(-1)
  {
    if (level >= 0)
    {
      level_ = level;
    }
  }
  tokenLevel::tokenLevel(const tokenLevel &other)
      : token(other), level_(other.level_) {}
  tokenLevel &tokenLevel::operator=(const tokenLevel &other)
  {
    if (this != &other)
    {
      token::operator=(other);
      level_ = other.level_;
    }
    return *this;
  }
  tokenLevel::~tokenLevel()
  {
  }
  tokentype tokenLevel::getType(void) const
  {
    return tokentype::Level;
  }
  int tokenLevel::getLevel(void) const
  {
    return level_;
  }
  bool tokenLevel::isValid(void) const
  {
    return level_ >= 0;
  }
  //////////////////////////////
  tokenId::tokenId(const string &id)
  {
    string s = stringutils::trim(id);
    if (stringutils::isPointer(s))
    {
      id_ = s;
    }
  }
  tokenId::tokenId(const tokenId &other) : token(other), id_(other.id_)
  {
  }
  tokenId &tokenId::operator=(const tokenId &other)
  {
    if (this != &other)
    {
      token::operator=(other);
      id_ = other.id_;
    }
    return *this;
  }
  tokenId::~tokenId()
  {
  }
  tokentype tokenId::getType(void) const
  {
    return tokentype::Id;
  }
  const string &tokenId::getId(void) const
  {
    return id_;
  }
  bool tokenId::isValid(void) const
  {
    return stringutils::isPointer(id_);
  }
  //////////////////////////////
  tokenTag::tokenTag(const string &tag)
  {
    string s = stringutils::uppercase(stringutils::trim(tag));
    if (stringutils::isTag(s))
    {
      tag_ = s;
    }
  }
  tokenTag::tokenTag(const tokenTag &other) : token(other), tag_(other.tag_)
  {
  }
  tokenTag &tokenTag::operator=(const tokenTag &other)
  {
    if (this != &other)
    {
      token::operator=(other);
      tag_ = other.tag_;
    }
    return *this;
  }
  tokenTag::~tokenTag()
  {
  }
  tokentype tokenTag::getType(void) const
  {
    return tokentype::Tag;
  }
  const string &tokenTag::getTag(void) const
  {
    return tag_;
  }

  bool tokenTag::isValid(void) const
  {
    return stringutils::isTag(tag_);
  }
  ///////////////////////////////
  tokenXRef::tokenXRef(const string &xref)
  {
    string s = stringutils::trim(xref);
    if (stringutils::isPointer(s))
    {
      xref_ = s;
    }
  }
  tokenXRef::tokenXRef(const tokenXRef &other)
      : token(other), xref_(other.xref_)
  {
  }
  tokenXRef &tokenXRef::operator=(const tokenXRef &other)
  {
    if (this != &other)
    {
      token::operator=(other);
      xref_ = other.xref_;
    }
    return *this;
  }
  tokenXRef::~tokenXRef()
  {
  }
  tokentype tokenXRef::getType(void) const
  {
    return tokentype::XRef;
  }
  const string &tokenXRef::getXRef(void) const
  {
    return xref_;
  }
  bool tokenXRef::isValid(void) const
  {
    return stringutils::isPointer(xref_);
  }
  /////////////////////////////
  tokenValue::tokenValue(const string &value)
  {
    value_ = stringutils::trim(value);
  }
  tokenValue::tokenValue(const tokenValue &other)
      : token(other), value_(other.value_)
  {
  }
  tokenValue &tokenValue::operator=(const tokenValue &other)
  {
    if (this != &other)
    {
      token::operator=(other);
      value_ = other.value_;
    }
    return *this;
  }
  tokenValue::~tokenValue()
  {
  }
  tokentype tokenValue::getType(void) const
  {
    return tokentype::Value;
  }
  const string &tokenValue::getValue(void) const
  {
    return value_;
  }
  bool tokenValue::isValid(void) const
  {
    return true;
  }
  //////////////////////////////
} // namespace infoged