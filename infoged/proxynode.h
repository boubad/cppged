#pragma once
#ifndef PROXY_NODE_H
#define PROXY_NODE_H
/////////////////////////
#include "mydefs.h"
/////////////////////
namespace infoged
{
    class multinode;
    class proxynode
    {
    public:
        proxynode(multinode *p = nullptr);
        proxynode(const proxynode &other);
        proxynode &operator=(const proxynode &other);
        virtual ~proxynode(void);
        multinode *getProxy(void) const;
        void setProxy(multinode *p);

    public:
        string getMultiLinesValue(void) const;
        void setMultiLinesValue(const string &value);
        bool getAllStringValues(const string &tag, stringset &values) const;
        string getChildValue(const string &tag, bool bMulti = false) const;
        void setChildValue(const string &tag, const string &value, bool bMulti = false);
        string getChildValue(const string &tag1, const string &tag2, bool bMulti = false) const;
        void setChildValue(const string &tag1, const string &tag2, const string &value, bool bMulti = false);
        string getChildValue(const string &tag1, const string &tag2, const string &tag3, bool bMulti = false) const;
        void setChildValue(const string &tag1, const string &tag2, const string &tag3, const string &value, bool bMulti = false);
        string getChildValue(const string &tag1, const string &tag2, const string &tag3, const string &tag4, bool bMulti = false) const;
        void setChildValue(const string &tag1, const string &tag2, const string &tag3, const string &tag4, const string &value, bool bMulti = false);

    private:
        multinode *m_proxy;
    };
} // namespace infoged
#endif // PROXY_NODE_H