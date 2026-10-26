
#include "ldsspousesealing.h"
//////////////////////////////
#include "sourcecitation.h"
#include "changedate.h"
#include "notestructure.h"
#include "gedconstants.h"
//////////////////////////
namespace infoged
{
    ldsspousesealing::ldsspousesealing(int level) : multinode(level, gedconstants::GED_SLGC)
    {
    }
    ldsspousesealing::ldsspousesealing(const ldsspousesealing &other) : multinode(other)
    {
    }
    ldsspousesealing &ldsspousesealing::operator=(const ldsspousesealing &other)
    {
        if (this != &other)
        {
            multinode::operator=(other);
        }
        return *this;
    }
    ldsspousesealing::~ldsspousesealing()
    {
    }
    //////////////////////////
    string ldsspousesealing::getDate(void) const
    {
        return getChildValue(gedconstants::GED_DATE);
    }
    void ldsspousesealing::setDate(const string &date)
    {
        setChildValue(gedconstants::GED_DATE, date);
    }
    string ldsspousesealing::getTempleCode(void) const
    {
        return getChildValue(gedconstants::GED_TEMP);
    }
    void ldsspousesealing::setTempleCode(const string &templeCode)
    {
        setChildValue(gedconstants::GED_TEMP, templeCode);
    }
    string ldsspousesealing::getPlaceLivingOrdinance(void) const
    {
        return getChildValue(gedconstants::GED_PLAC);
    }
    void ldsspousesealing::setPlaceLivingOrdinance(const string &placeLivingOrdinance)
    {
        setChildValue(gedconstants::GED_PLAC, placeLivingOrdinance);
    }
    string ldsspousesealing::getLesSpouseSealingDateStatus(void) const
    {
        return getChildValue(gedconstants::GED_STAT);
    }
    void ldsspousesealing::setLesSpouseSealingDateStatus(const string &lesSpouseSealingDateStatus)
    {
        setChildValue(gedconstants::GED_STAT, lesSpouseSealingDateStatus);
    }
    string ldsspousesealing::getStatusDate(void) const
    {
        return getChildValue(gedconstants::GED_STAT, gedconstants::GED_DATE);
    }
    void ldsspousesealing::setStatusDate(const string &statusDate)
    {
        setChildValue(gedconstants::GED_STAT, gedconstants::GED_DATE, statusDate);
    }
    const notestructure *ldsspousesealing::findNote() const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *ldsspousesealing::getNote()
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    const sourcecitation *ldsspousesealing::findSourceCitation() const
    {
        return findChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    sourcecitation *ldsspousesealing::getSourceCitation()
    {
        return getChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    /////////////////////////////////
    bool ldsspousesealing::isValid(void) const
    {
        return multinode::isValid() && getTag() == gedconstants::GED_SLGC;
    }
    nodetype ldsspousesealing::getType(void) const
    {
        return nodetype::LdsSpouseSealing;
    }
    /////////////////////////////////
} // namespace infoged
