#pragma once
#ifndef TREEUTILS_H__
#define TREEUTILS_H__
//////////////////////////////
#include "mydefs.h"
/////////////////////////////
namespace infoged
{
    class tree;
    class treeutils
    {
    public:
        static void checkStatus(tree *pTree);
    }; // treeutils
} // namespace infoged
////////////////////////////////
#endif //
