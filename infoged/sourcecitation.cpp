
/////////////////////////
#include "sourcecitation.h"
//////////////////////////
#include "notestructure.h"
#include "multimedialink.h"
#include "gedconstants.h"
#include "stringutils.h"
/////////////////////////
namespace infoged
{
    sourcecitation::sourcecitation(int level, const string &xref) : multinode(level, gedconstants::GED_SOUR, xref)
    {
    }
    sourcecitation::sourcecitation(const sourcecitation &src) : multinode(src)
    {
    }
    sourcecitation &sourcecitation::operator=(const sourcecitation &src)
    {
        if (this != &src)
        {
            multinode::operator=(src);
        }
        return *this;
    }
    sourcecitation::~sourcecitation()
    {
    }
    string sourcecitation::getSourceRef(void) const
    {
        string s = getValue();
        return stringutils::isPointer(s) ? s : string();
    }
    void sourcecitation::setSourceRef(const string &text)
    {
        string s = stringutils::isPointer(text) ? text : string();
        setValue(s);
    }
    string sourcecitation::getWhereWithinSource(void) const
    {
        return getChildValue(gedconstants::GED_PAGE);
    }
    void sourcecitation::setWhereWithinSource(const string &page)
    {
        setChildValue(gedconstants::GED_PAGE, page);
    }
    string sourcecitation::getEventTypeCitedFrom(void) const
    {
        return getChildValue(gedconstants::GED_EVEN);
    }
    void sourcecitation::setEventTypeCitedFrom(const string &evenTypeCitedFrom)
    {
        setChildValue(gedconstants::GED_EVEN, evenTypeCitedFrom);
    }
    string sourcecitation::getRoleInEvent(void) const
    {
        return getChildValue(gedconstants::GED_EVEN, gedconstants::GED_ROLE);
    }

    void sourcecitation::setRoleInEvent(const string &roleInEvent)
    {
        setChildValue(gedconstants::GED_EVEN, gedconstants::GED_ROLE, roleInEvent);
    }
    string sourcecitation::getRecordingDate(void) const
    {
        return getChildValue(gedconstants::GED_DATA, gedconstants::GED_DATE);
    }
    void sourcecitation::setRecordingDate(const string &recordingDate)
    {
        setChildValue(gedconstants::GED_DATA, gedconstants::GED_DATE, recordingDate);
    }
    string sourcecitation::getTextFromSource(void) const
    {
        return getChildValue(gedconstants::GED_DATA, gedconstants::GED_TEXT, true);
    }
    void sourcecitation::setTextFromSource(const string &text)
    {
        setChildValue(gedconstants::GED_DATA, gedconstants::GED_TEXT, text, true);
    }
    const multimedialink *sourcecitation::findMultiMediaLink(void) const
    {
        return findChildNodeByTag<multimedialink>(gedconstants::GED_OBJE);
    }
    multimedialink *sourcecitation::getMultiMediaLink(void)
    {
        return getChildNodeByTag<multimedialink>(gedconstants::GED_OBJE);
    }
    const notestructure *sourcecitation::findNote(void) const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *sourcecitation::getNote(void)
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    string sourcecitation::getCertaintyAssessment(void) const
    {
        return getChildValue(gedconstants::GED_QUAY);
    }
    void sourcecitation::setCertaintyAssessment(const string &certaintyAssessment)
    {
        setChildValue(gedconstants::GED_QUAY, certaintyAssessment);
    }

    bool sourcecitation::isValid(void) const
    {
        string ref = getSourceRef();
        if (ref.empty())
        {
            return false;
        }
        return multinode::isValid() && getTag() == gedconstants::GED_SOUR;
    }
    void sourcecitation::check(void)
    {
        multinode::check();
        string ref = getSourceRef();
        if (ref.empty())
        {
            if (getStatus() == status::Normal)
            {
                setStatus(status::IncorrectData);
            }
        }
    }
    nodetype sourcecitation::getType(void) const
    {
        return nodetype::SourceCitation;
    }
} // namespace infoged
