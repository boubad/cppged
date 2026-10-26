#pragma once
#ifndef SUBMITTERNODE_H__
#define SUBMITTERNODE_H__
///////////////////////////
#include "entitynode.h"
///////////////////////////
namespace infoged
{
    class addressstructure;
    class multimedialink;
    class notestructure;
    class changedate;
    class submitterrecord : public entitynode
    {
    public:
        submitterrecord(const string &id = string());
        submitterrecord(const submitterrecord &other);
        submitterrecord &operator=(const submitterrecord &other);
        virtual ~submitterrecord();

    public:
        string getSubmitterName() const;
        void setSubmitterName(const string &name);
        const addressstructure *findAddress() const;
        addressstructure *getAddress();
        const multimedialink *findMultimediaLink() const;
        multimedialink *getMultimediaLink();
        string getLanguagePreference(void) const;
        void setLanguagePreference(const string &languagepreference);
        string getSubmitterRegisteredRfn(void) const;
        void setSubmitterRegisteredRfn(const string &rfn);
        string getAutomatedRecordId(void) const;
        void setAutomatedRecordId(const string &automatedRecordId);
        const notestructure *findNote() const;
        notestructure *getNote();
        const changedate *findChangedate(void) const;
        changedate *getChangedate();

    public:
        virtual bool isValid() const override;
        virtual nodetype getType(void) const override;
    };
} // namespace infoged
#endif // SUBMITTERNODE_H__
