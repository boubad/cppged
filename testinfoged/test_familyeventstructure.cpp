///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <familyeventstructure.h>
#include <familyeventdetail.h>
#include <createnode.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("familyeventstructure");
//////////////////////
class familyeventstructureFixture : public gedconstants
{
public:
    familyeventstructureFixture()
    {
    }
    ~familyeventstructureFixture()
    {
    }
    std::vector<string> getEventTags() const
    {
        return {GED_ANUL, GED_CENS, GED_DIV, GED_DIVF, GED_ENGA, GED_MARB, GED_MARC, GED_MARR, GED_MARL, GED_MARS, GED_RESI};
    }
    node::nodePtr createNode(int level, const string &ParentTag, const string &value = string()) const
    {
        static const char *FAMILYEVENTDETAIL_STRING =
            "1 TEST\n"
            "2 HUSB\n"
            "3 AGE husb_age\n"
            "2 WIFE\n"
            "3 AGE wife_age\n"
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
        string data = FAMILYEVENTDETAIL_STRING;
        std::shared_ptr<node> oNodeTest = fixture.createNode(data);
        node *pTestNode = oNodeTest.get();
        CHECK(pTestNode != nullptr);
        multinode *pz = dynamic_cast<multinode *>(pTestNode);
        CHECK(pz != nullptr);
        // Node::Ptr oret = gedcomenv::create(level, ParentTag, value);
        node::nodePtr oret = createnode::createNode(level, ParentTag, value);
        node *pret = oret.get();
        CHECK(pret != nullptr);
        multinode *pmultinode = dynamic_cast<multinode *>(pret);
        CHECK(pmultinode != nullptr);
        pmultinode->setChildren(*pz);
        return oret;
    }
}; // class familyeventstructureFixture
//////////////////////////
TEST_CASE("default constructor")
{
    multinode parent(2, "TEST");
    familyeventstructure familyEventStructure(&parent);
    //
    string value = familyEventStructure.getMarrValue();
    CHECK(value.empty());
    //
    {
        familyeventdetail detail;
        CHECK(!familyEventStructure.getAnul(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(!familyEventStructure.getCens(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(!familyEventStructure.getDiv(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(!familyEventStructure.getDivf(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(!familyEventStructure.getEnga(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(!familyEventStructure.getMarb(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(!familyEventStructure.getMarc(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(!familyEventStructure.getMarr(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(!familyEventStructure.getMarl(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(!familyEventStructure.getMars(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(!familyEventStructure.getResi(detail));
    }
} //
/////////////////////////
TEST_CASE_FIXTURE(familyeventstructureFixture, "familyeventstructure")
{
    multinode parent(2, "TEST");
    for (const string &tag : getEventTags())
    {
        string value = (tag == GED_MARR) ? "Y" : "";
        node::nodePtr oNode = createNode(3, tag, value);
        node *pNode = oNode.get();
        CHECK(pNode != nullptr);
        parent.getChildren().push_back(oNode);
    }
    //
    familyeventstructure familyEventStructure(&parent);
    //
    string value = familyEventStructure.getMarrValue();
    CHECK(value == "Y");
    //
    {
        familyeventdetail detail;
        CHECK(familyEventStructure.getAnul(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(familyEventStructure.getCens(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(familyEventStructure.getDiv(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(familyEventStructure.getDivf(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(familyEventStructure.getEnga(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(familyEventStructure.getMarb(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(familyEventStructure.getMarc(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(familyEventStructure.getMarr(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(familyEventStructure.getMarl(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(familyEventStructure.getMars(detail));
    } //
    {
        familyeventdetail detail;
        CHECK(familyEventStructure.getResi(detail));
    }
}
///////////////////////
TEST_SUITE_END();