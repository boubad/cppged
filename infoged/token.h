#pragma once
#ifndef TOKEN_H__
#define TOKEN_H__
/////////////////////////
#include <memory>
#include <list>
///////////////////////////
#include "mydefs.h"
///////////////////////////
#include "tokentype.h"
////////////////////////
namespace infoged
{
  ///////////////////////
  class token
  {
  public:
    using tokenPtr = std::shared_ptr<token>;
    using tokenPtrList = std::list<tokenPtr>;

  protected:
    token();
    token(const token &other);
    token &operator=(const token &other);

  public:
    virtual ~token();

  public:
    virtual tokentype getType(void) const = 0;
    virtual bool isValid(void) const = 0;
    //
    virtual int getLevel(void) const;
    virtual const string &getId(void) const;
    virtual const string &getTag(void) const;
    virtual const string &getXRef(void) const;
    virtual const string &getValue(void) const;

  public:
    static bool parseLine(const string &line, tokenPtrList &tokens);
  }; // class Token
  ///////////////////////////////
  class tokensLine
  {
  public:
    using tokensLinesList = std::list<tokensLine>;
    using tokensLinesArray = std::list<tokensLinesList>;

  public:
    tokensLine();
    tokensLine(const token::tokenPtrList &tokens);
    tokensLine(const tokensLine &other);
    tokensLine &operator=(const tokensLine &other);
    virtual ~tokensLine();

  public:
    int getLevel(void) const;
    const string &getId(void) const;
    const string &getTag(void) const;
    const string &getValue(void) const;
    bool isValid(void) const;

  public:
    static istream &parseStream(istream &in, tokensLinesList &tokensLines);
    static bool parseFile(const string &filepath, tokensLinesList &tokensLines);
    static bool parseEntities(const tokensLinesList &lines, tokensLinesArray &oAr);
  private:
    int level_;
    string id_;
    string tag_;
    string value_;
  }; // class tokensLine
  ////////////////////////////////
  class tokenLevel : public token
  {
  public:
    tokenLevel(int level = -1);
    tokenLevel(const tokenLevel &other);
    tokenLevel &operator=(const tokenLevel &other);
    virtual ~tokenLevel();

  public:
    virtual tokentype getType(void) const override;
    virtual bool isValid(void) const override;
    //
    virtual int getLevel(void) const override;

  private:
    int level_;
  }; // class tokenLevel
  /////////////////////////////
  class tokenId : public token
  {
  public:
    tokenId(const string &id = string());
    tokenId(const tokenId &other);
    tokenId &operator=(const tokenId &other);
    virtual ~tokenId();

  public:
    virtual tokentype getType(void) const override;
    virtual bool isValid(void) const override;
    //
    virtual const string &getId(void) const override;

  private:
    string id_;
  }; // class tokenId
  /////////////////////////////
  class tokenTag : public token
  {
  public:
    tokenTag(const string &tag = string());
    tokenTag(const tokenTag &other);
    tokenTag &operator=(const tokenTag &other);
    virtual ~tokenTag();

  public:
    virtual tokentype getType(void) const override;
    virtual bool isValid(void) const override;
    //
    virtual const string &getTag(void) const override;

  private:
    string tag_;
  }; // class tokenTag
  ////////////////////////////////
  class tokenXRef : public token
  {
  public:
    tokenXRef(const string &xref = string());
    tokenXRef(const tokenXRef &other);
    tokenXRef &operator=(const tokenXRef &other);
    virtual ~tokenXRef();

  public:
    virtual tokentype getType(void) const override;
    virtual bool isValid(void) const override;
    //
    virtual const string &getXRef(void) const override;

  private:
    string xref_;
  }; // class tokenXRef
  //////////////////////////////////
  class tokenValue : public token
  {
  public:
    tokenValue(const string &value = string());
    tokenValue(const tokenValue &other);
    tokenValue &operator=(const tokenValue &other);
    virtual ~tokenValue();

  public:
    virtual tokentype getType(void) const override;
    virtual bool isValid(void) const override;
    //
    virtual const string &getValue(void) const override;

  private:
    string value_;
  };
  /////////////////////////////////
} // namespace infoged
////////////////////////////
#endif // TOKEN_H__
