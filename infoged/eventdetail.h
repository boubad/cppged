#pragma once
#ifndef EVENTDETAILSTRUCT_H__
#define EVENTDETAILSTRUCT_H__
///////////////////////
#include "proxynode.h"
/////////////////////////
namespace infoged
{
    class place;
    class addressstructure;
    class notestructure;
    class sourcecitation;
    class multimedialink;
    ///////////////////////
    class eventdetail : public proxynode
    {
    public:
        eventdetail(multinode *proxy = nullptr);
        eventdetail(const eventdetail &other);
        eventdetail &operator=(const eventdetail &other);
        virtual ~eventdetail();

    public:
        string getEventOrFactClassification(void) const;
        void setEventOrFactClassification(const string &eventorfact);
        string getDate(void) const;
        void setDate(const string &date);
        const place *findPlace(void) const;
        place *getPlace(void);
        const addressstructure *findAddress() const;
        addressstructure *getAddress(void);
        string getAgency(void) const;
        void setAgency(const string &agency);
        string getReligiousAffiliation(void) const;
        void setReligiousAffiliation(const string &religiousaffiliation);
        string getCauseOfEvent(void) const;
        void setCauseOfEvent(const string &causeofevent);
        string getRestrictionNotice(void) const;
        void setRestrictionNotice(const string &restrictionnotice);
        const notestructure *findNote(void) const;
        notestructure *getNote(void);
        const sourcecitation *findSourceCitation(void) const;
        sourcecitation *getSourceCitation(void);
        bool getMultimediaLinks(stringset &multimedialinks) const;
        void addMultimediaLink(const string &multimedialink);
    };
} // namespace infoged
#endif // EVENTDETAILSTRUCT_H__
