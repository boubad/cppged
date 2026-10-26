
#include "spousetofamily.h"
////////////////////////////
#include "notestructure.h"
#include "gedconstants.h"
#include "stringutils.h"
/////////////////////////////
namespace infoged
{
    spousetofamilylink::spousetofamilylink(int level, const string &xref) :
     multinode(level,gedconstants::GED_FAMS, xref)
    {
    }
    spousetofamilylink::spousetofamilylink(const spousetofamilylink &rec) : multinode(rec)
    {
    }
    spousetofamilylink &spousetofamilylink::operator=(const spousetofamilylink &other)
    {
        if (this != &other)
        {
            multinode::operator=(other);
        }
        return *this;
    }
    spousetofamilylink::~spousetofamilylink()
    {
    }
    string spousetofamilylink::getFamilyRef(void) const
    {
        string s = getValue();
        return stringutils::isPointer(s) ? s : string();
    }
    void spousetofamilylink::setFamilyRef(const string &familyref)
    {
        string s = stringutils::trim(familyref);
        if (stringutils::isPointer(s))
        {
            setValue(s);
        }
        else
        {
            setValue(string());
        }
    }
    const notestructure *spousetofamilylink::findNote(void) const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *spousetofamilylink::getNote()
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    bool spousetofamilylink::isValid() const
    {
        string ref = getValue();
        if (ref.empty())
        {
            return false;
        }
        return multinode::isValid() && getTag() == gedconstants::GED_FAMS;
    }
    void spousetofamilylink::check(void)
    {
        multinode::check();
        string ref = getValue();
        if (ref.empty())
        {
            if (getStatus() == status::Normal)
            {
                setStatus(status::IncorrectData);
            }
        }
    }
    nodetype spousetofamilylink::getType(void) const
    {
        return nodetype::SpouseToFamilyLink;
    }
} // namespace    infoged