#pragma once
#ifndef AssociationNodeNODE_H__
#define AssociationNodeNODE_H__
#include "multinode.h"

///////////////////////
namespace infoged
{
    class sourcecitation;
    class notestructure;
    class associationstructure : public multinode
    {
    public:
        associationstructure(int level = -1, const string &xref = string());
        associationstructure(const associationstructure &other);
        associationstructure &operator=(const associationstructure &other);
        virtual ~associationstructure();

    public:
        string getIndivReference(void) const;
        void setIndivReference(const string &indivReference);
        string getRelationDescriptor(void) const;
        void setRelationDescriptor(const string &relationDescriptor);
        const sourcecitation *findSourceCitation() const;
        sourcecitation *getSourceCitation(void);
        const notestructure *findNote() const;
        notestructure *getNote(void);

    public:
        virtual void check(void) override;
        virtual bool isValid() const override;
        virtual nodetype getType(void) const override;
    };
} // namespace infoged
#endif // AssociationNodeNODE_H__