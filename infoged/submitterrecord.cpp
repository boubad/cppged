
#include "submitterrecord.h"
#include "addressstructure.h"
#include "multimedialink.h"
#include "changedate.h"
#include "notestructure.h"
#include "gedconstants.h"
////////////////////////
namespace infoged
{
    submitterrecord::submitterrecord(const string &id) : entitynode(gedconstants::GED_SUBM, id)
    {
    }
    submitterrecord::submitterrecord(const submitterrecord &other) : entitynode(other)
    {
    }
    submitterrecord &submitterrecord::operator=(const submitterrecord &other)
    {
        if (this != &other)
        {
            entitynode::operator=(other);
        }
        return *this;
    }
    submitterrecord::~submitterrecord()
    {
    }
    ////////////////////////////
    string submitterrecord::getSubmitterName() const
    {
        return getChildValue(gedconstants::GED_NAME);
    }
    void submitterrecord::setSubmitterName(const string &name)
    {
        setChildValue(gedconstants::GED_NAME, name);
    }
    const addressstructure *submitterrecord::findAddress() const
    {
        return findChildNodeByTag<addressstructure>(gedconstants::GED_ADDR);
    }
    addressstructure *submitterrecord::getAddress()
    {
        return getChildNodeByTag<addressstructure>(gedconstants::GED_ADDR);
    }
    const multimedialink *submitterrecord::findMultimediaLink() const
    {
        return findChildNodeByTag<multimedialink>(gedconstants::GED_OBJE);
    }
    multimedialink *submitterrecord::getMultimediaLink()
    {
        return getChildNodeByTag<multimedialink>(gedconstants::GED_OBJE);
    }
    string submitterrecord::getLanguagePreference() const
    {
        return getChildValue(gedconstants::GED_LANG);
    }
    void submitterrecord::setLanguagePreference(const string &language)
    {
        setChildValue(gedconstants::GED_LANG, language);
    }
    string submitterrecord::getSubmitterRegisteredRfn(void) const
    {
        return getChildValue(gedconstants::GED_RFN);
    }
    void submitterrecord::setSubmitterRegisteredRfn(const string &rfn)
    {
        setChildValue(gedconstants::GED_RFN, rfn);
    }
    string submitterrecord::getAutomatedRecordId(void) const
    {
        return getChildValue(gedconstants::GED_RIN);
    }
    void submitterrecord::setAutomatedRecordId(const string &automatedRecordId)
    {
        setChildValue(gedconstants::GED_RIN, automatedRecordId);
    }
    const notestructure *submitterrecord::findNote() const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *submitterrecord::getNote()
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }

    const changedate *submitterrecord::findChangedate(void) const
    {
        return findChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }
    changedate *submitterrecord::getChangedate()
    {
        return getChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }

    //////////////////////////
    nodetype submitterrecord::getType(void) const
    {
        return nodetype::Submitter;
    } //
    bool submitterrecord::isValid() const
    {
        if (!entitynode::isValid())
        {
            return false;
        }
        if (getTag() != gedconstants::GED_SUBM)
        {
            return false;
        }
        return true;
    }
    //////////////////////////////
} // namespace infoged