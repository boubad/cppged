
#include "individualeventdetail.h"
#include "gedconstants.h"
namespace infoged
{

    individualeventdetail::individualeventdetail(multinode *proxy) : eventdetail(proxy)
    {
    }
    individualeventdetail::individualeventdetail(const individualeventdetail &other) : eventdetail(other)
    {
    }
    individualeventdetail &individualeventdetail::operator=(const individualeventdetail &other)
    {
        if (this != &other)
        {
            eventdetail::operator=(other);
        }
        return *this;
    }
    individualeventdetail::~individualeventdetail()
    {
    }
    string individualeventdetail::getAgeAtEvent(void) const
    {
        return getChildValue(gedconstants::GED_AGE);
    }
    void individualeventdetail::setAgeAtEvent(const string &ageatevent)
    {
        setChildValue(gedconstants::GED_AGE, ageatevent);
    }
} // namespace    infoged