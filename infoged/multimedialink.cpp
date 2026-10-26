
////////////////////////
#include "multimedialink.h"
#include "gedconstants.h"
#include "stringutils.h"
//////////////////////////
namespace infoged
{
    multimedialink::multimedialink(int level, const string &xref)
        : multinode(level, gedconstants::GED_OBJE, xref)
    {
    }
    multimedialink::multimedialink(const multimedialink &other) : multinode(other)
    {
    }

    multimedialink &multimedialink::operator=(const multimedialink &other)
    {
        if (this != &other)
        {
            multinode::operator=(other);
        }
        return *this;
    }

    multimedialink::~multimedialink()
    {
    }
    string multimedialink::getObjectReference(void) const
    {
        string sval = getValue();
        return stringutils::isPointer(sval) ? sval : string();
    }
    void multimedialink::setObjectReference(const string &xref)
    {
        string ref = stringutils::trim(xref);
        if (stringutils::isPointer(ref))
        {
            setValue(ref);
        }
        else
        {
            setValue(string());
        }
    }
    string multimedialink::getFileRef(void) const
    {
        return getChildValue(gedconstants::GED_FILE);
    }
    void multimedialink::setFileRef(const string &fileref)
    {
        setChildValue(gedconstants::GED_FILE, fileref);
    }
    string multimedialink::getFormat(void) const
    {
        return getChildValue(gedconstants::GED_FILE, gedconstants::GED_FORM);
    }
    void multimedialink::setFormat(const string &format)
    {
        setChildValue(gedconstants::GED_FILE, gedconstants::GED_FORM, format);
    }
    string multimedialink::getMediaType(void) const
    {
        return getChildValue(gedconstants::GED_FILE, gedconstants::GED_FORM, gedconstants::GED_MEDI);
    }
    void multimedialink::setMediaType(const string &mediatype)
    {
        setChildValue(gedconstants::GED_FILE, gedconstants::GED_FORM, gedconstants::GED_MEDI, mediatype);
    }
    string multimedialink::getTitle(void) const
    {
        return getChildValue(gedconstants::GED_TITL);
    }
    void multimedialink::setTitle(const string &title)
    {
        setChildValue(gedconstants::GED_TITL, title);
    }
    nodetype multimedialink::getType(void) const
    {
        return nodetype::MultimediaLink;
    }
    bool multimedialink::isValid(void) const
    {
        if (!multinode::isValid() || getTag() != gedconstants::GED_OBJE)
        {
            return false;
        }
        string xref = getObjectReference();
        if (stringutils::isPointer(xref))
        {
            return true;
        }
        string file = getFileRef();
        string format = getFormat();
        if (file.empty() || format.empty())
        {
            return false;
        }
        return true;
    }
    void multimedialink::check(void)
    {
        multinode::check();
        if (getStatus() != status::Normal)
        {
            return;
        }
        string xref = getObjectReference();
        if (stringutils::isPointer(xref))
        {
            return;
        }
        string file = getFileRef();
        string format = getFormat();
        if (file.empty() || format.empty())
        {
            setStatus(status::IncorrectData);
        }
    }
} // namespace infoged