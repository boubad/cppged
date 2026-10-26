
#include "indivordinance.h"
/////////////////////////////
#include "sourcecitation.h"
#include "notestructure.h"
#include "gedconstants.h"
///////////////////////////
namespace infoged
{
    individualordinance::individualordinance(multinode *proxy) : proxynode(proxy)
    {
    }

    individualordinance::individualordinance(const individualordinance &other) : proxynode(other)
    {
    }
    individualordinance &individualordinance::operator=(const individualordinance &other)
    {
        if (this != &other)
        {
            proxynode::operator=(other);
        }
        return *this;
    }
    individualordinance::~individualordinance()
    {
    }
    ////////////////////////////////
    string individualordinance::getDateLdsOrd(void) const
    {
        return getChildValue(gedconstants::GED_DATE);
    }
    void individualordinance::setDateLdsOrd(const string &dateLdsOrd)
    {
        setChildValue(gedconstants::GED_DATE, dateLdsOrd);
    }
    string individualordinance::getTempleCode(void) const
    {
        return getChildValue(gedconstants::GED_TEMP);
    }
    void individualordinance::setTempleCode(const string &templeCode)
    {
        setChildValue(gedconstants::GED_TEMP, templeCode);
    }
    string individualordinance::getPlaceLivingOrdinance(void) const
    {
        return getChildValue(gedconstants::GED_PLAC);
    }
    void individualordinance::setPlaceLivingOrdinance(const string &placeLivingOrdinance)
    {
        setChildValue(gedconstants::GED_PLAC, placeLivingOrdinance);
    }

    string individualordinance::getFamilyReference(void) const
    {
        return getChildValue(gedconstants::GED_FAMC);
    }
    void individualordinance::setFamilyReference(const string &famcid)
    {
        setChildValue(gedconstants::GED_FAMC, famcid);
    }
    string individualordinance::getLdsStatus(void) const
    {
        return getChildValue(gedconstants::GED_STAT);
    }
    void individualordinance::setLdsStatus(const string &ldsStatus)
    {
        setChildValue(gedconstants::GED_STAT, ldsStatus);
    }
    string individualordinance::getLdsStatusDate(void) const
    {

        return getChildValue(gedconstants::GED_STAT, gedconstants::GED_DATE);
    }
    void individualordinance::setLdsStatusDate(const string &ldsStatusDate)
    {
        setChildValue(gedconstants::GED_STAT, gedconstants::GED_DATE, ldsStatusDate);
    }
    const sourcecitation *individualordinance::findSourceCitation() const
    {
        return getProxy()->findChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    sourcecitation *individualordinance::getSourceCitation()
    {
        return getProxy()->getChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    const notestructure *individualordinance::findNote() const
    {
        return getProxy()->findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *individualordinance::getNote()
    {
        return getProxy()->getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    ////////////////////////////////
} // namespace infoged