#pragma once
#ifndef SUBMISSIONNODE_H__
#define SUBMISSIONNODE_H__
//////////////////////////
#include "entitynode.h"
///////////////////////////
namespace infoged
{
    class notestructure;
    class changedate;
    class submissionrecord : public entitynode
    {
    public:
        submissionrecord(const string &id = string());
        submissionrecord(const submissionrecord &other);
        submissionrecord &operator=(const submissionrecord &other);
        virtual ~submissionrecord();

    public:
        string getSubmitterId(void) const;
        void setSubmitterId(const string &id);
        string getNameOfFamilyFile(void) const;
        void setNameOfFamilyFile(const string &name);
        string getTempleCode(void) const;
        void setTempleCode(const string &code);
        string getAncestorsGenerations(void) const;
        void setAncestorsGenerations(const string &generations);
        string getDescendantsGenerations(void) const;
        void setDescendantsGenerations(const string &generations);
        string getOrdinanceProcessFlag(void) const;
        void setOrdinanceProcessFlag(const string &flag);
        const notestructure *findNote() const;
        notestructure *getNote();
        const changedate *findChangedate(void) const;
        changedate *getChangedate();

    public:
        virtual bool isValid() const override;
        virtual nodetype getType(void) const override;
    };
} // namespace infoged
#endif // SUBMISSIONNODE_H__