#pragma once
#ifndef INDIVIDUALRECORD_H__
#define INDIVIDUALRECORD_H__
///////////////////////////
#include "entitynode.h"
////////////////////////////////
namespace infoged
{
    class personalnamestructure;
    class individualeventstructure;
    class individualattributestructure;
    class ldsindividualordinance;
    class childtofamilylink;
    class spousetofamilylink;
    class associationstructure;
    class notestructure;
    class changedate;
    class sourcecitation;
    class multimedialink;
    /////////////////
    class individualrecord : public entitynode
    {
    public:
        individualrecord(const string &id = string());
        individualrecord(const individualrecord &other);
        individualrecord &operator=(const individualrecord &other);
        virtual ~individualrecord();

    public:
        string getRestrictionNotice(void) const;
        void setRestrictionNotice(const string &notice);
        const personalnamestructure *findPersonalName(void) const;
        personalnamestructure *getPersonalName();
        string getSex(void) const;
        void setSex(const string &sex);
        bool getIndividualEvents(individualeventstructure &events);
        bool getIndividualAttributes(individualattributestructure &attributes);
        bool getIndividualOrdinances(ldsindividualordinance &ordinances);
        const childtofamilylink *findChildToFamilyLink() const;
        childtofamilylink *getChildToFamilyLink();
        bool getSpouseToFamilyLinks(std::list<spousetofamilylink> &links) const;
        bool getSubmitters(stringset &submitters) const;
        void addSubmitter(const string &submitter);
        bool getAssociations(std::list<associationstructure> &associations) const;
        bool getAliases(stringset &aliases) const;
        void addAlias(const string &alias);
        bool getAncistors(stringset &ancestors) const;
        void addAncestor(const string &ancestor);
        bool getDescendants(stringset &descendants) const;
        void addDescendant(const string &descendant);
        string getPermanentRecordFileNumber(void) const;
        void setPermanentRecordFileNumber(const string &fileNumber);
        string getAncestralFileNumber(void) const;
        void setAncestralFileNumber(const string &fileNumber);
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
        notestructure *getNote(void);
        const sourcecitation *findSourceCitation(void) const;
        sourcecitation *getSourceCitation();
        const multimedialink *findMultimediaLink(void) const;
        multimedialink *getMultimediaLink();
        //
    public:
        virtual bool isValid() const override;
        virtual nodetype getType(void) const override;
    };
} // namespace infoged
#endif // INDIVIDUALRECORD_H__