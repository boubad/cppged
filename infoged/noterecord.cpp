
#include "noterecord.h"
#include "sourcecitation.h"
#include "changedate.h"
#include "gedconstants.h"
#include "stringutils.h"
namespace infoged
{

    noterecord::noterecord(const string &id, const string &svalue) : entitynode(gedconstants::GED_NOTE, id)
    {
        string sval = stringutils::trim(svalue);
        if (!sval.empty())
        {
            setSubmitterText(sval);
        }
    }

    noterecord::noterecord(const noterecord &other) : entitynode(other)
    {
    }
    noterecord &noterecord::operator=(const noterecord &other)
    {
        if (this != &other)
        {
            entitynode::operator=(other);
        }
        return *this;
    }
    noterecord::~noterecord()
    {
    }

    string noterecord::getSubmitterText(void) const
    {
        return getMultiLinesValue();
    }
    void noterecord::setSubmitterText(const string &suubmitterText)
    {
        setMultiLinesValue(suubmitterText);
    }
    string noterecord::getUserReferenceNumber(void) const
    {
        return getChildValue(gedconstants::GED_REFN);
    }
    void noterecord::setUserReferenceNumber(const string &userReferenceNumber)
    {
        setChildValue(gedconstants::GED_REFN, userReferenceNumber);
    }

    string noterecord::getUserReferenceType(void) const
    {
        return getChildValue(gedconstants::GED_REFN, gedconstants::GED_TYPE);
    }
    void noterecord::setUserReferenceType(const string &userReferenceType)
    {
        setChildValue(gedconstants::GED_REFN, gedconstants::GED_TYPE, userReferenceType);
    }
    string noterecord::getAutomatedRecordId(void) const
    {
        return getChildValue(gedconstants::GED_RIN);
    }
    void noterecord::setAutomatedRecordId(const string &automatedRecordId)
    {
        setChildValue(gedconstants::GED_RIN, automatedRecordId);
    }
    const sourcecitation *noterecord::findSourceCitation(void) const
    {
        return findChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    sourcecitation *noterecord::getSourceCitation()
    {
        return getChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    const changedate *noterecord::findChangedate(void) const
    {
        return findChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }
    changedate *noterecord::getChangedate()
    {
        return getChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }
    ///////////////////////////////
    nodetype noterecord::getType(void) const
    {
        return nodetype::Note;
    }
    bool noterecord::isValid() const
    {
        if (!entitynode::isValid())
        {
            return false;
        }
        if (getTag() != gedconstants::GED_NOTE)
        {
            return false;
        }
        return true;
    }
    //////////////////////////////
} // namespace infoged