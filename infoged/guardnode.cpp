#include "guardnode.h"
////////////////////////
namespace infoged
{
    guardnode::guardnode(const string &tag) : multinode(0, tag)
    {
    }
    guardnode::guardnode(const guardnode &other) : multinode(other)
    {
    }
    guardnode &guardnode::operator=(const guardnode &other)
    {
        if (this != &other)
        {
            multinode::operator=(other);
        }
        return *this;
    }
    guardnode::~guardnode()
    {
    }
    nodetype guardnode::getType(void) const
    {
        return nodetype::Guard;
    }
    bool guardnode::isValid(void) const
    {
        return multinode::isValid() && getLevel() == 0;
    }
} // namespace infoged