#pragma once
#ifndef FAMILYNODE_H__
#define FAMILYNODE_H__
///////////////////////////
#include "entitynode.h"
//////////////////////
namespace infoged
{
    class familyeventstructure;
    class ldsspousesealing;
    class changedate;
    class sourcecitation;
    class multimedialink;
    class familyrecord : public entitynode
    {
    public:
        familyrecord(const string &id = string());
        familyrecord(const familyrecord &other);
        familyrecord &operator=(const familyrecord &other);
        virtual ~familyrecord();

      public:
        string getResctrictionNotice(void) const;
        void setResctrictionNotice(const string &notice);
        void getFamilyEventStructure(familyeventstructure &fes) const;
        string getHusbandId(void) const;
        void setHusbandId(const string &id);
        string getWifeId(void) const;
        void setWifeId(const string &id);
        bool getChildrenIds(stringset &ids) const;
        bool addChildId(const string &id);
        string getCountOfChildren(void) const;
        void setCountOfChildren(const string &count);
        string getSubmitterId(void) const;
        void setSubmitterId(const string &id);
        const ldsspousesealing *findLdsSpouseSealing() const;
        ldsspousesealing *getLdsSpouseSealing();
        //
        string getUserReferenceNumber(void) const;
        void setUserReferenceNumber(const string &userReferenceNumber);
        string getUserReferenceType(void) const;
        void setUserReferenceType(const string &userReferenceType);
        string getAutomatedRecordId(void) const;
        void setAutomatedRecordId(const string &automatedRecordId);
        const changedate *findChangeDate() const;
        changedate *getChangeDate();
        const sourcecitation *findSourceCitation() const;
        sourcecitation *getSourceCitation();
        bool getMultimediaLinks(stringset &multimedialinks) const;
        multimedialink *addMultimediaLink(const string &xref = string());
        //

    public:
        virtual bool isValid(void) const override;
        virtual nodetype getType(void) const override;
    }; // class FamilyNode
} // namespace infoged
#endif //
