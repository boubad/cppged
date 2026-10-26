
#include "eventdetail.h"
////////////////////////////
#include "place.h"
#include "addressstructure.h"
#include "sourcecitation.h"
#include "notestructure.h"
#include "gedconstants.h"
//////////////////////////////
namespace infoged
{
    eventdetail::eventdetail(multinode *proxy) : proxynode(proxy)
    {
    }
    eventdetail::eventdetail(const eventdetail &other) : proxynode(other)
    {
    }
    eventdetail &eventdetail::operator=(const eventdetail &other)
    {
        if (this != &other)
        {
            proxynode::operator=(other);
        }
        return *this;
    }
    eventdetail::~eventdetail()
    {
    }
    ////////////////////////
    string eventdetail::getEventOrFactClassification(void) const
    {
        return getChildValue(gedconstants::GED_TYPE);
    }
    void eventdetail::setEventOrFactClassification(const string &eventorfact)
    {
        setChildValue(gedconstants::GED_TYPE, eventorfact);
    }
    string eventdetail::getDate() const
    {
        return getChildValue(gedconstants::GED_DATE);
    }
    void eventdetail::setDate(const string &date)
    {
        setChildValue(gedconstants::GED_DATE, date);
    }
    const place *eventdetail::findPlace() const
    {
        return getProxy()->findChildNodeByTag<place>(gedconstants::GED_PLAC);
    }
    place *eventdetail::getPlace(void)
    {
        return getProxy()->getChildNodeByTag<place>(gedconstants::GED_PLAC);
    }
    const addressstructure *eventdetail::findAddress() const
    {
        return getProxy()->findChildNodeByTag<addressstructure>(gedconstants::GED_ADDR);
    }
    addressstructure *eventdetail::getAddress(void)
    {
        return getProxy()->getChildNodeByTag<addressstructure>(gedconstants::GED_ADDR);
    }
    string eventdetail::getAgency(void) const
    {
        return getChildValue(gedconstants::GED_AGNC);
    }
    void eventdetail::setAgency(const string &agency)
    {
        setChildValue(gedconstants::GED_AGNC, agency);
    }
    string eventdetail::getReligiousAffiliation(void) const
    {
        return getChildValue(gedconstants::GED_RELI);
    }
    void eventdetail::setReligiousAffiliation(const string &religiousaffiliation)
    {
        setChildValue(gedconstants::GED_RELI, religiousaffiliation);
    }
    string eventdetail::getCauseOfEvent(void) const
    {
        return getChildValue(gedconstants::GED_CAUS);
    }
    void eventdetail::setCauseOfEvent(const string &causeofevent)
    {
        setChildValue(gedconstants::GED_CAUS, causeofevent);
    }
    string eventdetail::getRestrictionNotice(void) const
    {
        return getChildValue(gedconstants::GED_RESN);
    }
    void eventdetail::setRestrictionNotice(const string &restrictionnotice)
    {
        setChildValue(gedconstants::GED_RESN, restrictionnotice);
    }
    const notestructure *eventdetail::findNote() const
    {
        return getProxy()->findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *eventdetail::getNote(void)
    {
        return getProxy()->getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    const sourcecitation *eventdetail::findSourceCitation() const
    {
        return getProxy()->findChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    sourcecitation *eventdetail::getSourceCitation(void)
    {
        return getProxy()->getChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    bool eventdetail::getMultimediaLinks(stringset &multimedialinks) const
    {
        return getAllStringValues(gedconstants::GED_OBJE, multimedialinks);
    }
    void eventdetail::addMultimediaLink(const string &multimedialink)
    {
        getProxy()->getChild(gedconstants::GED_OBJE, multimedialink);
    }
    //////////////////////////
} // namespace infoged
