#include "entitynode.h"
/////////////////////////////
#include "stringutils.h"
/////////////////////////////
namespace infoged
{
    entitynode::entitynode(const string &tag, const string &id) : multinode(0, tag, string(), id)
    {
    }
    entitynode::entitynode(const entitynode &other) : multinode(other)
    {
    }
    entitynode &entitynode::operator=(const entitynode &other)
    {
        if (this != &other)
        {
            multinode::operator=(other);
        }
        return *this;
    }
    entitynode::~entitynode()
    {
    }
    nodetype entitynode::getType(void) const
    {
        return nodetype::Entity;
    }
    bool entitynode::isValid(void) const
    {
        return (getLevel() == 0 && stringutils::isPointer(getId()));
    }
} // namespace infoged