#include "gedcomline.h"
#include "stringutils.h"
//////////////////////////////
namespace infoged
{
    /////////////////////////
    gedcomline::gedcomline(int level, const string &tag, const string &value, const string &id) : datanode(level, tag, value, id)
    {
    }
    gedcomline::gedcomline(const gedcomline &other) : datanode(other)
    {
    }
    gedcomline &gedcomline::operator=(const gedcomline &other)
    {
        if (this != &other)
        {
            datanode::operator=(other);
        }
        return *this;
    }
    gedcomline::~gedcomline()
    {
    }
    ////////////////////////////
    nodetype gedcomline::getType(void) const
    {
        return nodetype::Single;
    }
    ///////////////////////////
} // namespace infoged