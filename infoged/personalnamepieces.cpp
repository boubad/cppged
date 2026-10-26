
#include "personalnamepieces.h"
////////////////////////////////
#include "notestructure.h"
#include "sourcecitation.h"
#include "gedconstants.h"
////////////////////////
namespace infoged
{
    personalnamepieces::personalnamepieces(multinode *proxy) : proxynode(proxy)
    {
    }
    personalnamepieces::personalnamepieces(const personalnamepieces &other) : proxynode(other)
    {
    }
    personalnamepieces &personalnamepieces::operator=(const personalnamepieces &other)
    {
        if (this != &other)
        {
            proxynode::operator=(other);
        }
        return *this;
    }
    //////////////////////////
    personalnamepieces::~personalnamepieces()
    {
    }
    /////////////////////////////
    string personalnamepieces::getNamePrefix(void) const
    {
        return getChildValue(gedconstants::GED_NPFX);
    }
    void personalnamepieces::setNamePrefix(const string &prefix)
    {
        setChildValue(gedconstants::GED_NPFX, prefix);
    }
    string personalnamepieces::getNameGiven(void) const
    {

        return getChildValue(gedconstants::GED_GIVN);
    }
    void personalnamepieces::setNameGiven(const string &given)
    {
        setChildValue(gedconstants::GED_GIVN, given);
    }
    string personalnamepieces::getNameNickname(void) const
    {
        return getChildValue(gedconstants::GED_NICK);
    }
    void personalnamepieces::setNameNickname(const string &nickname)
    {
        setChildValue(gedconstants::GED_NICK, nickname);
    }
    string personalnamepieces::getNameSurname(void) const
    {
        return getChildValue(gedconstants::GED_SURN);
    }
    void personalnamepieces::setNameSurname(const string &surname)
    {
        setChildValue(gedconstants::GED_SURN, surname);
    }
    string personalnamepieces::getNameSuffix(void) const
    {
        return getChildValue(gedconstants::GED_NSFX);
    }
    void personalnamepieces::setNameSuffix(const string &suffix)
    {
        setChildValue(gedconstants::GED_NSFX, suffix);
    }
    //////////////////////////
    const notestructure *personalnamepieces::findNote(void) const
    {
        return getProxy()->findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *personalnamepieces::getNote()
    {
        return getProxy()->getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    const sourcecitation *personalnamepieces::findSourceCitation(void) const
    {
        return getProxy()->findChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    sourcecitation *personalnamepieces::getSourceCitation()
    {
        return getProxy()->getChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    /////////////////////////////
} // namespace infoged