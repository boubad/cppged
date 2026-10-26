#include "multinode.h"
///////////////////////////
#include "createnode.h"
#include "gedconstants.h"
#include "stringutils.h"
#include "stringconstants.h"
///////////////////////////
#include <iostream>
//////////////////////////////
namespace infoged
{
    /////////////////////////
    multinode::multinode(int level, const string &tag, const string &value, const string &id) : datanode(level, tag, value, id)
    {
    }
    multinode::multinode(const multinode &other) : datanode(other), m_nodes(other.m_nodes)
    {
    }
    multinode &multinode::operator=(const multinode &other)
    {
        if (this != &other)
        {
            datanode::operator=(other);
            m_nodes = other.m_nodes;
        }
        return *this;
    }
    multinode::~multinode()
    {
    }
    ///////////////////////
    const node::nodePtrList &multinode::getChildren(void) const
    {
        return m_nodes;
    }
    node::nodePtrList &multinode::getChildren(void)
    {
        return m_nodes;
    }
    void multinode::setChildren(const multinode &other)
    {
        const int level = getLevel() + 1;
        for (auto o : other.m_nodes)
        {
            node *pnode = o.get();
            pnode->setLevel(level);
            m_nodes.push_back(o);
        } // o
    }
    const node *multinode::findChild(const string &tag) const
    {
        string stag = stringutils::uppercase(stringutils::trim(tag));
        for (const auto &n : m_nodes)
        {
            if (n->getTag() == stag)
            {
                return n.get();
            }
        }
        return nullptr;
    } // findChild
    node *multinode::getChild(const string &tag, const string &value, bool bfront)
    {
        string stag = stringutils::uppercase(stringutils::trim(tag));
        string svalue = stringutils::trim(value);
        for (auto &n : m_nodes)
        {
            if (n->getTag() == stag)
            {
                const string &xvalue = n->getValue();
                if (!xvalue.empty() && xvalue == svalue)
                {
                    return n.get();
                }
                else if (svalue.empty())
                {
                    return n.get();
                }
            } // tag
        }
        const int level = getLevel() + 1;
        nodePtr hret = createnode::createNode(level, tag, value, string(), getTag());
        node *pRet = hret.get();
        if (pRet != nullptr)
        {
            pRet->setParent(this);
            if (bfront)
            {
                m_nodes.insert(m_nodes.begin(), hret);
            }
            else
            {
                m_nodes.push_back(hret);
            }
            return pRet;
        }
        return nullptr;
    } // getChild
    string multinode::getMultiLinesValue(void) const
    {
        string sret = datanode::getValue();
        for (auto it = m_nodes.begin(); it != m_nodes.end(); ++it)
        {
            const node *pn = (*it).get();
            const string &tag = pn->getTag();
            if (tag == gedconstants::GED_CONT)
            {
                const string &value = pn->getValue();
                sret += stringconstants::NEWLINE + value;
            }
            else if (tag == gedconstants::GED_CONC)
            {
                const string &value = pn->getValue();
                sret += value;
            }
            else
            {
                break;
            }
        } // it
        return sret;
    } // getMultiLinesValue
    void multinode::setMultiLinesValue(const string &value)
    {
        bool done(false);
        while (!done)
        {
            done = true;
            for (auto it = m_nodes.begin(); it != m_nodes.end(); it++)
            {
                const node *pn = (*it).get();
                const string &tag = pn->getTag();
                if (tag == gedconstants::GED_CONT || tag == gedconstants::GED_CONC)
                {
                    m_nodes.erase(it);
                    done = false;
                }
                break;
            }
        } // not done
        string svalue = stringutils::trim(value);
        stringvector lines;
        stringutils::splitlinevalue(svalue, lines);
        if (lines.empty())
        {
            datanode::setValue(string());
            return;
        }
        const size_t n = lines.size();
        datanode::setValue(lines[0]);
        for (size_t i = n - 1; i > 0; i--)
        {
            const string &line = lines[i];
            getChild(gedconstants::GED_CONC, line, true);
        }
    } // setMultiLinesValue
    bool multinode::getAllStringValues(const string &tag, stringset &values) const
    {
        values.clear();
        string stag = stringutils::uppercase(stringutils::trim(tag));
        for (const auto &n : m_nodes)
        {
            if (n->getTag() == stag)
            {
                const string &value = n->getValue();
                string vv = stringutils::trim(value);
                if (!vv.empty() && values.find(vv) == values.end())
                {
                    values.insert(vv);
                }
            }
        }
        return !values.empty();
    }
    string multinode::getChildValue(const string &tag, bool bMulti) const
    {
        const node *p0 = findChild(tag);
        if (p0 == nullptr)
        {
            return string();
        }
        if (!bMulti)
        {
            return p0->getValue();
        }
        const multinode *pm = dynamic_cast<const multinode *>(p0);
        if (pm != nullptr)
        {
            return pm->getMultiLinesValue();
        }
        return string();
    } // getChildValue
    void multinode::setChildValue(const string &tag, const string &value, bool bMulti)
    {
        node *p0 = getChild(tag);
        if (p0 != nullptr)
        {
            if (!bMulti)
            {
                p0->setValue(value);
            }
            else
            {
                multinode *pm = dynamic_cast<multinode *>(p0);
                if (pm != nullptr)
                {
                    pm->setMultiLinesValue(value);
                }
            }
        }
    } // setChildValue
    string multinode::getChildValue(const string &tag1, const string &tag2, bool bMulti) const
    {
        const node *p0 = findChild(tag1);
        if (p0 == nullptr)
        {
            return string();
        }
        const multinode *pm = dynamic_cast<const multinode *>(p0);
        if (pm != nullptr)
        {
            return pm->getChildValue(tag2, bMulti);
        }
        return string();
    } // getChildValue
    void multinode::setChildValue(const string &tag1, const string &tag2, const string &value, bool bMulti)
    {
        node *p0 = getChild(tag1);
        if (p0 != nullptr)
        {
            multinode *pm = dynamic_cast<multinode *>(p0);
            if (pm != nullptr)
            {
                pm->setChildValue(tag2, value, bMulti);
            }
        }
    } // setChildValue
    string multinode::getChildValue(const string &tag1, const string &tag2, const string &tag3, bool bMulti) const
    {
        const node *p0 = findChild(tag1);
        if (p0 == nullptr)
        {
            return string();
        }
        const multinode *pm = dynamic_cast<const multinode *>(p0);
        if (pm != nullptr)
        {
            return pm->getChildValue(tag2, tag3, bMulti);
        }
        return string();
    } // getChildValue
    void multinode::setChildValue(const string &tag1, const string &tag2, const string &tag3, const string &value, bool bMulti)
    {
        node *p0 = getChild(tag1);
        if (p0 != nullptr)
        {
            multinode *pm = dynamic_cast<multinode *>(p0);
            if (pm != nullptr)
            {
                pm->setChildValue(tag2, tag3, value, bMulti);
            }
        }
    } // setChildValue
    string multinode::getChildValue(const string &tag1, const string &tag2, const string &tag3, const string &tag4, bool bMulti) const
    {
        const node *p0 = findChild(tag1);
        if (p0 == nullptr)
        {
            return string();
        }
        const multinode *pm = dynamic_cast<const multinode *>(p0);
        if (pm != nullptr)
        {
            return pm->getChildValue(tag2, tag3, tag4, bMulti);
        }
        return string();
    } // getChildValue
    void multinode::setChildValue(const string &tag1, const string &tag2, const string &tag3, const string &tag4, const string &value, bool bMulti)
    {
        node *p0 = getChild(tag1);
        if (p0 != nullptr)
        {
            multinode *pm = dynamic_cast<multinode *>(p0);
            if (pm != nullptr)
            {
                pm->setChildValue(tag2, tag3, tag4, value, bMulti);
            }
        }
    } // setChildValue
    ///////////////////////
    ////////////////////////////
    void multinode::setLevel(int level)
    {
        datanode::setLevel(level);
        const int curLevel = level + 1;
        for (auto &n : m_nodes)
        {
            node *p = n.get();
            multinode *pm = dynamic_cast<multinode *>(p);
            if (pm != nullptr)
            {
                pm->setLevel(curLevel);
            }
            else
            {
                p->setLevel(curLevel);
            }
        }
    }
    nodetype multinode::getType(void) const
    {
        return nodetype::MultiRecord;
    }
    void multinode::check(void)
    {
        for (auto &n : m_nodes)
        {
            node *p = n.get();
            multinode *pm = dynamic_cast<multinode *>(p);
            if (pm != nullptr)
            {
                pm->check();
            }
            else
            {
                p->check();
            }
        } // for
        datanode::check();
        if (m_nodes.empty() && getLevel() > 0 && getValue().empty())
        {
            if (getStatus() == status::Normal)
            {
                setStatus(status::MissingData);
            }
        }
    } // check
    ostream &multinode::write(ostream &os) const
    {
        datanode::write(os);
        for (auto it = m_nodes.begin(); it != m_nodes.end(); ++it)
        {
            (*it)->write(os);
        }
        return os;
    }
    void multinode::clear(void)
    {
        m_nodes.clear();
        datanode::clear();
    }
    void multinode::mutate(const std::function<void(node *)> &func)
    {
        func(this);
        for (auto &n : m_nodes)
        {
            node *p = n.get();
            multinode *pm = dynamic_cast<multinode *>(p);
            if (pm != nullptr)
            {
                pm->mutate(func);
            }
            else
            {
                p->mutate(func);
            }
        }
    }
    void multinode::visit(const std::function<void(const node *)> &func) const
    {
        func(this);
        for (const auto &n : m_nodes)
        {
            const node *p = n.get();
            const multinode *pm = dynamic_cast<const multinode *>(p);
            if (pm != nullptr)
            {
                pm->visit(func);
            }
            else
            {
                p->visit(func);
            }
        }
    }
    void multinode::remove(const std::function<bool(const node *)> &func)
    {
        bool done(false);
        while (!m_nodes.empty() && !done)
        {
            done = true;
            for (auto it = m_nodes.begin(); it != m_nodes.end(); it++)
            {
                const node *pn = (*it).get();
                if (func(pn))
                {
                    // std::cout << "removing " << *pn;
                    it = m_nodes.erase(it);
                    done = false;
                    break;
                }
            } // it
        } // not done
        if (!m_nodes.empty())
        {
            for (auto &n : m_nodes)
            {
                node *p = n.get();
                multinode *pm = dynamic_cast<multinode *>(p);
                if (pm != nullptr)
                {
                    pm->remove(func);
                }
            }
        }

    } //
    ///////////////////////////
} // namespace infoged