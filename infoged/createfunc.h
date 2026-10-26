#pragma once
#ifndef CREATEFUNC_H__
#define CREATEFUNC_H__
/////////////////////
#include "node.h"
/////////////////////
namespace infoged
{
    class multinode;
    class createfunc
    {
    public:
        static const node::nodeCreateFunc *getCreateFunc(const string &tag);
    };
} // namespace infoged
#endif // CREATEFUNC_H__