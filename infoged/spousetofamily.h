#pragma once
#ifndef SPOUSETOFAMILYNODE_H__
#define SPOUSETOFAMILYNODE_H__
/////////////////////
#include "multinode.h"

/////////////////////////
namespace infoged
{
    class notestructure;
    class spousetofamilylink : public multinode
    {
    public:
        spousetofamilylink(int level = -1, const string &xref = string());
        spousetofamilylink(const spousetofamilylink &other);
        spousetofamilylink &operator=(const spousetofamilylink &other);
        virtual ~spousetofamilylink();

    public:
        string getFamilyRef(void) const;
        void setFamilyRef(const string &familyref);
        const notestructure *findNote(void) const;
        notestructure *getNote();

    public:
        virtual void check() override;
        virtual bool isValid() const override;
        virtual nodetype getType(void) const override;

    }; // class SpouseToFamilyNode
} // namespace infoged
#endif // SPOUSETOFAMILYNODE_H__