
#include "individualattributestructure.h"
///////////////////////////////
#include "individualeventdetail.h"
#include "multinode.h"
#include "gedconstants.h"
///////////////////
namespace infoged
{
    individualattributestructure::individualattributestructure(multinode *proxy) : proxynode(proxy)
    {
    }
    individualattributestructure::individualattributestructure(const individualattributestructure &other) : proxynode(other)
    {
    }
    individualattributestructure &individualattributestructure::operator=(const individualattributestructure &other)
    {
        if (this != &other)
        {
            proxynode::operator=(other);
        }
        return *this;
    }
    individualattributestructure::~individualattributestructure()
    {
    }
    /////////////////////////////////////////
    bool individualattributestructure::getDetail(const string &tag, individualeventdetail &detail)
    {
        const node *node = getProxy()->findChild(tag);
        if (node != nullptr)
        {
            const multinode *px = dynamic_cast<const multinode *>(node);
            if (px != nullptr)
            {
                multinode *pCurrent = const_cast<multinode *>(px);
                detail = individualeventdetail(pCurrent);
                return true;
            }
        }
        return false;
    }
    ////////////////////////////////////////
    string individualattributestructure::getCasteName(void) const
    {
        return getChildValue(gedconstants::GED_CAST);
    }
    void individualattributestructure::setCasteName(const string &castname)
    {
        setChildValue(gedconstants::GED_CAST, castname);
    }
    bool individualattributestructure::getCasteDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_CAST, detail);
    }
    //
    string individualattributestructure::getPhysicalDescription(void) const
    {
        return getChildValue(gedconstants::GED_DSCR);
    }
    void individualattributestructure::setPhysicalDescription(const string &physicaldescription)
    {
        setChildValue(gedconstants::GED_DSCR, physicaldescription, nullptr);
    }
    bool individualattributestructure::getPhysicalDescriptionDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_DSCR, detail);
    }
    //
    string individualattributestructure::getSholasticAchievement(void) const
    {
        return getChildValue(gedconstants::GED_EDUC);
    }
    void individualattributestructure::setScholastucAchievement(const string &educachievement)
    {
        setChildValue(gedconstants::GED_EDUC, educachievement);
    }
    bool individualattributestructure::getSholasticDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_EDUC, detail);
    }
    //
    string individualattributestructure::getNationalIdNumber(void) const
    {
        return getChildValue(gedconstants::GED_IDNO);
    }
    void individualattributestructure::setNationalIdNumber(const string &nationalidnumber)
    {
        setChildValue(gedconstants::GED_IDNO, nationalidnumber);
    }
    bool individualattributestructure::getNationalIdDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_IDNO, detail);
    }
    //
    string individualattributestructure::getNationalOrTribalOrigin(void) const
    {
        return getChildValue(gedconstants::GED_NATI);
    }
    void individualattributestructure::setNationalOrTribalOrigin(const string &nationalortribalorigin)
    {
        setChildValue(gedconstants::GED_NATI, nationalortribalorigin);
    }
    bool individualattributestructure::getNationalOrTribalOriginDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_NATI, detail);
    }
    //
    string individualattributestructure::getCountOfChildren(void) const
    {
        return getChildValue(gedconstants::GED_NCHI);
    }
    void individualattributestructure::setCountOfChildren(const string &countofchildren)
    {
        setChildValue(gedconstants::GED_NCHI, countofchildren);
    }
    bool individualattributestructure::getCountOfChildrenDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_NCHI, detail);
    }
    //
    string individualattributestructure::getCountOfMarriages(void) const
    {
        return getChildValue(gedconstants::GED_NMR);
    }
    void individualattributestructure::setCountOfMarriages(const string &countofmarriages)
    {
        setChildValue(gedconstants::GED_NMR, countofmarriages);
    }
    bool individualattributestructure::getCountOfMarriagesDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_NMR, detail);
    }
    string individualattributestructure::getOccupation(void) const
    {
        return getChildValue(gedconstants::GED_OCCU);
    }
    void individualattributestructure::setOccupation(const string &occupation)
    {
        setChildValue(gedconstants::GED_OCCU, occupation);
    }
    bool individualattributestructure::getOccupationDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_OCCU, detail);
    }
    //
    string individualattributestructure::getPossesions(void) const
    {
        return getChildValue(gedconstants::GED_PROP);
    }
    void individualattributestructure::setPossesions(const string &possesions)
    {
        setChildValue(gedconstants::GED_PROP, possesions);
    }
    bool individualattributestructure::getPossesionsDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_PROP, detail);
    }
    //
    string individualattributestructure::getReligiusAffiliation(void) const
    {
        return getChildValue(gedconstants::GED_RELI);
    }
    void individualattributestructure::setReligiusAffiliation(const string &religiusaffiliation)
    {
        setChildValue(gedconstants::GED_RELI, religiusaffiliation);
    }
    bool individualattributestructure::getReligiusAffiliationDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_RELI, detail);
    }
    //
    string individualattributestructure::getResidence(void) const
    {
        return getChildValue(gedconstants::GED_RESI);
    }
    void individualattributestructure::setResidence(const string &residence)
    {
        setChildValue(gedconstants::GED_RESI, residence);
    }
    bool individualattributestructure::getResidenceDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_RESI, detail);
    }
    //
    string individualattributestructure::getSocaiSecurityNumber(void) const
    {
        return getChildValue(gedconstants::GED_SSN);
    }
    void individualattributestructure::setSocaiSecurityNumber(const string &socaisecuritynumber)
    {
        setChildValue(gedconstants::GED_SSN, socaisecuritynumber);
    }
    bool individualattributestructure::getSocaiSecurityNumberDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_SSN, detail);
    }
    //
    string individualattributestructure::getNobilityTypeTitle(void) const
    {
        return getChildValue(gedconstants::GED_TITL);
    }
    void individualattributestructure::setNobilityTypeTitle(const string &nobilitytypetitle)
    {
        setChildValue(gedconstants::GED_TITL, nobilitytypetitle);
    }
    bool individualattributestructure::getNobilityTypeTitleDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_TITL, detail);
    }
    //
    string individualattributestructure::getAttributeDescriptor(void) const
    {
        return getChildValue(gedconstants::GED_FACT);
    }
    void individualattributestructure::setAttributeDescriptor(const string &attributedescriptor)
    {
        setChildValue(gedconstants::GED_FACT, attributedescriptor);
    }
    bool individualattributestructure::getAttributeDescriptorDetail(individualeventdetail &detail)
    {
        return getDetail(gedconstants::GED_FACT, detail);
    }

    //////////////////////////////////////
} // namespace