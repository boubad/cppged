
#include "individualrecord.h"
///////////////////////////////
#include "personalnamestructure.h"
#include "individualeventstructure.h"
#include "individualattributestructure.h"
#include "ldsindividualordinance.h"
#include "childtofamilylink.h"
#include "spousetofamily.h"
#include "associationstructure.h"
#include "notestructure.h"
#include "changedate.h"
#include "sourcecitation.h"
#include "multimedialink.h"
#include "gedconstants.h"
#include "stringutils.h"
////////////////////////
namespace infoged
{
    individualrecord::individualrecord(const string &id) : entitynode(gedconstants::GED_INDI, id)
    {
    }

    individualrecord::individualrecord(const individualrecord &other) : entitynode(other)
    {
    }

    individualrecord &individualrecord::operator=(const individualrecord &other)
    {
        if (this != &other)
        {
            entitynode::operator=(other);
        }
        return *this;
    }
    individualrecord::~individualrecord()
    {
    }
    ////////////////////////////////
    string individualrecord::getRestrictionNotice(void) const
    {
        return getChildValue(gedconstants::GED_RESN);
    }
    void individualrecord::setRestrictionNotice(const string &notice)
    {
        setChildValue(gedconstants::GED_RESN, notice);
    }
    const personalnamestructure *individualrecord::findPersonalName(void) const
    {
        return findChildNodeByTag<personalnamestructure>(gedconstants::GED_NAME);
    }
    personalnamestructure *individualrecord::getPersonalName()
    {
        return getChildNodeByTag<personalnamestructure>(gedconstants::GED_NAME);
    }
    bool individualrecord::getIndividualEvents(individualeventstructure &events)
    {
        events = individualeventstructure(this);
        return true;
    }
    bool individualrecord::getIndividualAttributes(individualattributestructure &attributes)
    {
        attributes = individualattributestructure(this);
        return true;
    }
    bool individualrecord::getIndividualOrdinances(ldsindividualordinance &ordinances)
    {
        ordinances = ldsindividualordinance(this);
        return true;
    }
    string individualrecord::getSex(void) const
    {
        return getChildValue(gedconstants::GED_SEX);
    }
    void individualrecord::setSex(const string &sex)
    {
        setChildValue(gedconstants::GED_SEX, sex);
    }
    const childtofamilylink *individualrecord::findChildToFamilyLink() const
    {
        return findChildNodeByTag<childtofamilylink>(gedconstants::GED_FAMC);
    }
    childtofamilylink *individualrecord::getChildToFamilyLink()
    {
        return getChildNodeByTag<childtofamilylink>(gedconstants::GED_FAMC);
    }
    bool individualrecord::getSpouseToFamilyLinks(std::list<spousetofamilylink> &links) const
    {
        return getAllNodes<spousetofamilylink>(links);
    }
    bool individualrecord::getSubmitters(stringset &submitters) const
    {
        return getAllStringValues(gedconstants::GED_SUBM, submitters);
    }
    void individualrecord::addSubmitter(const string &submitter)
    {
        string s = stringutils::trim(submitter);
        if (stringutils::isPointer(s))
        {
            getChild(gedconstants::GED_SUBM, s);
        } // valid
    }
    bool individualrecord::getAssociations(std::list<associationstructure> &associations) const
    {
        return getAllNodes<associationstructure>(associations);
    }
    bool individualrecord::getAliases(stringset &aliases) const
    {
        return getAllStringValues(gedconstants::GED_ALIA, aliases);
    }
    void individualrecord::addAlias(const string &alias)
    {
        string sval = stringutils::trim(alias);
        if (sval.empty())
        {
            return;
        }
        getChild(gedconstants::GED_ALIA, sval);
    }
    bool individualrecord::getAncistors(stringset &ancestors) const
    {
        return getAllStringValues(gedconstants::GED_ANCI, ancestors);
    }
    void individualrecord::addAncestor(const string &ancestor)
    {
        string sval = stringutils::trim(ancestor);
        if (sval.empty())
        {
            return;
        }
        getChild(gedconstants::GED_ANCI, sval);
    }
    bool individualrecord::getDescendants(stringset &descendants) const
    {
        return getAllStringValues(gedconstants::GED_DESI, descendants);
    }
    void individualrecord::addDescendant(const string &descendant)
    {
        string sval = stringutils::trim(descendant);
        if (sval.empty())
        {
            return;
        }
        getChild(gedconstants::GED_DESI, sval);
    }
    string individualrecord::getPermanentRecordFileNumber(void) const
    {
        return getChildValue(gedconstants::GED_RFN);
    }
    void individualrecord::setPermanentRecordFileNumber(const string &refn)
    {
        setChildValue(gedconstants::GED_RFN, refn);
    }
    string individualrecord::getAncestralFileNumber(void) const
    {
        return getChildValue(gedconstants::GED_AFN);
    }
    void individualrecord::setAncestralFileNumber(const string &refn)
    {
        setChildValue(gedconstants::GED_AFN, refn);
    }

    ////////////////////////////////////
    string individualrecord::getUserReferenceNumber(void) const
    {
        return getChildValue(gedconstants::GED_REFN);
    }
    void individualrecord::setUserReferenceNumber(const string &userReferenceNumber)
    {
        setChildValue(gedconstants::GED_REFN, userReferenceNumber);
    }
    string individualrecord::getUserReferenceType(void) const
    {
        return getChildValue(gedconstants::GED_REFN, gedconstants::GED_TYPE);
    }
    void individualrecord::setUserReferenceType(const string &userReferenceType)
    {
        setChildValue(gedconstants::GED_REFN, gedconstants::GED_TYPE, userReferenceType);
    }
    string individualrecord::getAutomatedRecordId(void) const
    {
        return getChildValue(gedconstants::GED_RIN);
    }
    void individualrecord::setAutomatedRecordId(const string &automatedRecordId)
    {
        setChildValue(gedconstants::GED_RIN, automatedRecordId);
    }
    const changedate *individualrecord::findChangedate(void) const
    {
        return findChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }

    changedate *individualrecord::getChangedate()
    {
        return getChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }
    const notestructure *individualrecord::findNote() const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *individualrecord::getNote(void)
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    const multimedialink *individualrecord::findMultimediaLink(void) const
    {
        return findChildNodeByTag<multimedialink>(gedconstants::GED_OBJE);
    }

    multimedialink *individualrecord::getMultimediaLink()
    {
        return getChildNodeByTag<multimedialink>(gedconstants::GED_OBJE);
    }
    /////////////////////////////////
    bool individualrecord::isValid(void) const
    {
        if (!multinode::isValid())
        {
            return false;
        }
        if (getTag() != gedconstants::GED_INDI)
        {
            return false;
        }
        return true;
    }
    nodetype individualrecord::getType(void) const
    {
        return nodetype::Individual;
    }
    ////////////////////////////////////
} // namespace infoged