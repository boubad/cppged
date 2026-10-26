#pragma once
#ifndef INDIVORDINANCE_H__
#define INDIVORDINANCE_H__
#include "proxynode.h"
/////////////////////////////
namespace infoged
{
    class sourcecitation;
    class notestructure;
    class individualordinance : public proxynode
    {
    public:
        individualordinance(multinode *proxy = nullptr);
        individualordinance(const individualordinance &other);
        individualordinance &operator=(const individualordinance &other);
        virtual ~individualordinance();

    public:
        string getDateLdsOrd(void) const;
        void setDateLdsOrd(const string &dateLdsOrd);
        string getTempleCode(void) const;
        void setTempleCode(const string &templeCode);
        string getPlaceLivingOrdinance(void) const;
        void setPlaceLivingOrdinance(const string &placeLivingOrdinance);
        string getFamilyReference(void) const;
        void setFamilyReference(const string &famcId);
        string getLdsStatus(void) const;
        void setLdsStatus(const string &ldsStatus);
        string getLdsStatusDate(void) const;
        void setLdsStatusDate(const string &ldsStatusDate);
        const sourcecitation *findSourceCitation() const;
        sourcecitation *getSourceCitation();
        const notestructure *findNote() const;
        notestructure *getNote();
    }; // class individualordinance
} // namespace infoged
#endif // INDIVORDINANCE_H__