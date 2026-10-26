
#include "sourcerecord.h"
/////////////////////////
#include "sourcerepositorycitation.h"
#include "changedate.h"
#include "notestructure.h"
#include "multimedialink.h"
#include "gedconstants.h"
/////////////////////////////
#include <cassert>
/////////////////////////
namespace infoged
{
    sourcerecord::sourcerecord(const string &id) : entitynode(gedconstants::GED_SOUR, id)
    {
    }

    sourcerecord::sourcerecord(const sourcerecord &other) : entitynode(other)
    {
    }
    sourcerecord &sourcerecord::operator=(const sourcerecord &other)
    {
        if (this != &other)
        {
            entitynode::operator=(other);
        }
        return *this;
    }
    sourcerecord::~sourcerecord()
    {
    }
    ////////////////////////////////////////
    string sourcerecord::getEventsRecorded(void) const
    {
        return getChildValue(gedconstants::GED_DATA, gedconstants::GED_EVEN);
    }
    void sourcerecord::setEventsRecorded(const string &eventsrecorded)
    {
        setChildValue(gedconstants::GED_DATA, gedconstants::GED_EVEN, eventsrecorded);
    }
    string sourcerecord::getDatePeriod(void) const
    {
        return getChildValue(gedconstants::GED_DATA, gedconstants::GED_EVEN, gedconstants::GED_DATE);
    }
    void sourcerecord::setDatePeriod(const string &dateperiod)
    {
        setChildValue(gedconstants::GED_DATA, gedconstants::GED_EVEN, gedconstants::GED_DATE, dateperiod);
    }
    string sourcerecord::getJurisdictionPlace(void) const
    {
        return getChildValue(gedconstants::GED_DATA, gedconstants::GED_EVEN, gedconstants::GED_PLAC);
    }
    void sourcerecord::setJurisdictionPlace(const string &jurisdictionplace)
    {
        setChildValue(gedconstants::GED_DATA, gedconstants::GED_EVEN, gedconstants::GED_PLAC, jurisdictionplace);
    }
    string sourcerecord::getResponsibleAgency(void) const
    {
        return getChildValue(gedconstants::GED_DATA, gedconstants::GED_AGNC);
    }
    void sourcerecord::setResponsibleAgency(const string &responsibleagency)
    {
        setChildValue(gedconstants::GED_DATA, gedconstants::GED_AGNC, responsibleagency);
    }

    const notestructure *sourcerecord::findDataNote() const
    {
        const node *pData0 = findChild(gedconstants::GED_DATA);
        if (pData0 != nullptr)
        {
            const multinode *pData = dynamic_cast<const multinode *>(pData0);
            if (pData != nullptr)
            {
                return pData->findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
            }
        }
        return nullptr;
    }
    notestructure *sourcerecord::getDataNote()
    {
        node *pData0 = getChild(gedconstants::GED_DATA);
        if (pData0 != nullptr)
        {
            multinode *pData = dynamic_cast<multinode *>(pData0);
            if (pData != nullptr)
            {
                return pData->getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
            }
        }
        return nullptr;
    }
    string sourcerecord::getSourceOriginators() const
    {
        const node *p0 = findChild(gedconstants::GED_AUTH);
        if (p0 != nullptr)
        {
            const multinode *p = dynamic_cast<const multinode *>(p0);
            if (p != nullptr)
            {
                return p->getMultiLinesValue();
            }
        }
        return string();
    }
    void sourcerecord::setSourceOriginator(const string &sourceoriginator)
    {
        node *p0 = getChild(gedconstants::GED_AUTH);
        if (p0 != nullptr)
        {
            multinode *p = dynamic_cast<multinode *>(p0);
            if (p != nullptr)
            {
                p->setMultiLinesValue(sourceoriginator);
            }
        }
    }
    string sourcerecord::getSourceDescriptiveTitles() const
    {
        const node *p0 = findChild(gedconstants::GED_TITL);
        if (p0 != nullptr)
        {
            const multinode *p = dynamic_cast<const multinode *>(p0);
            if (p != nullptr)
            {
                return p->getMultiLinesValue();
            }
        }
        return string();
    }
    void sourcerecord::setSourceDescriptiveTitle(const string &title)
    {
        node *p0 = getChild(gedconstants::GED_TITL);
        if (p0 != nullptr)
        {
            multinode *p = dynamic_cast<multinode *>(p0);
            if (p != nullptr)
            {
                p->setMultiLinesValue(title);
            }
        }
    }

    string sourcerecord::getSourceFiledByEntry(void) const
    {
        return getChildValue(gedconstants::GED_ABBR);
    }
    void sourcerecord::setSourceFiledByEntry(const string &sourcefiledbyentry)
    {
        setChildValue(gedconstants::GED_ABBR, sourcefiledbyentry);
    }
    string sourcerecord::getSourcePublicationFacts() const
    {
        const node *p0 = findChild(gedconstants::GED_PUBL);
        if (p0 != nullptr)
        {
            const multinode *p = dynamic_cast<const multinode *>(p0);
            if (p != nullptr)
            {
                return p->getMultiLinesValue();
            }
        }
        return string();
    }
    void sourcerecord::setSourcePublicationFact(const string &fact)
    {
        node *p0 = getChild(gedconstants::GED_PUBL);
        if (p0 != nullptr)
        {
            multinode *p = dynamic_cast<multinode *>(p0);
            if (p != nullptr)
            {
                p->setMultiLinesValue(fact);
            }
        }
    }
    string sourcerecord::getSourceTexts() const
    {
        const node *p0 = findChild(gedconstants::GED_TEXT);
        if (p0 != nullptr)
        {
            const multinode *p = dynamic_cast<const multinode *>(p0);
            if (p != nullptr)
            {
                return p->getMultiLinesValue();
            }
        }
        return string();
    }
    void sourcerecord::setSourceText(const string &text)
    {
        node *p0 = getChild(gedconstants::GED_TEXT);
        if (p0 != nullptr)
        {
            multinode *p = dynamic_cast<multinode *>(p0);
            if (p != nullptr)
            {
                p->setMultiLinesValue(text);
            }
        }
    }

    const sourcerepositorycitation *sourcerecord::findSourceRepositoryCitation() const
    {
        return findChildNodeByTag<sourcerepositorycitation>(gedconstants::GED_REPO);
    }
    sourcerepositorycitation *sourcerecord::getSourceRepositoryCitation()
    {
        return getChildNodeByTag<sourcerepositorycitation>(gedconstants::GED_REPO);
    }
    const notestructure *sourcerecord::findNote() const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *sourcerecord::getNote()
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    string sourcerecord::getUserReferenceNumber(void) const
    {
        return getChildValue(gedconstants::GED_REFN);
    }
    void sourcerecord::setUserReferenceNumber(const string &userReferenceNumber)
    {
        setChildValue(gedconstants::GED_REFN, userReferenceNumber);
    }
    string sourcerecord::getUserReferenceType(void) const
    {
        return getChildValue(gedconstants::GED_REFN, gedconstants::GED_TYPE);
    }
    void sourcerecord::setUserReferenceType(const string &userReferenceType)
    {
        setChildValue(gedconstants::GED_REFN, gedconstants::GED_TYPE, userReferenceType);
    }
    string sourcerecord::getAutomatedRecordId(void) const
    {
        return getChildValue(gedconstants::GED_RIN);
    }
    void sourcerecord::setAutomatedRecordId(const string &automatedRecordId)
    {
        setChildValue(gedconstants::GED_RIN, automatedRecordId);
    }
    const changedate *sourcerecord::findChangedate(void) const
    {
        return findChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }

    changedate *sourcerecord::getChangedate()
    {
        return getChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }
    bool sourcerecord::getMultimediaLinks(stringset &multimedialinks) const
    {
        return getAllStringValues(gedconstants::GED_OBJE, multimedialinks);
    }
    multimedialink *sourcerecord::addMultimediaLink(const string &mediaReference)
    {
        node *p = getChild(gedconstants::GED_OBJE, mediaReference);
        return dynamic_cast<multimedialink *>(p);
    }
    /////////////////////////////////////////////
    nodetype sourcerecord::getType(void) const
    {
        return nodetype::Source;
    }
    bool sourcerecord::isValid(void) const
    {
        if (!entitynode::isValid())
        {
            return false;
        }
        if (getTag() != gedconstants::GED_SOUR)
        {
            return false;
        }
        return true;
    }
    ////////////////////////////////////////////
} // namespace infoged