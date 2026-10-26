#pragma once
#ifndef REPOSITORYCITATION_H__
#define REPOSITORYCITATION_H__
//////////////////////////
#include "multinode.h"
/////////////////////////
namespace infoged
{
    class notestructure;
    /////////////////////////
    class sourcerepositorycitation : public multinode
    {
    public:
        sourcerepositorycitation(int level = -1, const string &xref = string());
        sourcerepositorycitation(const sourcerepositorycitation &other);
        sourcerepositorycitation &operator=(const sourcerepositorycitation &other);
        virtual ~sourcerepositorycitation();

    public:
        string getRepositoryRef(void) const;
        void setRepositoryRef(const string &text);
        const notestructure *findNote() const;
        notestructure *getNote();
        string getSourceCallNumber(void) const;
        void setSourceCallNumber(const string &scn);
        string getSourceMediaType(void) const;
        void setSourceMediaType(const string &media);

    public:
        virtual void check() override;
        virtual bool isValid() const override;
        virtual nodetype getType(void) const override;
    };
} // namespace infoged
#endif // REPOSITORYCITATION_H__
