#pragma once
#ifndef CREATENODE_H__
#define CREATENODE_H__
///////////////////////
#include "token.h"
#include "node.h"
///////////////////////
namespace infoged
{
    class multinode;
    class createnode
    {
    public:
        static node::nodePtr createNode(int level,
                                        const string &tag,
                                        const string &value = string(),
                                        const string &id = string(),
                                        const string &parentTag = string());
        static node::nodePtr createNode(const tokensLine::tokensLinesList &lines,
                                        multinode *parent = nullptr);
        static node::nodePtr createNode(istream &in, multinode *parent = nullptr);
        static node::nodePtr createNode(const string &linesString, multinode *parent = nullptr);
    }; // class createnode
} // namespace infoged
//////////////////////////
#endif // CREATENODE_H__