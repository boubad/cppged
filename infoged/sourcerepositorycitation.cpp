
#include "sourcerepositorycitation.h"
#include "notestructure.h"
#include "gedconstants.h"
#include "stringutils.h"
//////////////////////////
namespace infoged
{
    sourcerepositorycitation::sourcerepositorycitation(int level, const string &xref) : multinode(level, gedconstants::GED_REPO, xref)
    {
    }

    sourcerepositorycitation::sourcerepositorycitation(const sourcerepositorycitation &other) : multinode(other)
    {
    }
    sourcerepositorycitation &sourcerepositorycitation::operator=(const sourcerepositorycitation &other)
    {
        if (this != &other)
        {
            multinode::operator=(other);
        }
        return *this;
    }
    sourcerepositorycitation::~sourcerepositorycitation()
    {
    }
    ///////////////////////////
    string sourcerepositorycitation::getRepositoryRef(void) const
    {
        string s = getValue();
        return stringutils::isPointer(s) ? s : string();
    }
    void sourcerepositorycitation::setRepositoryRef(const string &text)
    {
        string s = stringutils::trim(text);
        if (stringutils::isPointer(s))
        {
            setValue(s);
        }
        else
        {
            setValue(string());
        }
    }
    const notestructure *sourcerepositorycitation::findNote() const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *sourcerepositorycitation::getNote()
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    string sourcerepositorycitation::getSourceCallNumber(void) const
    {
        return getChildValue(gedconstants::GED_CALN);
    }
    void sourcerepositorycitation::setSourceCallNumber(const string &scn)
    {
        setChildValue(gedconstants::GED_CALN, scn);
    }
    string sourcerepositorycitation::getSourceMediaType(void) const
    {
        return getChildValue(gedconstants::GED_CALN, gedconstants::GED_MEDI);
    }

    void sourcerepositorycitation::setSourceMediaType(const string &media)
    {
        setChildValue(gedconstants::GED_CALN, gedconstants::GED_MEDI, media);
    }
    ////////////////////////////
    bool sourcerepositorycitation::isValid(void) const
    {
        string ref = getRepositoryRef();
        if (ref.empty())
        {
            return false;
        }
        return multinode::isValid() && getTag() == gedconstants::GED_REPO;
    }
    void sourcerepositorycitation::check(void)
    {
        multinode::check();
        string ref = getRepositoryRef();
        if (ref.empty())
        {
            if (getStatus() == status::Normal)
            {
                setStatus(status::IncorrectData);
            }
        }
    }
    nodetype sourcerepositorycitation::getType(void) const
    {
        return nodetype::SourceRepositoryCitation;
    }
    //////////////////////////////
} // namespace infoged
