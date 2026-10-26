#include "linedata.h"
#include "stringutils.h"
#include "stringconstants.h"
/////////////////////////////////
namespace infoged
{
    linedata::linedata(int level, const string &tag, const string &value, const string &id) :
    basedata(level, tag), m_id(id), m_value(value)
    {
        string sid = stringutils::trim(id);
        if (stringutils::isPointer(sid))
        {
            m_id = sid;
        }
        string svalue = stringutils::trim(value);
        if (!svalue.empty())
        {
            m_value = svalue;
        }
        linedata::check();
    }
    linedata::linedata(const linedata &other) :basedata(other), m_id(other.m_id),
                                                m_value(other.m_value)
    {
    }
    linedata &linedata::operator=(const linedata &other)
    {
        if (this != &other)
        {
            basedata::operator=(other);
            m_id = other.m_id;
            m_value = other.m_value;
        }
        return *this;
    }
    linedata::~linedata(void)
    {
    }
    ////////////////////////////////////////////
    const string &linedata::getId(void) const
    {
        return m_id;
    }
    void linedata::setId(const string &id)
    {
        string sid = stringutils::trim(id);
        if (stringutils::isPointer(sid))
        {
            m_id = sid;
        }
        else
        {
            m_id.clear();
        }
        check();
    }
    const string &linedata::getValue(void) const
    {
        return m_value;
    }
    void linedata::setValue(const string &value)
    {
        m_value = stringutils::trim(value);
        check();
    }
    ostream &linedata::write(ostream &os) const
    {
        os << getLevel();
        if (!m_id.empty())
        {
            os << stringconstants::SPACE << m_id;
        }
        string tag = stringutils::uppercase(getTag());
        if (!tag.empty())
        {
            os << stringconstants::SPACE << tag;
        }
        if (!m_value.empty())
        {
            os << stringconstants::SPACE << m_value;
        }
        os << stringconstants::NEWLINE;
        return os;
    }
    status linedata::getStatusValue(void) const
    {
        status s = basedata::getStatusValue();
        if (s != status::Normal)
        {
            return s;
        }
        if (stringutils::isPointer(m_id))
        {
            if (getLevel() > 0)
            {
                return status::BadLevelValue;
            }
            if (m_id.length() > 22)
            {
                return status::NotCompliantId;
            }
            if (stringutils::isPointer(m_value))
            {
                return status::BadReferenceLocation;
            }
        } // id
        if (stringutils::isPointer(m_value))
        {
            if (getLevel() == 0)
            {
                return status::BadEntityDefinition;
            }
            if (m_value.length() > 22)
            {
                return status::NntCompliantReference;
            }
        }
        return status::Normal;
    }
    void linedata::clear(void)
    {
        basedata::clear();
        m_id.clear();
        m_value.clear();
    }
    //////////////////////////////////////////////
} // namespace infoged