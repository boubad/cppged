///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <individualattributestructure.h>
#include <individualeventdetail.h>
#include <indivordinance.h>
#include <multinode.h>
#include <createnode.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("individualattributestructure tests suite");
//////////////////////
class individualattributestructureFixture : public gedconstants
{
public:
    individualattributestructureFixture()
    {
    }
    ~individualattributestructureFixture()
    {
    }
    std::vector<string> getEventTags() const
    {
        return {GED_CAST, GED_DSCR, GED_EDUC,
                GED_IDNO, GED_NATI, GED_NCHI,
                GED_NMR, GED_OCCU, GED_PROP,
                GED_RELI, GED_RESI,
                GED_SSN, GED_TITL, GED_FACT};
    }
    node::nodePtr createNode(int level, const string &ParentTag) const
    {
        static const char *INDIVIDUALEVENTDETAIL_STRING =
            "1 TEST\n"
            "2 AGE indiv_age\n"
            "2 TYPE event_classification\n"
            "2 DATE date\n"
            "2 PLAC placere\n"
            "2 ADDR address\n"
            "2 AGNC agency\n"
            "2 RELI religious_affiliation\n"
            "2 CAUS cause_of_event\n"
            "2 RESN restriction_notice\n"
            "2 NOTE @notereference@\n"
            "2 SOUR @sourcereference@\n"
            "2 OBJE @objectreference@1\n"
            "2 OBJE @objectreference@2";
        const nodefixture &fixture = nodefixture::getInstance();
        string data = INDIVIDUALEVENTDETAIL_STRING;
        node::nodePtr oNodeTest = fixture.createNode(data);
        node *pTestNode = oNodeTest.get();
        CHECK(pTestNode != nullptr);
        multinode *pz = dynamic_cast<multinode *>(pTestNode);
        CHECK(pz != nullptr);
       node::nodePtr oret = createnode::createNode(level, ParentTag, ParentTag + "_value");
        node *pret = oret.get();
        CHECK(pret != nullptr);
        multinode *pmultinode = dynamic_cast<multinode *>(pret);
        CHECK(pmultinode != nullptr);
        pmultinode->setChildren(*pz);
        return oret;
    }
}; // class individualattributestructureFixture
/////////////////////////////
TEST_CASE("Default constructor")
{
    multinode parent(2, "TEST");
    individualattributestructure node(&parent);
    //
    CHECK(node.getCasteName().empty());
    CHECK(node.getPhysicalDescription().empty());
    CHECK(node.getSholasticAchievement().empty());
    CHECK(node.getNationalIdNumber().empty());
    CHECK(node.getNationalOrTribalOrigin().empty());
    CHECK(node.getCountOfChildren().empty());
    CHECK(node.getCountOfMarriages().empty());
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getCasteDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getPhysicalDescriptionDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getSholasticDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getNationalIdDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getNationalOrTribalOriginDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getCountOfChildrenDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getCountOfMarriagesDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getOccupationDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getPossesionsDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getReligiusAffiliationDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getResidenceDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getSocaiSecurityNumberDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getNobilityTypeTitleDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(!node.getAttributeDescriptorDetail(deyail));
    }
} // Default constructor
TEST_CASE_FIXTURE(individualattributestructureFixture, "getDetail")
{
    multinode parent(2, "TEST");
    individualattributestructure node(&parent);
    //
    std::vector<string> eventTags = getEventTags();
    for (const string &tag : eventTags)
    {
        node::nodePtr oNode = createNode(3, tag);
        infoged::node *pNode = oNode.get();
        CHECK(pNode != nullptr);
        parent.getChildren().push_back(oNode);
    } //
    //
    {
        individualeventdetail deyail;
        CHECK(node.getCasteDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getPhysicalDescriptionDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getSholasticDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getNationalIdDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getNationalOrTribalOriginDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getCountOfChildrenDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getCountOfMarriagesDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getOccupationDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getPossesionsDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getReligiusAffiliationDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getResidenceDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getSocaiSecurityNumberDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getNobilityTypeTitleDetail(deyail));
    }
    //
    {
        individualeventdetail deyail;
        CHECK(node.getAttributeDescriptorDetail(deyail));
    }

} // getDetail
///////////////////////
TEST_SUITE_END();