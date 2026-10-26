
///////////////////////
#include "changedate.h"
//////////////////////
#include "notestructure.h"
#include "gedconstants.h"
/////////////////////////
#include <cassert>
////////////////////////
namespace infoged
{
  changedate::changedate(int level)
      : multinode(level, gedconstants::GED_CHAN)
  {
  }
  changedate::changedate(const changedate &other) : multinode(other) {}
  changedate &changedate::operator=(const changedate &other)
  {
    if (this != &other)
    {
      multinode::operator=(other);
    }
    return *this;
  }
  changedate::~changedate()
  {
  }
 
  string changedate::getDate() const
  {
    return getChildValue(gedconstants::GED_DATE);
  }
  void changedate::setDate(const string &date)
  {
    setChildValue(gedconstants::GED_DATE, date);
  }

  string changedate::getTime() const
  {
    return getChildValue(gedconstants::GED_DATE, gedconstants::GED_TIME);
  }
  void changedate::setTime(const string &time)
  {
    setChildValue(gedconstants::GED_DATE, gedconstants::GED_TIME, time);
  }
  const notestructure *changedate::findNote(void) const
  {
    return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
  }
  notestructure *changedate::getNote(void)
  {
    return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
  }
  bool changedate::isValid() const
  {
    if (!multinode::isValid())
    {
      return false;
    }
    string date = getDate();
    string time = getTime();
    if (date.empty() && time.empty())
    {
      return false;
    }
    return getTag() == gedconstants::GED_CHAN;
  }
  nodetype changedate::getType(void) const 
  { 
    return nodetype::ChangeDate; 
  }
  void changedate::check(void)
  {
    multinode::check();
    string date = getDate();
    string time = getTime();
    if (date.empty() || time.empty())
    {
      if (getStatus() == status::Normal)
      {
        setStatus(status::IncorrectData);
      }
    }
  }
} // namespace infoged
