
/////////////////////////
#include "individualeventstructure.h"
/////////////////////////
#include "individualeventdetail.h"
#include "multinode.h"
#include "gedconstants.h"
///////////////////////////
#include <cassert>
///////////////////////////
namespace infoged
{
    individualeventstructure::individualeventstructure(multinode *proxy) : proxynode(proxy)
    {
    }
    individualeventstructure::individualeventstructure(const individualeventstructure &other) : proxynode(other)
    {
    }
    individualeventstructure &individualeventstructure::operator=(const individualeventstructure &other)
    {
        if (this != &other)
        {
            proxynode::operator=(other);
        }
        return *this;
    }
    individualeventstructure::~individualeventstructure()
    {
    }
    bool individualeventstructure::getDetail(const string &tag, individualeventdetail &detail)
    {
        const node *node = getProxy()->findChild(tag);
        if (node != nullptr)
        {
            const multinode *px = dynamic_cast<const multinode *>(node);
            if (px != nullptr)
            {
                multinode *pCurrent = const_cast<multinode *>(px);
                detail = individualeventdetail(pCurrent);
                return true;
            }
        }
        return false;
    }
    /////////////////////////////////////
    string individualeventstructure::getBirth(void) const
    {
        return getChildValue(gedconstants::GED_BIRT);
    }
    void individualeventstructure::setBirth(const string &value)
    {
        setChildValue(gedconstants::GED_BIRT, value);
    }
    bool individualeventstructure::getBirthDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_BIRT, detail);
    }
    string individualeventstructure::getBirthFamilyReference(void) const
    {
        return getChildValue(gedconstants::GED_BIRT, gedconstants::GED_FAMC);
    }
    void individualeventstructure::setBirthFamilyReference(const string &value)
    {
        setChildValue(gedconstants::GED_BIRT, gedconstants::GED_FAMC, value);
    }
    //
    string individualeventstructure::getChr(void) const
    {
        return getChildValue(gedconstants::GED_CHR);
    }
    void individualeventstructure::setChr(const string &value)
    {
        setChildValue(gedconstants::GED_CHR, value);
    }
    bool individualeventstructure::getChrDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_CHR, detail);
    }
    string individualeventstructure::getChrFamilyReference(void) const
    {
        return getChildValue(gedconstants::GED_CHR, gedconstants::GED_FAMC);
    }
    void individualeventstructure::setChrFamilyReference(const string &value)
    {
        setChildValue(gedconstants::GED_CHR, gedconstants::GED_FAMC, value);
    }
    //
    string individualeventstructure::getDeath(void) const
    {
        return getChildValue(gedconstants::GED_DEAT);
    }
    void individualeventstructure::setDeath(const string &value)
    {
        setChildValue(gedconstants::GED_DEAT, value);
    }
    bool individualeventstructure::getDeathDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_DEAT, detail);
    }
    //
    bool individualeventstructure::getBurialDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_BURI, detail);
    }
    bool individualeventstructure::getCremationDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_CREM, detail);
    }
    //
    bool individualeventstructure::getAdoptionDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_ADOP, detail);
    }
    string individualeventstructure::getAdoptionFamilyReference(void) const
    {
        return getChildValue(gedconstants::GED_ADOP, gedconstants::GED_FAMC);
    }
    void individualeventstructure::setAdoptionFamilyReference(const string &value)
    {
        setChildValue(gedconstants::GED_ADOP, gedconstants::GED_FAMC, value);
    }
    string individualeventstructure::getAdoptionAdoptedByWich(void) const
    {
        return getChildValue(gedconstants::GED_ADOP, gedconstants::GED_FAMC, gedconstants::GED_ADOP);
    }
    void individualeventstructure::setAdoptionAdoptedByWich(const string &value)
    {
        setChildValue(gedconstants::GED_ADOP, gedconstants::GED_FAMC, gedconstants::GED_ADOP, value);
    }
    //
    bool individualeventstructure::getBapmDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_BAPM, detail);
    }
    bool individualeventstructure::getBarmDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_BARM, detail);
    }

    bool individualeventstructure::getBasmDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_BASM, detail);
    }

    bool individualeventstructure::getBlesDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_BLES, detail);
    }
    bool individualeventstructure::getChraDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_CHRA, detail);
    }
    bool individualeventstructure::getConfDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_CONF, detail);
    }
    bool individualeventstructure::getFcomDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_FCOM, detail);
    }
    bool individualeventstructure::getOrdnDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_ORDN, detail);
    }
    bool individualeventstructure::getNatuDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_NATU, detail);
    }
    bool individualeventstructure::getEmigDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_EMIG, detail);
    }
    bool individualeventstructure::getImmiDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_IMMI, detail);
    }
    bool individualeventstructure::getCensDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_CENS, detail);
    }
    bool individualeventstructure::getProbDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_PROB, detail);
    }
    bool individualeventstructure::getWillDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_WILL, detail);
    }
    bool individualeventstructure::getGradDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_GRAD, detail);
    }
    bool individualeventstructure::getRetiDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_RETI, detail);
    }
    bool individualeventstructure::getOtherEventDetails(std::list<individualeventdetail> &details)
    {
        details.clear();
        auto &col = getProxy()->getChildren();
        for (auto &p : col)
        {
            if (p->getTag() == gedconstants::GED_EVEN)
            {
                multinode *px = dynamic_cast<multinode *>(p.get());
                if (px != nullptr)
                {
                    individualeventdetail detail(px);
                    details.push_back(detail);
                }
            }
        }
        return !details.empty();
    }
    bool individualeventstructure::createOtherEventDetail(individualeventdetail &detail)
    {
        node *p = getProxy()->getChild(gedconstants::GED_EVEN);
        if (p != nullptr)
        {
            multinode *px = dynamic_cast<multinode *>(p);
            if (px != nullptr)
            {
                detail = individualeventdetail(px);
                return true;
            }
        }
        return false;
    }
    //////////////////////////////////////
} // namespace infoged
