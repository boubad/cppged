
////////////////////////////
#include "personalnamestructure.h"
////////////////////////////
#include "stringconstants.h"
#include "personalnamepieces.h"
#include "gedconstants.h"
///////////////////////////
namespace infoged
{ //////////////////////////
    personalnamestructure::personalnamestructure(int level, const string &name)
        : multinode(level, gedconstants::GED_NAME, name)
    {
    }
    personalnamestructure::personalnamestructure(const personalnamestructure &other) : multinode(other)
    {
    }
    personalnamestructure &personalnamestructure::operator=(const personalnamestructure &other)
    {
        if (this != &other)
        {
            multinode::operator=(other);
        }
        return *this;
    }
    //////////////////////////
    personalnamestructure::~personalnamestructure()
    {
    }
    /////////////////////////////
    string personalnamestructure::getName(void) const
    {
        return getValue();
    }
    void personalnamestructure::setName(const string &name)
    {
        setValue(name);
    }
    string personalnamestructure::getNameType(void) const
    {
        return getChildValue(gedconstants::GED_TYPE);
    }
    void personalnamestructure::setNameType(const string &nameType)
    {
        setChildValue(gedconstants::GED_TYPE, nameType);
    }

    void personalnamestructure::getNamePieces(personalnamepieces &namePieces)
    {
        namePieces = personalnamepieces(this);
    }
    /////////////////////////
    string personalnamestructure::getNamePhoneticVariation(void) const
    {
        return getChildValue(gedconstants::GED_FONE);
    }
    void personalnamestructure::setNamePhoneticVariation(const string &namePhoneticVariation)
    {
        setChildValue(gedconstants::GED_FONE, namePhoneticVariation);
    }
    string personalnamestructure::getPhoneticType(void) const
    {
        return getChildValue(gedconstants::GED_FONE, gedconstants::GED_TYPE);
    }
    void personalnamestructure::setPhoneticType(const string &phoneticType)
    {
        setChildValue(gedconstants::GED_FONE, gedconstants::GED_TYPE, phoneticType);
    }
    bool personalnamestructure::getPhoneticNamePieces(personalnamepieces &namePieces)
    {
        const node *parent = findChild(gedconstants::GED_FONE);
        if (parent != nullptr)
        {
            multinode *px = dynamic_cast<multinode *>(const_cast<node *>(parent));
            if (px != nullptr)
            {
                namePieces = personalnamepieces(px);
                return true;
            }
        }
        return false;
    }
    //
    string personalnamestructure::getRomanizedVariation(void) const
    {
        return getChildValue(gedconstants::GED_ROMN);
    }
    void personalnamestructure::setRomanizedVariation(const string &romanizedVariation)
    {
        setChildValue(gedconstants::GED_ROMN, romanizedVariation);
    }
    string personalnamestructure::getRomanizedType(void) const
    {
        return getChildValue(gedconstants::GED_ROMN, gedconstants::GED_TYPE);
    }
    void personalnamestructure::setRomanizedType(const string &romanizedType)
    {
        setChildValue(gedconstants::GED_ROMN, gedconstants::GED_TYPE, romanizedType);
    }
    bool personalnamestructure::getRomanizedNamePieces(personalnamepieces &namePieces)
    {
        const node *parent = findChild(gedconstants::GED_ROMN);
        if (parent != nullptr)
        {
            multinode *px = dynamic_cast<multinode *>(const_cast<node *>(parent));
            if (px != nullptr)
            {
                namePieces = personalnamepieces(px);
                return true;
            }
        }
        return false;
    }
    //////////////////////////
    nodetype personalnamestructure::getType(void) const
    {
        return nodetype::PersonalName;
    }
    bool personalnamestructure::isValid(void) const
    {
        return multinode::isValid() && getTag() == gedconstants::GED_NAME;
    }
    /////////////////////////////
} // namespace infoged
