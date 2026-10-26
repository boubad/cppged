
#include "multimediarecord.h"
////////////////////////////////
#include "changedate.h"
#include "notestructure.h"
#include "sourcecitation.h"
#include "gedconstants.h"
////////////////////////
#include <filesystem>
//////////////////////////
namespace infoged
{

  multimediarecord::multimediarecord(const string &id)
      : entitynode(gedconstants::GED_OBJE, id) {}

  multimediarecord::multimediarecord(const multimediarecord &rec)
      : entitynode(rec) {}

  multimediarecord &multimediarecord::operator=(const multimediarecord &rec)
  {
    if (this != &rec)
    {
      entitynode::operator=(rec);
    }
    return *this;
  }

  multimediarecord::~multimediarecord()
  {
  }
  //////////////////////////////////////
  string multimediarecord::getMediaFileName(void) const
  {
    return getChildValue(gedconstants::GED_FILE);
  }
  void multimediarecord::setMediaFileName(const string &mediaFileName)
  {
    setChildValue(gedconstants::GED_FILE, mediaFileName);
  }
  string multimediarecord::getFormat(void) const
  {
    return getChildValue(gedconstants::GED_FILE, gedconstants::GED_FORM);
  }
  void multimediarecord::setFormat(const string &format)
  {
    setChildValue(gedconstants::GED_FILE, gedconstants::GED_FORM, format);
  }
  string multimediarecord::getMediaType(void) const
  {
    return getChildValue(gedconstants::GED_FILE, gedconstants::GED_FORM, gedconstants::GED_TYPE);
  }

  void multimediarecord::setMediaType(const string &mediaType)
  {
    setChildValue(gedconstants::GED_FILE, gedconstants::GED_FORM, gedconstants::GED_TYPE, mediaType);
  }
  string multimediarecord::getMediaDescriptiveTitle(void) const
  {
    return getChildValue(gedconstants::GED_FILE, gedconstants::GED_TITL);
  }
  void multimediarecord::setMediaDescriptiveTitle(
      const string &mediaDescriptiveTitle)
  {
    setChildValue(gedconstants::GED_FILE, gedconstants::GED_TITL, mediaDescriptiveTitle);
  }
  string multimediarecord::getUserReferenceNumber(void) const
  {
    return getChildValue(gedconstants::GED_REFN);
  }
  void multimediarecord::setUserReferenceNumber(
      const string &userReferenceNumber)
  {
    setChildValue(gedconstants::GED_REFN, userReferenceNumber);
  }
  string multimediarecord::getUserReferenceType(void) const
  {
    return getChildValue(gedconstants::GED_REFN, gedconstants::GED_TYPE);
  }
  void multimediarecord::setUserReferenceType(const string &userReferenceType)
  {
    setChildValue(gedconstants::GED_REFN, gedconstants::GED_TYPE, userReferenceType);
  }
  string multimediarecord::getAutomatedRecordId(void) const
  {
    return getChildValue(gedconstants::GED_RIN);
  }
  void multimediarecord::setAutomatedRecordId(const string &automatedRecordId)
  {
    setChildValue(gedconstants::GED_RIN, automatedRecordId);
  }
  const notestructure *multimediarecord::findNote() const
  {
    return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
  }
  notestructure *multimediarecord::getNote()
  {
    return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
  }
  const sourcecitation *multimediarecord::findSourceCitation(void) const
  {
    return findChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
  }
  sourcecitation *multimediarecord::getSourceCitation()
  {
    return getChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
  }
  const changedate *multimediarecord::findChangedate(void) const
  {
    return findChildNodeByTag<changedate>(gedconstants::GED_CHAN);
  }
  changedate *multimediarecord::getChangedate()
  {
    return getChildNodeByTag<changedate>(gedconstants::GED_CHAN);
  }
  //////////////////////////////
  nodetype multimediarecord::getType(void) const
  {
    return nodetype::Multimedia;
  }
  bool multimediarecord::isValid() const
  {
    if (!entitynode::isValid())
    {
      return false;
    }
    if (getTag() != gedconstants::GED_OBJE)
    {
      return false;
    }
    string mediaFileName = getMediaFileName();
    if (mediaFileName.empty())
    {
      return false;
    }
    string format = getFormat();
    if (format.empty())
    {
      return false;
    }
    return true;
  }
  void multimediarecord::check()
  {
    entitynode::check();
    string mediaFileName = getMediaFileName();
    string format = getFormat();
    if (mediaFileName.empty() || format.empty())
    {
      if (getStatus() == status::Normal)
      {
        setStatus(status::IncorrectData);
      }
    }
  }
  ////////////////////////////////
  void multimediarecord::setMediaDir(const string &mediadir)
  {
    string sfilepath = getMediaFileName();
    if (!sfilepath.empty())
    {
      std::filesystem::path p(sfilepath);
      string sfilename = p.filename().string();
      std::filesystem::path newpath(mediadir);
      newpath /= sfilename;
      string snewpath = newpath.string();
      setMediaFileName(snewpath);
    }
  } // setMediaDir
  bool multimediarecord::existsFile(const string &mediadir) const
  {
    string sfilepath = getMediaFileName();
    if (!sfilepath.empty())
    {
      std::filesystem::path p(sfilepath);
      string sfilename = p.filename().string();
      std::filesystem::path newpath(mediadir);
      newpath /= sfilename;
      string snewpath = newpath.string();
      return std::filesystem::exists(snewpath);
    }
    return false;
  } // existsFile
  //////////////////////////////
} // namespace infoged
