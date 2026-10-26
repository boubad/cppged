#pragma once
#ifndef LDSSPOUSESEALING_H__
#define LDSSPOUSESEALING_H__
#include "multinode.h"
////////////////////////

namespace infoged
{
    class changedate;
    class notestructure;
    class sourcecitation;
    class ldsspousesealing : public multinode
    {
    public:
        ldsspousesealing(int level = -1);
        ldsspousesealing(const ldsspousesealing &other);
        ldsspousesealing &operator=(const ldsspousesealing &other);
        virtual ~ldsspousesealing();

    public:
        string getDate(void) const;
        void setDate(const string &date);
        string getTempleCode(void) const;
        void setTempleCode(const string &templeCode);
        string getPlaceLivingOrdinance(void) const;
        void setPlaceLivingOrdinance(const string &placeLivingOrdinance);
        string getLesSpouseSealingDateStatus(void) const;
        void setLesSpouseSealingDateStatus(const string &lesSpouseSealingDateStatus);
        string getStatusDate(void) const;
        void setStatusDate(const string &statusDate);
        const notestructure *findNote() const;
        notestructure *getNote();
        const sourcecitation *findSourceCitation() const;
        sourcecitation *getSourceCitation();

    public:
        virtual bool isValid(void) const override;
        virtual nodetype getType(void) const override;
    }; // class LdssPouseSealing
} // namespace infoged
#endif // LDSSPOUSESEALING_H__
