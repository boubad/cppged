
////////////////////////
#include "place.h"
//////////////////////
#include "notestructure.h"
#include "gedconstants.h"
/////////////////////////
namespace infoged
{
    ///////////////////////////////////
    place::place(int level, const string &placeName) : multinode(level, gedconstants::GED_PLAC, placeName)
    {
    }
    place::place(const place &other) : multinode(other)
    {
    }
    place &place::operator=(const place &other)
    {
        if (this != &other)
        {
            multinode::operator=(other);
        }
        return *this;
    }
    place::~place()
    {
    }
    /////////////////////////
    string place::getName(void) const
    {
        return getValue();
    }
    void place::setName(const string &placeName)
    {
        setValue(placeName);
    }
    string place::getHierachy(void) const
    {
        return getChildValue(gedconstants::GED_FORM);
    }
    void place::setHierachy(const string &placeHierachy)
    {
        setChildValue(gedconstants::GED_FORM, placeHierachy);
    }
    string place::getLatitude(void) const
    {
        return getChildValue(gedconstants::GED_MAP, gedconstants::GED_LATI);
    }
    void place::setLatitude(const string &placeLatitude)
    {
        setChildValue(gedconstants::GED_MAP, gedconstants::GED_LATI, placeLatitude);
    }
    string place::getLongitude(void) const
    {
        return getChildValue(gedconstants::GED_MAP, gedconstants::GED_LONG);
    }
    void place::setLongitude(const string &placeLongitude)
    {
        setChildValue(gedconstants::GED_MAP, gedconstants::GED_LONG, placeLongitude);
    }
    string place::getPhoneticVariation(void) const
    {
        return getChildValue(gedconstants::GED_FONE);
    }
    void place::setPhoneticVariation(const string &phoneticVariation)
    {
        setChildValue(gedconstants::GED_FONE, phoneticVariation);
    }
    string place::getPhoneticVariationType(void) const
    {
        return getChildValue(gedconstants::GED_FONE, gedconstants::GED_TYPE);
    }

    void place::setPhoneticVariationType(const string &phoneticVariationType)
    {
        setChildValue(gedconstants::GED_PHON, gedconstants::GED_TYPE,
                      phoneticVariationType);
    }
    string place::getRomanizedVariation(void) const
    {
        return getChildValue(gedconstants::GED_ROMN);
    }
    void place::setRomanizedVariation(const string &romanizedVariation)
    {
        setChildValue(gedconstants::GED_ROMN, romanizedVariation);
    }
    string place::getRomanizedVariationType(void) const
    {
        return getChildValue(gedconstants::GED_ROMN, gedconstants::GED_TYPE);
    }
    void place::setRomanizedVariationType(const string &romanizedVariationType)
    {
        setChildValue(gedconstants::GED_ROMN,
                      gedconstants::GED_TYPE, romanizedVariationType);
    }
    const notestructure *place::findNote(void) const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *place::getNote(void)
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    bool place::isValid(void) const
    {
        string name = getName();
        if (name.empty())
        {
            return false;
        }
        return multinode::isValid() && getTag() == gedconstants::GED_PLAC;
    }
    void place::check(void)
    {
        multinode::check();
        string name = getName();
        if (name.empty())
        {
            if (getStatus() == status::Normal)
            {
                setStatus(status::IncorrectData);
            }
        }
    }
    nodetype place::getType(void) const
    {
        return nodetype::Place;
    }
    //////////////////////////////////////

} // namespace infoged
