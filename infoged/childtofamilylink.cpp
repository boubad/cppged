
/////////////////////////
#include "childtofamilylink.h"
/////////////////////////
#include "notestructure.h"
#include "gedconstants.h"
#include "stringutils.h"
/////////////////////////
namespace infoged
{
    /////////////////////////////////
    childtofamilylink::childtofamilylink(int level, const string &xref) : multinode(level, gedconstants::GED_FAMC, xref)
    {
    }
    childtofamilylink::childtofamilylink(const childtofamilylink &other) : multinode(other)
    {
    }
    childtofamilylink &childtofamilylink::operator=(const childtofamilylink &other)
    {
        if (this != &other)
        {
            multinode::operator=(other);
        }
        return *this;
    }
    childtofamilylink::~childtofamilylink()
    {
    }
    string childtofamilylink::getFamilyReference(void) const
    {
        string s = getValue();
        return stringutils::isPointer(s) ? s : string();
    }
    void childtofamilylink::setFamilyReference(const string &familyReference)
    {
        string s = stringutils::trim(familyReference);
        if (stringutils::isPointer(s))
        {
            setValue(s);
        }
        else
        {
            setValue(string());
        }
    }
    string childtofamilylink::getPedigreeLinkageType() const
    {
        return getChildValue(gedconstants::GED_PEDI);
    }
    void childtofamilylink::setPedigreeLinkageType(const string &pedigreLinkageType)
    {
        setChildValue(gedconstants::GED_PEDI, pedigreLinkageType);
    }
    string childtofamilylink::getChildLinkageStatus() const
    {
        return getChildValue(gedconstants::GED_STAT);
    }
    void childtofamilylink::setChildLinkageStatus(const string &childLinkageStatus)
    {
        setChildValue(gedconstants::GED_STAT, childLinkageStatus);
    }
    const notestructure *childtofamilylink::findNote() const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }

    notestructure *childtofamilylink::getNote(void)
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    bool childtofamilylink::isValid() const
    {
        string ref = getFamilyReference();
        if (ref.empty())
        {
            return false;
        }
        return multinode::isValid() && getTag() == gedconstants::GED_FAMC;
    }
    void childtofamilylink::check(void)
    {
        multinode::check();
        string ref = getFamilyReference();
        if (ref.empty())
        {
            if (getStatus() == status::Normal)
            {
                setStatus(status::IncorrectData);
            }
        }
    }
    nodetype childtofamilylink::getType(void) const
    {
        return nodetype::ChildToFamilyLink;
    }
    ///////////////////////////////////
} // namespace infoged
