#include "createnode.h"
/////////////////////////
#include "createfunc.h"
#include "nodeutils.h"
#include "gedconstants.h"
#include "stringutils.h"
//////////////////////////
#include "gedcomline.h"
#include "multinode.h"
/////////////
#include <cassert>
#include <iostream>
#include <sstream>
///////////////////////////
namespace infoged
{
    /////////////////////////////////
    node::nodePtr createnode::createNode(int level,
                                         const string &tag,
                                         const string &value,
                                         const string &id,
                                         const string &parentTag)
    {
        
        node::nodePtr hret;
        auto pfunc = createfunc::getCreateFunc(tag);
        if (pfunc != nullptr)
        {
            hret = (*pfunc)(level,value, id, parentTag);
            if (hret.get() != nullptr)
            {
                return hret;
            }
        }
        if (nodeutils::isTagHasNoChidren(tag))
        {
            return std::make_shared<gedcomline>(level, tag, value, id);
        }
        else if (!parentTag.empty())
        {
            if (!nodeutils::canHaveChild(parentTag, tag))
            {
                return hret;
            }
        }
        //
        if (hret.get() == nullptr)
        {
            hret = std::make_shared<multinode>(level, tag, value, id);
        }
        return hret;
    } // createNode
    node::nodePtr createnode::createNode(const tokensLine::tokensLinesList &lines, multinode *parent)
    {
        node::nodePtr record;
        auto it = lines.begin();
        if (it == lines.end())
        {
            return record;
        }
        const tokensLine &tokens = *it++;
        const int level = tokens.getLevel();
        const string &tag = tokens.getTag();
        const string &value = tokens.getValue();
        node *pNode = nullptr;
        if (parent != nullptr)
        {
            pNode = parent->getChild(tag, value);
            if (pNode == nullptr)
            {
                std::cerr << "Failed to create (add child)" << std::endl;
                std::cerr << "Parent tag: " << parent->getTag() << std::endl;
                std::cerr << "Level: " << level << std::endl;
                std::cerr << "Tag: " << tag << std::endl;
                std::cerr << "Value: " << value << std::endl;
                return record;
            }
            auto &children = parent->getChildren();
            for (auto &n : children)
            {
                if (n.get() == pNode)
                {
                    record = n;
                    break;
                }
            }
            if (record.get() == nullptr)
            {
                std::cerr << "Failed to create (child not found)" << std::endl;
                std::cerr << "Parent tag: " << parent->getTag() << std::endl;
                std::cerr << "Level: " << level << std::endl;
                std::cerr << "Tag: " << tag << std::endl;
                std::cerr << "Value: " << value << std::endl;
                record.reset();
                return record;
            }
        }
        else
        {
            const string &id = tokens.getId();
            record = createnode::createNode(level, tag, value, id);
            pNode = record.get();
            if (pNode == nullptr)
            {
                std::cerr << "Failed to create" << std::endl;
                std::cerr << "Level: " << level << std::endl;
                std::cerr << "Tag: " << tag << std::endl;
                std::cerr << "Value: " << value << std::endl;
                std::cerr << "Id: " << id << std::endl
                          << std::endl;
                record.reset();
                return record;
            }
        }
        multinode *pm = dynamic_cast<multinode *>(pNode);
        if (pm == nullptr || it == lines.end())
        {
            return record;
        }
        const int itemAddLevel = level + 1;
        while (it != lines.end() && (*it).getLevel() > level)
        {
            if ((*it).getLevel() == itemAddLevel)
            {
                auto startIt = it++;
                while (it != lines.end() && (*it).getLevel() > itemAddLevel)
                {
                    ++it;
                }
                tokensLine::tokensLinesList ores(startIt, it);
                assert(!ores.empty());
                node::nodePtr child = createnode::createNode(ores, pm);
                node *pChild = child.get();
                if (pChild == nullptr)
                {
                    std::cerr << "Failed to create child" << std::endl;
                    std::cerr << "Parent tag: " << tag << std::endl;
                    std::cerr << "Level: " << (*startIt).getLevel() << std::endl;
                    std::cerr << "Tag: " << (*startIt).getTag() << std::endl;
                    std::cerr << "Value: " << (*startIt).getValue() << std::endl;
                    std::cerr << "Id: " << (*startIt).getId() << std::endl
                              << std::endl;
                }
            }
            else
            {
                ++it;
            }
        } // while
        return record;
    } // createNode
    node::nodePtr createnode::createNode(istream &in, multinode *parent)
    {
        tokensLine::tokensLinesList lines;
        tokensLine::parseStream(in, lines);
        return createnode::createNode(lines, parent);
    } // createNode
    node::nodePtr createnode::createNode(const string &linesString, multinode *parent)
    {
        stringstream in(linesString);
        return createnode::createNode(in, parent);
    } // createNode
    //////////////////////////////////
} // namespace infoged