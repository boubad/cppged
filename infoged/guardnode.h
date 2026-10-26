#pragma once
#ifndef GUARDNODE_H__
#define GUARDNODE_H__
///////////////////////
#include "multinode.h"
//////////////////
namespace infoged
{
    class guardnode : public multinode
    {
    public:
        guardnode(const string &tag = string());
        guardnode(const guardnode &other);
        guardnode &operator=(const guardnode &other);
        ~guardnode();

    public:
        virtual nodetype getType(void) const override;
        virtual bool isValid(void) const override;
    }; // class guardnode
} // namespace infoged
#endif // GUARDNODE_H__