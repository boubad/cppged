
#include "submissionrecord.h"
#include "notestructure.h"
#include "changedate.h"
#include "gedconstants.h"
namespace infoged
{
    submissionrecord::submissionrecord(const string &id) : entitynode(gedconstants::GED_SUBN,id)
    {
    }
    submissionrecord::submissionrecord(const submissionrecord &other) : entitynode(other)
    {
    }
    submissionrecord &submissionrecord::operator=(const submissionrecord &other)
    {
        if (this != &other)
        {
            entitynode::operator=(other);
        }
        return *this;
    }
    submissionrecord::~submissionrecord()
    {
    }
    ////////////////////////////
    string submissionrecord::getSubmitterId(void) const
    {
        return getChildValue(gedconstants::GED_SUBM);
    }
    void submissionrecord::setSubmitterId(const string &id)
    {
        setChildValue(gedconstants::GED_SUBM, id);
    }
    string submissionrecord::getNameOfFamilyFile(void) const
    {
        return getChildValue(gedconstants::GED_FAMF);
    }
    void submissionrecord::setNameOfFamilyFile(const string &name)
    {
        setChildValue(gedconstants::GED_FAMF, name);
    }
    string submissionrecord::getTempleCode(void) const
    {
        return getChildValue(gedconstants::GED_TEMP);
    }
    void submissionrecord::setTempleCode(const string &code)
    {
        setChildValue(gedconstants::GED_TEMP, code);
    }
    string submissionrecord::getAncestorsGenerations(void) const
    {
        return getChildValue(gedconstants::GED_ANCE);
    }
    void submissionrecord::setAncestorsGenerations(const string &generations)
    {
        setChildValue(gedconstants::GED_ANCE, generations);
    }
    string submissionrecord::getDescendantsGenerations(void) const
    {
        return getChildValue(gedconstants::GED_DESC);
    }
    void submissionrecord::setDescendantsGenerations(const string &generations)
    {
        setChildValue(gedconstants::GED_DESC, generations);
    }
    string submissionrecord::getOrdinanceProcessFlag(void) const
    {
        return getChildValue(gedconstants::GED_ORDI);
    }
    void submissionrecord::setOrdinanceProcessFlag(const string &flag)
    {
        setChildValue(gedconstants::GED_ORDI, flag);
    }
    const notestructure *submissionrecord::findNote() const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *submissionrecord::getNote()
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    const changedate *submissionrecord::findChangedate(void) const
    {
        return findChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }
    changedate *submissionrecord::getChangedate()
    {
        return getChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }
    ///////////////////////////
    nodetype submissionrecord::getType(void) const
    {
        return nodetype::Submission;
    }
    bool submissionrecord::isValid() const
    {
        if (!entitynode::isValid())
        {
            return false;
        }
        return getTag() == gedconstants::GED_SUBN;
    }
    ////////////////////////////

} // namespace infoged