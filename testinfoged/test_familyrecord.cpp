///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <familyrecord.h>
#include <familyeventstructure.h>
#include <ldsspousesealing.h>
#include <changedate.h>
#include <sourcecitation.h>
#include <multimedialink.h>
#include <familyeventdetail.h>
////////////////////////
#include "nodefixture.h"
#include "createnode.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("familyrecord tests suite");
////////////////////////
class familyrecordFixture : public gedconstants
{
public:
    familyrecordFixture()
    {
    }
    ~familyrecordFixture()
    {
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
        node::nodePtr oNodeTest = fixture.createNode(data);
        node *pTestNode = oNodeTest.get();
        CHECK(pTestNode != nullptr);
        multinode *pz = dynamic_cast<multinode *>(pTestNode);
        CHECK(pz != nullptr);
        node::nodePtr oret = createnode::createNode(level, ParentTag, value);
        node *pret = oret.get();
        CHECK(pret != nullptr);
        multinode *pmultinode = dynamic_cast<multinode *>(pret);
        CHECK(pmultinode != nullptr);
        pmultinode->setChildren(*pz);
        return oret;
    } // createNode
    void updatefamilyrecord(familyrecord &parent) const
    {
        stringvector tags{GED_ANUL, GED_CENS, GED_DIV,
                          GED_DIVF, GED_ENGA, GED_MARB, GED_MARC,
                          GED_MARR, GED_MARL, GED_MARS, GED_RESI};
        for (const auto &tag : tags)
        {
            const int addLevel = parent.getLevel() + 1;
            string eventdescriptor = (tag == GED_MARR) ? "Y" : "";
            node *pCurrent = parent.getChild(tag,eventdescriptor);
            CHECK(pCurrent != nullptr);
            pCurrent->setLevel(addLevel);
        } // tag
    } // updatefamilyrecord
}; // class familyrecordFixture
///////////////////////
TEST_CASE("Default constructor")
{
    familyrecord node;
    node.check();
    CHECK(node.getType() == nodetype::Family);
    CHECK(node.isValid() == false);
    CHECK(node.getResctrictionNotice() == "");
    CHECK(node.getHusbandId() == "");
    CHECK(node.getWifeId() == "");
    CHECK(node.getCountOfChildren() == "");
    CHECK(node.getSubmitterId() == "");
    CHECK(node.getUserReferenceNumber() == "");
    CHECK(node.getUserReferenceType() == "");
    CHECK(node.getAutomatedRecordId() == "");
    //
    const familyrecord *pConst = &node;
    CHECK(pConst->findLdsSpouseSealing() == nullptr);
    CHECK(pConst->findChangeDate() == nullptr);
    CHECK(pConst->findSourceCitation() == nullptr);
    stringset multimedialinks;
    CHECK(pConst->getMultimediaLinks(multimedialinks) == false);

} // TEST_CASE
TEST_CASE_FIXTURE(familyrecordFixture, "Constructor from string")
{
    static const char *FAMILY_STRING =
        "0 @F1@ FAM\n"
        "1 HUSB @I1@\n"
        "1 WIFE @I2@\n"
        "1 CHIL @I3@\n"
        "1 CHIL @I4@\n"
        "1 CHIL @I5@\n"
        "1 NCHI 3\n"
        "1 MARR\n"
        "2 DATE 01 JAN 2000\n"
        "2 PLAC New York, USA\n"
        "1 RESN privacy\n"
        "1 REFN 12345\n"
        "2 TYPE userref\n"
        "1 RIN 67890\n"
        "1 SLGC\n"
        "2 DATE 1 JAN 2000\n"
        "2 TEMP temple_code\n"
        "2 PLAC place_living_ordinance\n"
        "2 STAT les_spouse_sealing_date_status\n"
        "3 DATE 2 FEB 2000\n"
        "2 NOTE @note_reference@\n"
        "2 SOUR @source_reference@"
        "1 SUBM @\n"
        "1 CHAN\n"
        "2 DATE 02 FEB 2020\n"
        "2 TIME 12:34:56";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = FAMILY_STRING;
    node::nodePtr oNodeTest = fixture.createNode(data);
    const node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    const familyrecord *pCur = dynamic_cast<const familyrecord *>(pTestNode);
    CHECK(pCur != nullptr);
    familyrecord *p = const_cast<familyrecord *>(pCur);
    CHECK(p != nullptr);
    updatefamilyrecord(*p);
    p->check();
    CHECK(p->getResctrictionNotice() == "privacy");
    CHECK(p->getHusbandId() == "@I1@");
    CHECK(p->getWifeId() == "@I2@");
    CHECK(p->getCountOfChildren() == "3");
    CHECK(p->getSubmitterId() == "");
    CHECK(p->getUserReferenceNumber() == "12345");
    CHECK(p->getUserReferenceType() == "userref");
    CHECK(p->getAutomatedRecordId() == "67890");
    //
    familyeventstructure familyEventStructure(p);
    familyeventdetail detail(p);
    CHECK(familyEventStructure.getAnul(detail));
    CHECK(familyEventStructure.getCens(detail));
    CHECK(familyEventStructure.getDiv(detail));
    CHECK(familyEventStructure.getDivf(detail));
    CHECK(familyEventStructure.getEnga(detail));
    CHECK(familyEventStructure.getMarb(detail));
    CHECK(familyEventStructure.getMarc(detail));
    CHECK(familyEventStructure.getMarr(detail));
    CHECK(familyEventStructure.getMarl(detail));
    CHECK(familyEventStructure.getMars(detail));
    CHECK(familyEventStructure.getResi(detail));
} // TEST_CASE
TEST_CASE("Mutator")
{
    familyrecord node("@F1@");
    node.setHusbandId("@I1@");
    node.setWifeId("@I2@");
    node.setCountOfChildren("3");
    node.setSubmitterId("@I3@");
    node.setUserReferenceNumber("12345");
    node.setUserReferenceType("userref");
    node.setAutomatedRecordId("67890");
    //
    const familyrecord *pConst = &node;
    CHECK(pConst->getHusbandId() == "@I1@");
    CHECK(pConst->getWifeId() == "@I2@");
    CHECK(pConst->getCountOfChildren() == "3");
    CHECK(pConst->getSubmitterId() == "@I3@");
    CHECK(pConst->getUserReferenceNumber() == "12345");
    CHECK(pConst->getUserReferenceType() == "userref");
    CHECK(pConst->getAutomatedRecordId() == "67890");
}// TEST_CASE
//////////////////////////////
TEST_SUITE_END();