#pragma once
#ifndef INDIVIDUALATTRIBUTESTRUCTURE_H__
#define INDIVIDUALATTRIBUTESTRUCTURE_H__
//
#include "proxynode.h"

//
namespace infoged
{
    class individualeventdetail;
    class indivordinance;
    class individualattributestructure : public proxynode
    {
    public:
        individualattributestructure(multinode *proxy = nullptr);
        individualattributestructure(const individualattributestructure &other);
        individualattributestructure &operator=(const individualattributestructure &other);
        virtual ~individualattributestructure();

    public:
        string getCasteName(void) const;
        void setCasteName(const string &castname);
        bool getCasteDetail(individualeventdetail &detail);
        //
        string getPhysicalDescription(void) const;
        void setPhysicalDescription(const string &physicaldescription);
        bool getPhysicalDescriptionDetail(individualeventdetail &detail);
        //
        string getSholasticAchievement(void) const;
        void setScholastucAchievement(const string &educachievement);
        bool getSholasticDetail(individualeventdetail &detail);
        //
        string getNationalIdNumber(void) const;
        void setNationalIdNumber(const string &nationalidnumber);
        bool getNationalIdDetail(individualeventdetail &detail);
        //
        string getNationalOrTribalOrigin(void) const;
        void setNationalOrTribalOrigin(const string &nationalortribalorigin);
        bool getNationalOrTribalOriginDetail(individualeventdetail &detail);
        //
        string getCountOfChildren(void) const;
        void setCountOfChildren(const string &countofchildren);
        bool getCountOfChildrenDetail(individualeventdetail &detail);
        //
        string getCountOfMarriages(void) const;
        void setCountOfMarriages(const string &countofmarriages);
        bool getCountOfMarriagesDetail(individualeventdetail &detail);
        //
        string getOccupation(void) const;
        void setOccupation(const string &occupation);
        bool getOccupationDetail(individualeventdetail &detail);
        //
        string getPossesions(void) const;
        void setPossesions(const string &possesions);
        bool getPossesionsDetail(individualeventdetail &detail);
        //
        string getReligiusAffiliation(void) const;
        void setReligiusAffiliation(const string &religion);
        bool getReligiusAffiliationDetail(individualeventdetail &detail);
        //
        string getResidence(void) const;
        void setResidence(const string &residence);
        bool getResidenceDetail(individualeventdetail &detail);
        //
        string getSocaiSecurityNumber(void) const;
        void setSocaiSecurityNumber(const string &socaisecurity);
        bool getSocaiSecurityNumberDetail(individualeventdetail &detail);
        //
        string getNobilityTypeTitle(void) const;
        void setNobilityTypeTitle(const string &nobilitytype);
        bool getNobilityTypeTitleDetail(individualeventdetail &detail);
        //
        string getAttributeDescriptor(void) const;
        void setAttributeDescriptor(const string &attributedescriptor);
        bool getAttributeDescriptorDetail(individualeventdetail &detail);
        //
    private:
        bool getDetail(const string &tag, individualeventdetail &detail);
    };
} // namespace infoged
#endif // INDIVIDUALATTRIBUTESTRUCTURE_H__