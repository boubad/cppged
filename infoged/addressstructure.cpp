
/////////////////////////
#include "addressstructure.h"
#include "gedconstants.h"
/////////////////////////
namespace infoged
{
    /////////////////////////
    addressstructure::addressstructure(int level, const string &addrline) : multinode(level, gedconstants::GED_ADDR)
    {
        setAddrLine(addrline);
    }
    /////////////////////////
    addressstructure::addressstructure(const addressstructure &other) : multinode(other)
    {
    }
    /////////////////////////
    addressstructure &addressstructure::operator=(const addressstructure &other)
    {
        if (this != &other)
        {
            multinode::operator=(other);
        }
        return *this;
    }
    /////////////////////////
    addressstructure::~addressstructure()
    {
    }
    /////////////////////////
    string addressstructure::getAddrLine(void) const
    {
        return getValue();
    }
    void addressstructure::setAddrLine(const string &addrline)
    {
        setValue(addrline);
    }
    string addressstructure::getAddr1(void) const
    {
        return getChildValue(gedconstants::GED_ADR1);
    }
    void addressstructure::setAddr1(const string &addr1)
    {
        setChildValue(gedconstants::GED_ADR1, addr1);
    }
    /////////////////////////
    string addressstructure::getAddr2(void) const
    {
        return getChildValue(gedconstants::GED_ADR2);
    }
    void addressstructure::setAddr2(const string &addr2)
    {
        setChildValue(gedconstants::GED_ADR2, addr2);
    }
    string addressstructure::getAddr3(void) const
    {
        return getChildValue(gedconstants::GED_ADR3);
    }
    void addressstructure::setAddr3(const string &addr3)
    {
        setChildValue(gedconstants::GED_ADR3, addr3);
    }
    /////////////////////////
    string addressstructure::getCity(void) const
    {
        return getChildValue(gedconstants::GED_CITY);
    }
    void addressstructure::setCity(const string &city)
    {
        setChildValue(gedconstants::GED_CITY, city);
    }
    /////////////////////////
    string addressstructure::getState(void) const
    {
        return getChildValue(gedconstants::GED_STAE);
    }
    void addressstructure::setState(const string &state)
    {
        setChildValue(gedconstants::GED_STAE, state);
    }
    /////////////////////////
    string addressstructure::getPost(void) const
    {
        return getChildValue(gedconstants::GED_POST);
    }
    void addressstructure::setPost(const string &post)
    {
        setChildValue(gedconstants::GED_POST, post);
    }
    /////////////////////////
    string addressstructure::getCountry(void) const
    {
        return getChildValue(gedconstants::GED_CTRY);
    }
    void addressstructure::setCountry(const string &country)
    {
        setChildValue(gedconstants::GED_CTRY, country);
    }

    //
    string addressstructure::getPhone(void) const
    {
        const multinode *parent = getParent();
        if (parent != nullptr)
        {
            return parent->getChildValue(gedconstants::GED_PHON);
        }
        return string();
    }
    void addressstructure::setPhone(const string &phone)
    {
        multinode *parent = getParent();
        if (parent != nullptr)
        {
            parent->setChildValue(gedconstants::GED_PHON, phone);
        }
    }
    string addressstructure::getFax(void) const
    {
        const multinode *parent = getParent();
        if (parent != nullptr)
        {
            return parent->getChildValue(gedconstants::GED_FAX);
        }
        return string();
    }
    void addressstructure::setFax(const string &fax)
    {
        multinode *parent = getParent();
        if (parent != nullptr)
        {
            parent->setChildValue(gedconstants::GED_FAX, fax);
        }
    }
    string addressstructure::getEmail(void) const
    {
        const multinode *parent = getParent();
        if (parent != nullptr)
        {
            return parent->getChildValue(gedconstants::GED_EMAIL);
        }
        return string();
    }
    void addressstructure::setEmail(const string &email)
    {
        multinode *parent = getParent();
        if (parent != nullptr)
        {
            parent->setChildValue(gedconstants::GED_EMAIL, email);
        }
    }
    string addressstructure::getWebsite(void) const
    {
        const multinode *parent = getParent();
        if (parent != nullptr)
        {
            return parent->getChildValue(gedconstants::GED_WWWW);
        }
        return string();
    }
    void addressstructure::setWebsite(const string &website)
    {
        multinode *parent = getParent();
        if (parent != nullptr)
        {
            parent->setChildValue(gedconstants::GED_WWWW, website);
        }
    }
    bool addressstructure::isValid(void) const
    {
        string addrline = getAddrLine();
        if (addrline.empty())
        {
            string s1 = getAddr1();
            string s2 = getAddr2();
            string s3 = getAddr3();
            string city = getCity();
            string state = getState();
            string post = getPost();
            string country = getCountry();
            if (s1.empty() &&
                s2.empty() &&
                s3.empty() &&
                city.empty() && state.empty() && post.empty() && country.empty())
            {
                return false;
            }
        } // addrline
        return multinode::isValid() && getTag() == gedconstants::GED_ADDR;
    }
    void addressstructure::check(void)
    {
        multinode::check();
        string addrline = getAddrLine();
        if (addrline.empty())
        {
            string s1 = getAddr1();
            string s2 = getAddr2();
            string s3 = getAddr3();
            string city = getCity();
            string state = getState();
            string post = getPost();
            string country = getCountry();
            if (s1.empty() &&
                s2.empty() &&
                s3.empty() &&
                city.empty() && state.empty() && post.empty() && country.empty())
            {
                setStatus(status::MissingData);
            }
        }
    }
    nodetype addressstructure::getType(void) const
    {
        return nodetype::Address;
    }
    /////////////////////////
} // namespace infoged
