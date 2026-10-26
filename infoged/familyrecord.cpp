
#include "familyrecord.h"
///////////////////////////
#include "familyeventstructure.h"
#include "ldsspousesealing.h"
#include "changedate.h"
#include "sourcecitation.h"
#include "multimedialink.h"
#include "gedconstants.h"
#include "stringutils.h"
///////////////////////////
namespace infoged
{
    familyrecord::familyrecord(const string &id) : entitynode(gedconstants::GED_FAM, id)
    {
    }

    familyrecord::familyrecord(const familyrecord &other) : entitynode(other)
    {
    }

    familyrecord &familyrecord::operator=(const familyrecord &other)
    {
        if (this != &other)
        {
            entitynode::operator=(other);
        }
        return *this;
    }

    familyrecord::~familyrecord()
    {
    }
    ////////////////////////////
    string familyrecord::getResctrictionNotice(void) const
    {
        return getChildValue(gedconstants::GED_RESN);
    }
    void familyrecord::setResctrictionNotice(const string &notice)
    {
        setChildValue(gedconstants::GED_RESN, notice);
    }
    void familyrecord::getFamilyEventStructure(familyeventstructure &fes) const
    {
        multinode *pcur = const_cast<familyrecord *>(this);
        fes = familyeventstructure(pcur);
    }
    string familyrecord::getHusbandId(void) const
    {
        return getChildValue(gedconstants::GED_HUSB);
    }
    void familyrecord::setHusbandId(const string &id)
    {
        setChildValue(gedconstants::GED_HUSB, id);
    }
    string familyrecord::getWifeId(void) const
    {
        return getChildValue(gedconstants::GED_WIFE);
    }
    void familyrecord::setWifeId(const string &id)
    {
        setChildValue(gedconstants::GED_WIFE, id);
    }
    bool familyrecord::getChildrenIds(stringset &ids) const
    {
        ids.clear();
        const auto &children = getChildren();
        for (const auto &p : children)
        {
            if (p->getTag() == gedconstants::GED_CHIL)
            {
                string sid = stringutils::trim(p->getValue());
                if (stringutils::isPointer(sid))
                {
                    ids.insert(sid);
                }
            }
        }
        return !ids.empty();
    }
    bool familyrecord::addChildId(const string &id)
    {
        string sid = stringutils::trim(id);
        if (stringutils::isPointer(sid))
        {
            node *child = getChild(gedconstants::GED_CHIL, id);
            return (child != nullptr);
        }
        return false;
    }
    string familyrecord::getCountOfChildren(void) const
    {
        return getChildValue(gedconstants::GED_NCHI);
    }
    void familyrecord::setCountOfChildren(const string &count)
    {
        setChildValue(gedconstants::GED_NCHI, count);
    }
    string familyrecord::getSubmitterId(void) const
    {
        return getChildValue(gedconstants::GED_SUBM);
    }
    void familyrecord::setSubmitterId(const string &id)
    {
        setChildValue(gedconstants::GED_SUBM, id);
    }
    const ldsspousesealing *familyrecord::findLdsSpouseSealing() const
    {
        return findChildNodeByTag<ldsspousesealing>(gedconstants::GED_SLGC);
    }
    ldsspousesealing *familyrecord::getLdsSpouseSealing()
    {
        return getChildNodeByTag<ldsspousesealing>(gedconstants::GED_SLGC);
    }
    //////////////////////////////
    string familyrecord::getUserReferenceNumber(void) const
    {
        return getChildValue(gedconstants::GED_REFN);
    }
    void familyrecord::setUserReferenceNumber(const string &userReferenceNumber)
    {
        setChildValue(gedconstants::GED_REFN, userReferenceNumber);
    }
    string familyrecord::getUserReferenceType(void) const
    {
        return getChildValue(gedconstants::GED_REFN, gedconstants::GED_TYPE);
    }
    void familyrecord::setUserReferenceType(const string &userReferenceType)
    {
        setChildValue(gedconstants::GED_REFN, gedconstants::GED_TYPE, userReferenceType);
    }
    string familyrecord::getAutomatedRecordId(void) const
    {
        return getChildValue(gedconstants::GED_RIN);
    }
    void familyrecord::setAutomatedRecordId(const string &automatedRecordId)
    {
        setChildValue(gedconstants::GED_RIN, automatedRecordId);
    }
    const changedate *familyrecord::findChangeDate() const
    {
        return findChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }
    changedate *familyrecord::getChangeDate()
    {
        return getChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }
    const sourcecitation *familyrecord::findSourceCitation() const
    {
        return findChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    sourcecitation *familyrecord::getSourceCitation()
    {
        return getChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    bool familyrecord::getMultimediaLinks(stringset &multimedialinks) const
    {
        return getAllStringValues(gedconstants::GED_OBJE, multimedialinks);
    }
    multimedialink *familyrecord::addMultimediaLink(const string &xref)
    {
        node *node = getChild(gedconstants::GED_OBJE, xref);
        return dynamic_cast<multimedialink *>(node);
    }
    /////////////////////////////
    bool familyrecord::isValid(void) const
    {
        if (!entitynode::isValid() || getTag() != gedconstants::GED_FAM)
        {
            return false;
        }
        return true;
    }
    nodetype familyrecord::getType(void) const
    {
        return nodetype::Family;
    }

    ///////////////////////////
} // namespace infoged