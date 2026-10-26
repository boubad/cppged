#pragma once
#ifndef NODE_H
#define NODE_H
/////////////////////
#include "mydefs.h"
#include "status.h"
#include "nodetype.h"
///////////////////////////
#include <functional>
#include <list>
#include <memory>

//////////////////////////////
namespace infoged
{
  //////////////////////
  class multinode;
  /////////////////////////
  class node
  {
  public:
    using nodePtr = std::shared_ptr<node>;
    using nodePtrList = std::list<nodePtr>;
    using nodeCreateFunc = std::function<nodePtr(
        int, const string &, const string &, const string &)>;
    using visitorFunc = std::function<void(const node *)>;
    using filterFunc = std::function<bool(const node *)>;
    using mutateFunc = std::function<void(node *)>;

  protected:
    node();
    node(const node &other);
    node &operator=(const node &other);

  public:
    virtual ~node();
    bool isNonCompliant(void) const;
  public:
    virtual int getLevel(void) const;
    virtual void setLevel(int level);
    virtual const string &getId(void) const;
    virtual multinode *getParent(void) const;
    virtual void setParent(multinode *p);
    virtual status getStatus(void) const;
    virtual void setStatus(status st);
    virtual nodetype getType(void) const;
    virtual const string &getTag(void) const;
    virtual const string &getValue(void) const;
    virtual void setValue(const string &value);
    virtual bool isValid(void) const;
    virtual void check(void);
    virtual ostream &write(ostream &os) const;
    virtual void clear(void);
    virtual void mutate(const std::function<void(node *)> &func);
    virtual void visit(const std::function<void(const node *)> &func) const;
    virtual void remove(const std::function<bool(const node *)> &func);
    virtual string getLineString(void) const;
  public:
    static nodePtr createTest(void);
  }; // class node
  //////////////////////////
} // namespace infoged
////////////////////////////
inline infoged::ostream &operator<<(infoged::ostream &os,
                                    const infoged::node &p)
{
  return p.write(os);
}
//////////////////////////////
#endif // GEDCONSTANTS_H
