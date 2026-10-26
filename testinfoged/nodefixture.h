#pragma once
#ifndef TESTINFOGED_NODEFIXTURE_H
#define TESTINFOGED_NODEFIXTURE_H
///////////////////////////////
#include "fixture.h"
//////////////////////////////
#include <node.h>
#include <multinode.h>
#include <gedconstants.h>
//////////////////////////////
namespace infoged
{
    namespace test
    {
        /////////////////////////////
        class nodefixture : public fixture
        {
        private:
            nodefixture();
            nodefixture(const nodefixture &other) = delete;
            nodefixture &operator=(const nodefixture &other) = delete;

        public:
            ~nodefixture();
            static const nodefixture &getInstance(void);

        public:
            std::shared_ptr<node> createFromStream(istream &is) const;
            std::shared_ptr<node> createNode(const string &data) const;
            template <typename T>
            std::pair<const T *, std::shared_ptr<node>> createTagNode(const string &data, const string &tag) const
            {
                static_assert(std::is_base_of<node, T>::value, "T must be derived from node");
                std::shared_ptr<node> hh = createNode(data);
                node *pNode = hh.get();
                if (pNode == nullptr)
                {
                    return std::make_pair(nullptr, hh);
                }
                multinode *pMut = dynamic_cast<multinode *>(pNode);
                if (pMut == nullptr)
                {
                    return std::make_pair(nullptr, hh);
                }
                const node *pTagNode = pMut->findChild(tag);
                if (pTagNode == nullptr)
                {
                    return std::make_pair(nullptr, hh);
                }
                const T *pRet = dynamic_cast<const T *>(pTagNode);
                return std::make_pair(pRet, hh);
            } // template <typename T>
        }; // class nodefixture
    } // namespace test
} // namespace infoged
//////////////////////////////
#endif // TESTINFOGED_NODEFIXTURE_H
