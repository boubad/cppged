
#include "notestructure.h"
#include "gedconstants.h"
#include "stringutils.h"
namespace infoged
{
  notestructure::notestructure(int level, const string &value)
      : multinode(level, gedconstants::GED_NOTE)
  {
    string sval = stringutils::trim(value);
    if (sval.length() <= 220)
    {
      setValue(sval);
    }
    else
    {
      setSubmitterText(sval);
    }
  }
  notestructure::notestructure(const notestructure &other)
      : multinode(other) {}
  notestructure &notestructure::operator=(const notestructure &other)
  {
    if (this != &other)
    {
      multinode::operator=(other);
    }
    return *this;
  }
  notestructure::~notestructure()
  {
  }
  string notestructure::getNoteReference(void) const
  {
    string sref = getValue();
    return stringutils::isPointer(sref) ? sref : string();
  }
  void notestructure::setNoteReference(const string &noteRefrence)
  {
    string sref = stringutils::trim(noteRefrence);
    if (stringutils::isPointer(sref))
    {
      setValue(sref);
    }
    else
    {
      setValue(string());
      getChildren().clear();
    }
  }
  string notestructure::getSubmitterText(void) const
  {
    string sref = getValue();
    if (stringutils::isPointer(sref))
    {
      return string();
    }
    return getMultiLinesValue();
  }
  void notestructure::setSubmitterText(const string &submitterText)
  {
    setMultiLinesValue(submitterText);
  }
  nodetype notestructure::getType(void) const
  {
    return nodetype::NoteStructure;
  }
  bool notestructure::isValid(void) const
  {
    if (!multinode::isValid() || getTag() != gedconstants::GED_NOTE)
    {
      return false;
    }
    string ref = getNoteReference();
    string submittertext = getSubmitterText();
    if (ref.empty() && submittertext.empty())
    {
      return false;
    }
    return true;
  }
  void notestructure::check(void)
  {
    multinode::check();
    string ref = getNoteReference();
    string submittertext = getSubmitterText();
    if (ref.empty() && submittertext.empty())
    {
      setStatus(status::MissingData);
    }
  }
} // namespace infoged
