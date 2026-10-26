#pragma once
#ifndef SOURCENODE_H__
#define SOURCENODE_H__
///////////////////////////
#include "entitynode.h"
////////////////////////////////
namespace infoged
{
    class sourcerepositorycitation;
    class addressstructure;
    class multimedialink;
    class changedate;
    class notestructure;
    class sourcerecord : public entitynode
    {
    public:
        sourcerecord(const string &id = string());
        sourcerecord(const sourcerecord &other);
        sourcerecord &operator=(const sourcerecord &other);
        virtual ~sourcerecord();

    public:
        string getEventsRecorded(void) const;
        void setEventsRecorded(const string &eventsrecorded);
        string getDatePeriod(void) const;
        void setDatePeriod(const string &dateperiod);
        string getJurisdictionPlace(void) const;
        void setJurisdictionPlace(const string &jurisdiction);
        string getResponsibleAgency(void) const;
        void setResponsibleAgency(const string &responsibleagency);
        const notestructure *findDataNote() const;
        notestructure *getDataNote();
        string getSourceOriginators(void) const;
        void setSourceOriginator(const string &sourceoriginator);
        string getSourceDescriptiveTitles(void) const;
        void setSourceDescriptiveTitle(const string &title);
        string getSourceFiledByEntry(void) const;
        void setSourceFiledByEntry(const string &sourcefiledbyentry);
        string getSourcePublicationFacts(void) const;
        void setSourcePublicationFact(const string &fact);
        string getSourceTexts() const;
        void setSourceText(const string &text);
        const sourcerepositorycitation *findSourceRepositoryCitation(void) const;
        sourcerepositorycitation *getSourceRepositoryCitation();
        //
        string getUserReferenceNumber(void) const;
        void setUserReferenceNumber(const string &userReferenceNumber);
        string getUserReferenceType(void) const;
        void setUserReferenceType(const string &userReferenceType);
        string getAutomatedRecordId(void) const;
        void setAutomatedRecordId(const string &automatedRecordId);
        const changedate *findChangedate(void) const;
        changedate *getChangedate();
        const notestructure *findNote() const;
        notestructure *getNote();
        bool getMultimediaLinks(stringset &multimedialinks) const;
        multimedialink *addMultimediaLink(const string &mediaReference);

    public:
        virtual bool isValid() const override;
        virtual nodetype getType(void) const override;
    };
} // namespace infoged
#endif // SOURCE_RECORD_H__
