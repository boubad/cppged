#include "proxynode.h"
#include "multinode.h"
////////////////////////////
#include <cassert>
////////////////////////////
namespace infoged
{
    proxynode::proxynode(multinode *p) : m_proxy(p)
    {
    }
    proxynode::proxynode(const proxynode &other) : m_proxy(other.m_proxy)
    {
    }
    proxynode &proxynode::operator=(const proxynode &other)
    {
        if (this != &other)
        {
            m_proxy = other.m_proxy;
        }
        return *this;
    }
    proxynode::~proxynode(void)
    {
    }
    multinode *proxynode::getProxy(void) const
    {
        return m_proxy;
    }
    void proxynode::setProxy(multinode *p)
    {
        m_proxy = p;
    }
    //////////////////////////////////////////
    string proxynode::getMultiLinesValue(void) const
    {
        assert(m_proxy != nullptr);
        return m_proxy->getMultiLinesValue();
    }
    void proxynode::setMultiLinesValue(const string &value)
    {
        assert(m_proxy != nullptr);
        m_proxy->setMultiLinesValue(value);
    }
    bool proxynode::getAllStringValues(const string &tag, stringset &values) const
    {
        assert(m_proxy != nullptr);
        return m_proxy->getAllStringValues(tag, values);
    }
    string proxynode::getChildValue(const string &tag, bool bMulti) const
    {
        assert(m_proxy != nullptr);
        return m_proxy->getChildValue(tag, bMulti);
    }
    void proxynode::setChildValue(const string &tag, const string &value, bool bMulti)
    {
        assert(m_proxy != nullptr);
        m_proxy->setChildValue(tag, value, bMulti);
    }
    string proxynode::getChildValue(const string &tag1, const string &tag2, bool bMulti) const
    {
        assert(m_proxy != nullptr);
        return m_proxy->getChildValue(tag1, tag2, bMulti);
    }
    void proxynode::setChildValue(const string &tag1, const string &tag2, const string &value, bool bMulti)
    {
        assert(m_proxy != nullptr);
        m_proxy->setChildValue(tag1, tag2, value, bMulti);
    }
    string proxynode::getChildValue(const string &tag1, const string &tag2, const string &tag3, bool bMulti) const
    {
        assert(m_proxy != nullptr);
        return m_proxy->getChildValue(tag1, tag2, tag3, bMulti);
    }
    void proxynode::setChildValue(const string &tag1, const string &tag2, const string &tag3, const string &value, bool bMulti)
    {
        assert(m_proxy != nullptr);
        m_proxy->setChildValue(tag1, tag2, tag3, value, bMulti);
    }
    string proxynode::getChildValue(const string &tag1, const string &tag2, const string &tag3, const string &tag4, bool bMulti) const
    {
        assert(m_proxy != nullptr);
        return m_proxy->getChildValue(tag1, tag2, tag3, tag4, bMulti);
    }
    void proxynode::setChildValue(const string &tag1, const string &tag2, const string &tag3, const string &tag4, const string &value, bool bMulti)
    {
        assert(m_proxy != nullptr);
        m_proxy->setChildValue(tag1, tag2, tag3, tag4, value, bMulti);
    }
    //////////////////////////////////////////
} // namespace infoged