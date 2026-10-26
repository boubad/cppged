#pragma once
#ifndef CHILFDTOFAMILYLINKNODE_H__
#define CHILFDTOFAMILYLINKNODE_H__
//////////////////////////////
#include "multinode.h"
///////////////////////////////
namespace infoged
{
    class notestructure;
    class childtofamilylink : public multinode
    {
    public:
        childtofamilylink(int level = -1, const string &xref = string());
        childtofamilylink(const childtofamilylink &other);
        childtofamilylink &operator=(const childtofamilylink &other);
        virtual ~childtofamilylink();
    public:
        string getFamilyReference(void) const;
        void setFamilyReference(const string &familyReference);
        string getPedigreeLinkageType() const;
        void setPedigreeLinkageType(const string &pedigreLinkageType);
        string getChildLinkageStatus() const;
        void setChildLinkageStatus(const string &childLinkageStatus);
        const notestructure *findNote() const;
        notestructure *getNote(void);

    public:
        virtual void check(void) override;
        virtual bool isValid() const override;
        virtual nodetype getType(void) const override;
    }; // class childtofamilylinkNode
} // namespace infoged
#endif // CHILFDTOFAMILYLINK_H__
