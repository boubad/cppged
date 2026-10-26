#pragma once
#ifndef NOTEENTITYNODE_H__
#define NOTEENTITYNODE_H__
/////////////////////
#include "entitynode.h"
///////////////////////////
namespace infoged
{
    class sourcecitation;
    class changedate;
    class noterecord : public entitynode
    {
    public:
        noterecord(const string &id = string(), const string &svalue = string());
        noterecord(const noterecord &other);
        noterecord &operator=(const noterecord &other);
        virtual ~noterecord();

    public:
        string getSubmitterText(void) const;
        void setSubmitterText(const string &suubmitterText);
        string getUserReferenceNumber(void) const;
        void setUserReferenceNumber(const string &userReferenceNumber);
        string getUserReferenceType(void) const;
        void setUserReferenceType(const string &userReferenceType);
        string getAutomatedRecordId(void) const;
        void setAutomatedRecordId(const string &automatedRecordId);
        const sourcecitation *findSourceCitation(void) const;
        sourcecitation *getSourceCitation();
        const changedate *findChangedate(void) const;
        changedate *getChangedate();

    public:
        virtual bool isValid() const override;
        virtual nodetype getType(void) const override;
    };
} // namespace infoged
#endif // NOTEENTITYNODE_H__