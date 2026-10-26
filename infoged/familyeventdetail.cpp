
#include "familyeventdetail.h"
#include "gedconstants.h"
//////////////////////////////
namespace infoged
{
    familyeventdetail::familyeventdetail(multinode *proxy) : eventdetail(proxy)
    {
    }
    familyeventdetail::familyeventdetail(const familyeventdetail &other) : eventdetail(other)
    {
    }
    familyeventdetail &familyeventdetail::operator=(const familyeventdetail &other)
    {
        if (this != &other)
        {
            eventdetail::operator=(other);
        }
        return *this;
    }
    familyeventdetail::~familyeventdetail()
    {
    }
    string familyeventdetail::getHusbAge(void) const
    {
        return getChildValue(gedconstants::GED_HUSB, gedconstants::GED_AGE);
    }
    void familyeventdetail::setHusbAge(const string &husbage)
    {
        setChildValue(gedconstants::GED_HUSB, gedconstants::GED_AGE, husbage);
    }
    string familyeventdetail::getWifeAge(void) const
    {
        return getChildValue(gedconstants::GED_WIFE, gedconstants::GED_AGE);
    }
    void familyeventdetail::setWifeAge(const string &wifeage)
    {
        setChildValue(gedconstants::GED_WIFE, gedconstants::GED_AGE, wifeage);
    }
} // namespace infoged
