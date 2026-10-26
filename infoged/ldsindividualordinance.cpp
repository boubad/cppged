
#include "ldsindividualordinance.h"
//////////////////////////////////
#include "indivordinance.h"
#include "multinode.h"
#include "gedconstants.h"
//////////////////////////////////
namespace infoged
{
    ldsindividualordinance::ldsindividualordinance(multinode *proxy) : proxynode(proxy)
    {
    }
    ldsindividualordinance::ldsindividualordinance(const ldsindividualordinance &other) : proxynode(other)
    {
    }
    ldsindividualordinance &ldsindividualordinance::operator=(const ldsindividualordinance &other)
    {
        if (this != &other)
        {
            proxynode::operator=(other);
        }
        return *this;
    }
    ldsindividualordinance::~ldsindividualordinance()
    {
    }
    ////////////////////////////////////////////////////
    bool ldsindividualordinance::getBaplOrdinance(individualordinance &detail)
    {
        node *node = getProxy()->getChild(gedconstants::GED_BAPL);
        if (node != nullptr)
        {
            multinode *pnode = dynamic_cast<multinode *>(node);
            if (pnode != nullptr)
            {
                detail = individualordinance(pnode);
                return true;
            }
        }
        return false;
    } // getBaplOrdinance
    bool ldsindividualordinance::getConlOrdinance(individualordinance &detail)
    {
        node *node = getProxy()->getChild(gedconstants::GED_CONL);
        if (node != nullptr)
        {
            multinode *pnode = dynamic_cast<multinode *>(node);
            if (pnode != nullptr)
            {
                detail = individualordinance(pnode);
                return true;
            }
        }
        return false;
    } // getConlOrdinance
    bool ldsindividualordinance::getEndlOrdinance(individualordinance &detail)
    {
        node *node = getProxy()->getChild(gedconstants::GED_ENDL);
        if (node != nullptr)
        {
            multinode *pnode = dynamic_cast<multinode *>(node);
            if (pnode != nullptr)
            {
                detail = individualordinance(pnode);
                return true;
            }
            return true;
        }
        return false;
    } // getEndlOrdinance
    bool ldsindividualordinance::getSlgcOrdinance(individualordinance &detail)
    {
        node *node = getProxy()->getChild(gedconstants::GED_SLGC);
        if (node != nullptr)
        {
            multinode *pnode = dynamic_cast<multinode *>(node);
            if (pnode != nullptr)
            {
                detail = individualordinance(pnode);
                return true;
            }
            return true;
        }
        return false;
    } // getSlgcOrdinance
    ////////////////////////////////////////////////////
} // namespace infoged
