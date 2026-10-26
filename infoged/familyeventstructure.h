#pragma once
#ifndef FAMILYSTRUCTURE_H__
#define FAMILYSTRUCTURE_H__
////////////////////////
#include "proxynode.h"
////////////////////////////////
namespace infoged
{
    class familyeventdetail;
    class familyeventstructure : public proxynode
    {
    public:
        familyeventstructure(multinode *proxy = nullptr);
        familyeventstructure(const familyeventstructure &other);
        familyeventstructure &operator=(const familyeventstructure &other);
        virtual ~familyeventstructure();

    public:
        bool getAnul(familyeventdetail &detail);
        bool getCens(familyeventdetail &detail);
        bool getDiv(familyeventdetail &detail);
        bool getDivf(familyeventdetail &detail);
        bool getEnga(familyeventdetail &detail);
        bool getMarb(familyeventdetail &detail);
        bool getMarc(familyeventdetail &detail);
        string getMarrValue() const;
        void setMarrValue(const string &value);
        bool getMarr(familyeventdetail &detail);
        bool getMarl(familyeventdetail &detail);
        bool getMars(familyeventdetail &detail);
        bool getResi(familyeventdetail &detail);
        bool getOtherEvents(std::list<familyeventdetail> &details);
        bool getEvent(familyeventdetail &detail, const string &eventdescriptor = string());

    private:
        bool getDetail(const string &tag, familyeventdetail &detail);
    };
} // namespace infoged
#endif // FAMILYSTRUCTURE_H__
