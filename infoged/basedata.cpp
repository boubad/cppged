#include "basedata.h"
#include "stringutils.h"
#include "stringconstants.h"
/////////////////////////////////
namespace infoged
{
    basedata::basedata(int level, const string &tag) : m_parent(nullptr), m_status(status::NotValid), m_level(-1)
    {
        if (level >= 0)
        {
            m_level = level;
        }
        string stag = stringutils::uppercase(stringutils::trim(tag));
        if (stringutils::isTag(stag))
        {
            m_tag = stag;
        }
        basedata::check();
    }
    basedata::basedata(const basedata &other) : m_parent(other.m_parent), m_status(other.m_status), m_level(other.m_level),m_tag(other.m_tag)
                                               
    {
    }
    basedata &basedata::operator=(const basedata &other)
    {
        if (this != &other)
        {
            m_parent = other.m_parent;
            m_status = other.m_status;
            m_level = other.m_level;
            m_tag = other.m_tag;
        }
        return *this;
    }
    basedata::~basedata(void)
    {
    }
    ////////////////////////////////////////////
    int basedata::getLevel(void) const
    {
        return m_level;
    }
    void basedata::setLevel(int level)
    {
        m_level = level >= 0 ? level : -1;
        check();
    }
    const string &basedata::getTag(void) const
    {
        return m_tag;
    }
    void basedata::setTag(const string &tag)
    {
        string stag = stringutils::uppercase(stringutils::trim(tag));
        if (stringutils::isTag(stag))
        {
            m_tag = stag;
        }
        else
        {
            m_tag.clear();
        }
        check();
    }
    ostream &basedata::write(ostream &os) const
    {
        os << m_level;
        if (!m_tag.empty())
        {
            os << stringconstants::SPACE << m_tag;
        }
        os << stringconstants::NEWLINE;
        return os;
    }
    bool basedata::isValid(void) const
    {
        return m_level >= 0 && !m_tag.empty();
    }
    status basedata::getStatusValue(void) const
    {
        if (m_level < 0)
        {
            return status::InvalidLevel;
        }
        if (!stringutils::isTag(m_tag))
        {
            return status::InvalidTag;
        }
        if (m_tag.front() == '_')
        {
            return status::NotCompliantTag;
        }
        if (m_tag.length() > 31)
        {
            return status::NotCompliantTag;
        }
        return status::Normal;
    }
    status basedata::getStatus(void) const
    {
        return m_status;
    }
    void basedata::setStatus(status st)
    {
        m_status = st;
    }
    void basedata::check(void)
    {
        m_status = getStatusValue();
    }
    multinode *basedata::getParent(void) const
    {
        return m_parent;
    }
    void basedata::setParent(multinode *p)
    {
        m_parent = p;
    }
    void basedata::clear(void)
    {
        m_parent = nullptr;
        m_status = status::NotValid;
        m_level = -1;
        m_tag.clear();
    }
    //////////////////////////////////////////////
} // namespace infoged