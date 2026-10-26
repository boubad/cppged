#pragma once
#ifndef NOTENODE_H__
#define NOTENODE_H__
/////////////////////////////
#include "multinode.h"
//////////////////////////////
namespace infoged
{
    class notestructure : public multinode
    {
    public:
        notestructure(int level = -1, const string &value = string());
        notestructure(const notestructure &other);
        notestructure &operator=(const notestructure &other);
        virtual ~notestructure();


    public:
        string getNoteReference(void) const;
        void setNoteReference(const string &noteRefrence);
        string getSubmitterText(void) const;
        void setSubmitterText(const string &suubmitterText);

    public:
        virtual void check(void) override;
        virtual nodetype getType(void) const override;
        virtual bool isValid(void) const override;
    }; //
} // namespace infoged
#endif // NOTENODE_H__