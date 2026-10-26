#pragma once
#ifndef FAMILYEVENTDETAILSTRUCT_H__
#define FAMILYEVENTDETAILSTRUCT_H__
//////////////////
#include "eventdetail.h"
//////////////////////////////
namespace infoged
{
    /////////////////////////////
    class familyeventdetail : public eventdetail
    {
    public:
        familyeventdetail(multinode *proxy = nullptr);
        familyeventdetail(const familyeventdetail &other);
        familyeventdetail &operator=(const familyeventdetail &other);
        virtual ~familyeventdetail();

    public:
        string getHusbAge(void) const;
        void setHusbAge(const string &husbage);
        string getWifeAge(void) const;
        void setWifeAge(const string &wifeage);
    };
} // namespace infoged
#endif // FAMILYEVENTDETAILSTRUCT_H__
