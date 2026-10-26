#pragma once
#ifndef TRAILER_H__
#define TRAILER_H__
//////////////////////
#include "node.h"
#include "basedata.h"
//////////////////////////
namespace infoged
{
    class trailer : public node, public basedata
    {
    public:
        trailer();
        trailer(const trailer &other);
        trailer &operator=(const trailer &other);
        virtual ~trailer();

    public:
        virtual const string &getTag(void) const;
        virtual ostream &write(ostream &os) const override;
        virtual bool isValid() const override;
        virtual nodetype getType(void) const override;
        virtual int getLevel(void) const override;
        virtual void setLevel(int level) override;
        virtual void check(void) override;
        virtual void clear(void) override;
    }; // classtrailer
} // namespace infoged
#endif // TRAILER_H__