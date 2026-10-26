
#include "repositoryrecord.h"
#include "changedate.h"
#include "notestructure.h"
#include "addressstructure.h"
#include "gedconstants.h"
///////////////////////////
namespace infoged
{
    repositoryrecord::repositoryrecord(const string &id) : entitynode(gedconstants::GED_REPO, id)
    {
    }
    repositoryrecord::repositoryrecord(const repositoryrecord &other) : entitynode(other)
    {
    }
    repositoryrecord &repositoryrecord::operator=(const repositoryrecord &other)
    {
        if (this != &other)
        {
            entitynode::operator=(other);
        }
        return *this;
    }
    repositoryrecord::~repositoryrecord()
    {
    }
    //////////////////////////
    string repositoryrecord::getNameOfRepository(void) const
    {
        return getChildValue(gedconstants::GED_NAME);
    }
    void repositoryrecord::setNameOfRepository(const string &name)
    {
        setChildValue(gedconstants::GED_NAME, name);
    }
    const addressstructure *repositoryrecord::findAddress() const
    {
        return findChildNodeByTag<addressstructure>(gedconstants::GED_ADDR);
    }
    addressstructure *repositoryrecord::getAddress()
    {
        return getChildNodeByTag<addressstructure>(gedconstants::GED_ADDR);
    }
    const notestructure *repositoryrecord::findNote() const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *repositoryrecord::getNote()
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    string repositoryrecord::getUserReferenceNumber(void) const
    {
        return getChildValue(gedconstants::GED_REFN);
    }
    void repositoryrecord::setUserReferenceNumber(const string &userReferenceNumber)
    {
        setChildValue(gedconstants::GED_REFN, userReferenceNumber);
    }
    string repositoryrecord::getUserReferenceType(void) const
    {
        return getChildValue(gedconstants::GED_REFN, gedconstants::GED_TYPE);
    }
    void repositoryrecord::setUserReferenceType(const string &userReferenceType)
    {
        setChildValue(gedconstants::GED_REFN, gedconstants::GED_TYPE, userReferenceType);
    }
    string repositoryrecord::getAutomatedRecordId(void) const
    {
        return getChildValue(gedconstants::GED_RIN);
    }
    void repositoryrecord::setAutomatedRecordId(const string &automatedRecordId)
    {
        setChildValue(gedconstants::GED_RIN, automatedRecordId);
    }
    const changedate *repositoryrecord::findChangedate(void) const
    {
        return findChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }
    changedate *repositoryrecord::getChangedate()
    {
        return getChildNodeByTag<changedate>(gedconstants::GED_CHAN);
    }

    ////////////////////////////
    nodetype repositoryrecord::getType(void) const
    {
        return nodetype::Repository;
    }
    bool repositoryrecord::isValid() const
    {
        if (getTag() != gedconstants::GED_REPO || !entitynode::isValid())
        {
            return false;
        }
        string name = getNameOfRepository();
        return !name.empty();
    }
    void repositoryrecord::check(void)
    {
        entitynode::check();
        string name = getNameOfRepository();
        if (name.empty())
        {
            if (getStatus() == status::Normal)
            {
                setStatus(status::IncorrectData);
            }
        }
    }
    ////////////////////////////

} // namespace infoged
