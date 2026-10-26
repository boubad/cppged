#pragma once
#ifndef DATANODE_H
#define DATANODE_H
///////////////////////
#include "linedata.h"
#include "node.h"
/////////////////
namespace infoged
{
    class datanode : public node, public linedata
    {
    public:
        datanode(int level = -1, const string &tag = string(), const string &value = string(), const string &id = string());
        datanode(const datanode &other);
        datanode &operator=(const datanode &other);
        virtual ~datanode();

    public:
        virtual int getLevel(void) const override;
        virtual void setLevel(int level) override;
        virtual const string &getId(void) const override;
        virtual multinode *getParent(void) const override;
        virtual void setParent(multinode *p) override;
        virtual status getStatus(void) const override;
        virtual void setStatus(status st) override;
        virtual nodetype getType(void) const override;
        virtual const string &getTag(void) const override;
        virtual const string &getValue(void) const override;
        virtual void setValue(const string &value) override;
        virtual bool isValid(void) const override;
        virtual void check(void) override;
        virtual ostream &write(ostream &os) const override;
        virtual string getLineString(void) const override;
        virtual void clear(void) override;
        virtual void mutate(const std::function<void(node *)> &func) override;
        virtual void visit(const std::function<void(const node *)> &func) const override;
        //
    };
} // namespace infoged

#endif // GEDCOMLINE_H
