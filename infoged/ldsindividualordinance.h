#pragma once
#ifndef GEDCOMLDSINDIVIDUALORDINANCE_H__
#define GEDCOMLDSINDIVIDUALORDINANCE_H__
//////////////////////////////////////
#include "proxynode.h"
///////////////////////////////////
namespace infoged
{
    class individualordinance;
    class ldsindividualordinance : public proxynode
    {
    public:
        ldsindividualordinance(multinode *proxy = nullptr);
        ldsindividualordinance(const ldsindividualordinance &other);
        ldsindividualordinance &operator=(const ldsindividualordinance &other);
        virtual ~ldsindividualordinance();

    public:
        bool getBaplOrdinance(individualordinance &detail);
        bool getConlOrdinance(individualordinance &detail);
        bool getEndlOrdinance(individualordinance &detail);
        bool getSlgcOrdinance(individualordinance &detail);

    private:
        bool getDetail(const string &tag, individualordinance &detail);
    };
} // namespace infoged

#endif //    GEDCOMLDSINDIVIDUALORDINANCE_H__
