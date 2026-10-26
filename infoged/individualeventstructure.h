#pragma once
#ifndef INDIVIDUALEVENTSTRUCTURE_H__
#define INDIVIDUALEVENTSTRUCTURE_H__
//////////////////////////
#include "proxynode.h"
/////////////////////////////
namespace infoged
{
    class individualeventdetail;
    class individualeventstructure : public proxynode
    {
    public:
        individualeventstructure(multinode *proxy = nullptr);
        individualeventstructure(const individualeventstructure &other);
        individualeventstructure &operator=(const individualeventstructure &other);
        virtual ~individualeventstructure();

    public:
        string getBirth(void) const;
        void setBirth(const string &birth);
        bool getBirthDetail(individualeventdetail &detail);
        string getBirthFamilyReference(void) const;
        void setBirthFamilyReference(const string &birthfamilyreference);
        //
        string getChr(void) const;
        void setChr(const string &chr);
        bool getChrDetail(individualeventdetail &detail);
        string getChrFamilyReference(void) const;
        void setChrFamilyReference(const string &chrfamilyreference);
        //
        string getDeath(void) const;
        void setDeath(const string &death);
        bool getDeathDetail(individualeventdetail &detail);
        //
        bool getBurialDetail(individualeventdetail &detail);
        bool getCremationDetail(individualeventdetail &detail);
        //
        bool getAdoptionDetail(individualeventdetail &detail);
        string getAdoptionFamilyReference(void) const;
        void setAdoptionFamilyReference(const string &aptionfamilyreference);
        string getAdoptionAdoptedByWich(void) const;
        void setAdoptionAdoptedByWich(const string &adoptionadoptedbywich);
        //
        bool getBapmDetail(individualeventdetail &detail);
        bool getBarmDetail(individualeventdetail &detail);
        bool getBasmDetail(individualeventdetail &detail);
        bool getBlesDetail(individualeventdetail &detail);
        //
        bool getChraDetail(individualeventdetail &detail);
        bool getConfDetail(individualeventdetail &detail);
        bool getFcomDetail(individualeventdetail &detail);
        bool getOrdnDetail(individualeventdetail &detail);
        //
        bool getNatuDetail(individualeventdetail &detail);
        bool getEmigDetail(individualeventdetail &detail);
        bool getImmiDetail(individualeventdetail &detail);
        //
        bool getCensDetail(individualeventdetail &detail);
        bool getProbDetail(individualeventdetail &detail);
        bool getWillDetail(individualeventdetail &detail);
        //
        bool getGradDetail(individualeventdetail &detail);
        bool getRetiDetail(individualeventdetail &detail);
        //
        bool getOtherEventDetails(std::list<individualeventdetail> &details);
        bool createOtherEventDetail(individualeventdetail &detail);
        //

    private:
        bool getDetail(const string &tag, individualeventdetail &detail);
    }; // class individualeventstructure
} // namespace infoged
#endif // INDIVIDUALEVENTSTRUCTURE_H__
