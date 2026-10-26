#pragma once
#ifndef REPOSITORYNODE_H__
#define REPOSITORYNODE_H__
/////////////////////////
#include "entitynode.h"

//////////////////////////////
namespace infoged
{
    class changedate;
    class addressstructure;
    class notestructure;
    class repositoryrecord : public entitynode
    {
    public:
        repositoryrecord(const string &id = string());
        repositoryrecord(const repositoryrecord &other);
        repositoryrecord &operator=(const repositoryrecord &other);
        virtual ~repositoryrecord();

    public:
        string getNameOfRepository(void) const;
        void setNameOfRepository(const string &name);
        const addressstructure *findAddress() const;
        addressstructure *getAddress();
        const notestructure *findNote() const;
        notestructure *getNote();
        string getUserReferenceNumber(void) const;
        void setUserReferenceNumber(const string &userReferenceNumber);
        string getUserReferenceType(void) const;
        void setUserReferenceType(const string &userReferenceType);
        string getAutomatedRecordId(void) const;
        void setAutomatedRecordId(const string &automatedRecordId);
        const changedate *findChangedate(void) const;
        changedate *getChangedate();

    public:
        virtual void check() override;
        virtual bool isValid() const override;
        virtual nodetype getType(void) const override;
    };
} // namespace infoged

#endif // REPOSITORYNODE_H__
