
#include "familyeventstructure.h"
/////////////////////////////
#include "multinode.h"
#include "familyeventdetail.h"
#include "gedconstants.h"
////////////////////////////
#include <cassert>
//////////////////////////////////
namespace infoged
{
    familyeventstructure::familyeventstructure(multinode *proxy) : proxynode(proxy)
    {
    }
    familyeventstructure::familyeventstructure(const familyeventstructure &other) : proxynode(other)
    {
    }
    familyeventstructure &familyeventstructure::operator=(const familyeventstructure &other)
    {
        if (this != &other)
        {
            proxynode::operator=(other);
        }
        return *this;
    }
    familyeventstructure::~familyeventstructure()
    {
    }
    bool familyeventstructure::getDetail(const string &tag, familyeventdetail &detail)
    {
        const node *node = getProxy()->findChild(tag);
        if (node == nullptr)
        {
            return false;
        }
        const multinode *px = dynamic_cast<const multinode *>(node);
        if (px != nullptr)
        {
            multinode *pCurrent = const_cast<multinode *>(px);
            detail = familyeventdetail(pCurrent);
            return true;
        }
        return false;
    } // getDetail
    ///////////////////////
    bool familyeventstructure::getAnul(familyeventdetail &detail)
    {
        return getDetail(gedconstants::GED_ANUL, detail);
    }
    bool familyeventstructure::getCens(familyeventdetail &detail)
    {
        return getDetail(gedconstants::GED_CENS, detail);
    }
    bool familyeventstructure::getDiv(familyeventdetail &detail)
    {
        return getDetail(gedconstants::GED_DIV, detail);
    }
    bool familyeventstructure::getDivf(familyeventdetail &detail)
    {
        return getDetail(gedconstants::GED_DIVF, detail);
    }
    bool familyeventstructure::getEnga(familyeventdetail &detail)
    {
        return getDetail(gedconstants::GED_ENGA, detail);
    }
    bool familyeventstructure::getMarb(familyeventdetail &detail)
    {
        return getDetail(gedconstants::GED_MARB, detail);
    }
    bool familyeventstructure::getMarc(familyeventdetail &detail)
    {
        return getDetail(gedconstants::GED_MARC, detail);
    }
    string familyeventstructure::getMarrValue() const
    {
        return getChildValue(gedconstants::GED_MARR);
    }
    void familyeventstructure::setMarrValue(const string &value)
    {
        setChildValue(gedconstants::GED_MARR, value);
    }
    bool familyeventstructure::getMarr(familyeventdetail &detail)
    {
        return getDetail(gedconstants::GED_MARR, detail);
    }
    bool familyeventstructure::getMarl(familyeventdetail &detail)
    {
        return getDetail(gedconstants::GED_MARL, detail);
    }
    bool familyeventstructure::getMars(familyeventdetail &detail)
    {
        return getDetail(gedconstants::GED_MARS, detail);
    }
    bool familyeventstructure::getResi(familyeventdetail &detail)
    {
        return getDetail(gedconstants::GED_RESI, detail);
    }
    bool familyeventstructure::getOtherEvents(std::list<familyeventdetail> &details)
    {
        details.clear();
        const auto &children = getProxy()->getChildren();
        for (const auto &o : children)
        {
            node *p = o.get();
            assert(p != nullptr);
            const string &stag = p->getTag();
            if (stag == gedconstants::GED_EVEN)
            {
                multinode *px = dynamic_cast<multinode *>(p);
                if (px != nullptr)
                {
                    familyeventdetail detail(px);
                    details.push_back(detail);
                    continue;
                }
            }
        }
        return !details.empty();
    } // getOtherEvents
    bool familyeventstructure::getEvent(familyeventdetail &detail, const string &eventdescriptor)
    {
        const auto &children = getProxy()->getChildren();
        for (const auto &o : children)
        {
            node *p = o.get();
            assert(p != nullptr);
            if (p->getTag() == gedconstants::GED_EVEN && p->getValue() == eventdescriptor)
            {
                multinode *px = dynamic_cast<multinode *>(p);
                if (px != nullptr)
                {
                    detail = familyeventdetail(px);
                    return true;
                }
            }
        }
        node *p = getProxy()->getChild(gedconstants::GED_EVEN, eventdescriptor);
        if (p != nullptr)
        {
            multinode *px = dynamic_cast<multinode *>(p);
            if (px != nullptr)
            {
                detail = familyeventdetail(px);
                return true;
            }
        }
        return false;
    } // getEvent
    //////////////////////
}