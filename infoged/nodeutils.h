#pragma once
#ifndef NODEUTILS_H
#define NODEUTILS_H
//////////////////////////
#include "mydefs.h"
/////////////////////////////
namespace infoged
{
    class nodeutils
    {
    public:
        static bool isTagHasNoChidren(const string &tag);
        static bool canHaveChild(const string &parentTag, const string &childTag);
    }; // class nodeutils
} // namespace infoged
//////////////////////////////
#endif // NODEUTILS_H
