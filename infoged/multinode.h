#pragma once
#ifndef multinode_H__
#define multinode_H__
//////////////////////////
#include "datanode.h"
//////////////////////////
namespace infoged
{
    class multinode : public datanode
    {
    public:
        multinode(int level = -1, const string &tag = string(),
                  const string &value = string(), const string &id = string());
        multinode(const multinode &other);
        multinode &operator=(const multinode &other);
        virtual ~multinode();

    public:
        virtual const nodePtrList &getChildren(void) const;
        virtual nodePtrList &getChildren(void);
        virtual const node *findChild(const string &tag) const;
        virtual node *getChild(const string &tag,
                               const string &value = string(),
                               bool bfront = false);

    public:
        void setChildren(const multinode &other);
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
        template <typename T>
        const T *findChildNodeByTag(const string &tag) const
        {
            static_assert(std::is_base_of<node, T>::value,
                          "T must be derived from node");
            const node *p = findChild(tag);
            if (p == nullptr)
            {
                return nullptr;
            }
            return dynamic_cast<const T *>(p);
        } // findChildNodeByTag
        template <typename T>
        T *getChildNodeByTag(const string &tag)
        {
            static_assert(std::is_base_of<node, T>::value,
                          "T must be derived from node");
            node *p = getChild(tag);
            if (p == nullptr)
            {
                return nullptr;
            }
            return dynamic_cast<T *>(p);
        } // getSingleRecordByTag
        template <typename T>
        bool getAllNodes(std::list<T> &records) const
        {
            static_assert(std::is_base_of<node, T>::value,
                          "T must be derived from Node");
            const auto &children = getChildren();
            records.clear();
            for (const auto &o : children)
            {
                const T *px = dynamic_cast<const T *>(o.get());
                if (px != nullptr)
                {
                    T item(*px);
                    records.push_back(item);
                }
            }
            return !records.empty();
        } // getAllRecordsByTag
    public:
        virtual void setLevel(int level) override;
        virtual nodetype getType(void) const override;
        virtual void check(void) override;
        virtual ostream &write(ostream &os) const override;
        virtual void clear(void) override;
        virtual void mutate(const std::function<void(node *)> &func) override;
        virtual void visit(const std::function<void(const node *)> &func) const override;
        virtual void remove(const std::function<bool(const node *)> &func) override;
    private:
        nodePtrList m_nodes;
    }; // class multinode
} // namespace infoged
#endif // multinode_H__