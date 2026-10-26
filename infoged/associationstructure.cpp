
/////////////////////////
#include "associationstructure.h"
/////////////////////////
#include "sourcecitation.h"
#include "notestructure.h"
#include "gedconstants.h"
#include "stringutils.h"
///////////////////////////
namespace infoged
{
    associationstructure::associationstructure(int level, const string &xref) : multinode(level, gedconstants::GED_ASSO, xref)
    {
    }
    associationstructure::associationstructure(const associationstructure &other) : multinode(other)
    {
    }
    associationstructure &associationstructure::operator=(const associationstructure &other)
    {
        if (this != &other)
        {
            multinode::operator=(other);
        }
        return *this;
    }
    associationstructure::~associationstructure()
    {
    }
    string associationstructure::getIndivReference(void) const
    {
        string s = getValue();
        return stringutils::isPointer(s) ? s : string();
    }
    void associationstructure::setIndivReference(const string &indivReference)
    {
        string s = stringutils::trim(indivReference);
        if (stringutils::isPointer(s))
        {
            setValue(s);
        }
        else
        {
            setValue(string());
        }
    }

    string associationstructure::getRelationDescriptor(void) const
    {
        return getChildValue(gedconstants::GED_RELA);
    }
    void associationstructure::setRelationDescriptor(const string &relationDescriptor)
    {
        setChildValue(gedconstants::GED_RELA, relationDescriptor);
    }
    const sourcecitation *associationstructure::findSourceCitation() const
    {
        return findChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    sourcecitation *associationstructure::getSourceCitation(void)
    {
        return getChildNodeByTag<sourcecitation>(gedconstants::GED_SOUR);
    }
    const notestructure *associationstructure::findNote() const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *associationstructure::getNote(void)
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    bool associationstructure::isValid() const
    {
        string ref = getIndivReference();
        string relation = getRelationDescriptor();
        if (ref.empty() || relation.empty())
        {
            return false;
        }
        return multinode::isValid() && getTag() == gedconstants::GED_ASSO;
    }
    void associationstructure::check(void)
    {
        multinode::check();
        string ref = getIndivReference();
        string relation = getRelationDescriptor();
        if (ref.empty() || relation.empty())
        {
            if (getStatus() == status::Normal)
            {
                setStatus(status::MissingData);
            }
        }
    }
    nodetype associationstructure::getType(void) const
    {
        return nodetype::Association;
    }
} // namespace infoged
