
////////////////////////
#include "trailer.h"
#include "gedconstants.h"
////////////////////////
namespace infoged
{

    trailer::trailer() : node(), basedata(0, gedconstants::GED_TRLR)
    {
    }

    trailer::trailer(const trailer &other) : node(other), basedata(other)
    {
    }
    trailer &trailer::operator=(const trailer &other)
    {
        if (this != &other)
        {
            node::operator=(other);
            basedata::operator=(other);
        }
        return *this;
    }
    trailer::~trailer()
    {
    }
    nodetype trailer::getType(void) const
    {
        return nodetype::Trailer;
    }
    ostream &trailer::write(ostream &os) const
    {
        return basedata::write(os);
    }
    const string &trailer::getTag(void) const
    {
        return basedata::getTag();
    }
    bool trailer::isValid() const
    {
        if (!basedata::isValid())
        {
            return false;
        }
        return getTag() == gedconstants::GED_TRLR;
    }
    int trailer::getLevel(void) const
    {
        return basedata::getLevel();
    }
    void trailer::setLevel(int /*level*/)
    {
        // do nothing
    }
    void trailer::check(void)
    {
        basedata::check();
    }
    void trailer::clear(void)
    {
    }
} // namespace infoged
