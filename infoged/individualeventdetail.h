#pragma once
#ifndef INDIVIDUALEVENTDETAIL_H__
#define INDIVIDUALEVENTDETAIL_H__
#include "eventdetail.h"
namespace infoged
{
    class individualeventdetail : public eventdetail
    {
    public:
        individualeventdetail(multinode *proxy = nullptr);
        individualeventdetail(const individualeventdetail &other);
        individualeventdetail &operator=(const individualeventdetail &other);
        virtual ~individualeventdetail();

    public:
        string getAgeAtEvent(void) const;
        void setAgeAtEvent(const string &ageatevent);
    };
} // namespace infoged
#endif // INDIVIDUALEVENTDETAIL_H__