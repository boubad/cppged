#pragma once
#ifndef CHANGENODE_H__
#define CHANGENODE_H__
/////////////////////.
#include "multinode.h"
/////////////////////////
namespace infoged
{
  class notestructure;
  class changedate : public multinode
  {
  public:
    changedate(int level = -1);
    changedate(const changedate &other);
    changedate &operator=(const changedate &other);
    virtual ~changedate();

  public:
    string getDate(void) const;
    void setDate(const string &date);
    string getTime(void) const;
    void setTime(const string &time);
    const notestructure *findNote(void) const;
    notestructure *getNote(void);

  public:
    virtual void check(void) override;
    virtual bool isValid() const override;
    virtual nodetype getType(void) const override;
    // destructor
  }; // class ChangeNode
} // namespace infoged
#endif // CHANGENODE_H__
