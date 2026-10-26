#pragma once
#ifndef ENTITYNODE_H__
#define ENTITYNODE_H__
/////////////////////////
#include "multinode.h"
/////////////////////////
namespace infoged
{
    class entitynode : public multinode
    {
    public:
        entitynode(const string &tag = string(), const string &id = string());
        entitynode(const entitynode &other);
        entitynode &operator=(const entitynode &other);
        virtual ~entitynode();

    public:
        virtual nodetype getType(void) const override;
        virtual bool isValid(void) const override;
    };
} // namespace infoged
#endif // ENTITYNODE_H__