///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <individualrecord.h>
#include <individualeventstructure.h>
#include <individualattributestructure.h>
#include <personalnamestructure.h>
#include <ldsindividualordinance.h>
#include <childtofamilylink.h>
#include <spousetofamily.h>
#include <associationstructure.h>
#include <notestructure.h>
#include <changedate.h>
#include <sourcecitation.h>
#include <multimedialink.h>
#include <individualeventstructure.h>
////////////////////////
#include "nodefixture.h"
#include <createnode.h>
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("individualrecord tests suite");
/////////////////////////
class individualrecordFixture : public gedconstants
{
public:
    individualrecordFixture()
    {
    }
    ~individualrecordFixture()
    {
    }
    node::nodePtr createIndividualEventDetailNode(int level, const string &ParentTag, const string &value = string()) const
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
            "2 OBJE @objectreference@2\n"
            "2 FAMC @familyreference@\n"
            "3 ADOP adopted_by_which_parent\n";

        const nodefixture &fixture = nodefixture::getInstance();
        string data = INDIVIDUALEVENTDETAIL_STRING;
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
        pmultinode->setParent(pz);
        return oret;
    } // createIndividualEventDEtailNode
    void updateIndividualAttributelNode(multinode &parent) const
    {
        stringvector tags{GED_BIRT, GED_CHR, GED_DEAT, GED_BURI, GED_CREM, GED_ADOP,
                          GED_BAPM, GED_BARM, GED_BASM, GED_BLES,
                          GED_CHRA, GED_CONF, GED_FCOM, GED_ORDN,
                          GED_NATU, GED_EMIG, GED_IMMI,
                          GED_CENS, GED_PROB, GED_WILL,
                          GED_GRAD, GED_RETI, GED_EVEN};

        for (const auto &tag : tags)
        {
            const int addLevel = parent.getLevel() + 1;
            string eventdescriptor;
            if (tag == GED_BIRT || tag == GED_CHR || tag == GED_DEAT)
            {
                eventdescriptor = "Y";
            }
            node *pCurrent = parent.getChild(tag, eventdescriptor);
            CHECK(pCurrent != nullptr);
            pCurrent->setLevel(addLevel);
        } // tag
    } // createIndividualAttributelNode
}; // class individualrecordFixture
///////////////////////
TEST_CASE("Default constructor")
{
    individualrecord node;
    node.check();
    CHECK(node.getType() == nodetype::Individual);
    CHECK(node.isValid() == true);
    CHECK(node.getId() == "");
    CHECK(node.getRestrictionNotice() == "");
    CHECK(node.getSex() == "");
    CHECK(node.getPermanentRecordFileNumber() == "");
    CHECK(node.getAncestralFileNumber() == "");
    CHECK(node.getUserReferenceNumber() == "");
    CHECK(node.getUserReferenceType() == "");
    CHECK(node.getAutomatedRecordId() == "");
    //
    const individualrecord *p = &node;
    CHECK(p->findPersonalName() == nullptr);
    CHECK(p->findChildToFamilyLink() == nullptr);
} // TEST_CASE
TEST_CASE_FIXTURE(individualrecordFixture, "Constructore from string")
{
    static const char *INDIVIDUAL_STRING =
        "0 @I1@ INDI\n"
        "1 RESN privacy\n"
        "1 NAME\n"
        "2 GIVN John\n"
        "2 SURN Smith\n"
        "1 SEX M\n"
        "1 BIRT\n"
        "2 DATE 01 JAN 2000\n"
        "2 PLAC New York, USA\n"
        "1 FAMC @F1@\n"
        "1 FAMS @F2@\n"
        "1 SUBM @submitter_reference@\n"
        "1 ASSO @association_reference@\n"
        "2 RELA relation_descriptor\n"
        "1 ALIA @alias_reference@\n"
        "1 ANCI @ancestry_reference@\n"
        "1 DESI @descendant_reference@\n"
        "1 RFN permanent_record_file_number\n5\n"
        "1 AFN ancestral_file_number\n5\n"
        "1 REFN 12345\n"
        "2 TYPE userref\n"
        "1 RIN 67890\n"
        "1 CHAN\n"
        "2 DATE 02 FEB 2020\n"
        "2 TIME 12:34:56";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = INDIVIDUAL_STRING;
    node::nodePtr oNodeTest = fixture.createNode(data);
    const node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    const individualrecord *pCur = dynamic_cast<const individualrecord *>(pTestNode);
    //
    individualrecord *pMut = const_cast<individualrecord *>(pCur);
    CHECK(pMut != nullptr);
    updateIndividualAttributelNode(*pMut);
    //
    CHECK(pCur != nullptr);
    //
    CHECK(pCur->getId() == "@I1@");
    CHECK(pCur->getRestrictionNotice() == "privacy");
    CHECK(pCur->getSex() == "M");
    CHECK(pCur->getPermanentRecordFileNumber() == "permanent_record_file_number");
    CHECK(pCur->getAncestralFileNumber() == "ancestral_file_number");
    CHECK(pCur->getUserReferenceNumber() == "12345");
    CHECK(pCur->getUserReferenceType() == "userref");
    CHECK(pCur->getAutomatedRecordId() == "67890");
    //
    const individualrecord *p = pCur;
    CHECK(p->findPersonalName() != nullptr);
    CHECK(p->findChildToFamilyLink() != nullptr);
    //
    individualeventstructure pevents(pMut);
    bool b = pMut->getIndividualEvents(pevents);
    CHECK(b == true);
    individualattributestructure attributel(pMut);
    b = pMut->getIndividualAttributes(attributel);
    CHECK(b == true);
    ldsindividualordinance ordinance(pMut);
    b = pMut->getIndividualOrdinances(ordinance);
    CHECK(b == true);
    //
    individualrecord node(*pCur);
    CHECK(node.getType() == nodetype::Individual);
    CHECK(node.getId() == "@I1@");
    CHECK(node.getRestrictionNotice() == "privacy");
    CHECK(node.getSex() == "M");
    CHECK(node.getPermanentRecordFileNumber() == "permanent_record_file_number");
    CHECK(node.getAncestralFileNumber() == "ancestral_file_number");
    CHECK(node.getUserReferenceNumber() == "12345");
    CHECK(node.getUserReferenceType() == "userref");
    CHECK(node.getAutomatedRecordId() == "67890");
} // TEST_CASE
TEST_CASE("Mutator")
{
    individualrecord node("@I1@");
    //
    personalnamestructure *pName = node.getPersonalName();
    CHECK(pName != nullptr);
    pName->setName("John /Doe/");
    pName->setNameType("Birth Name");
    pName->setNamePhoneticVariation("John /Doe/");
    pName->setPhoneticType("Phonetic");
    pName->setRomanizedVariation("John /Doe/");
    pName->setRomanizedType("Romanized");
    //
    node.setRestrictionNotice("privacy");
    //
    node.setSex("M");
    node.setPermanentRecordFileNumber("permanent_record_file_number");
    node.setAncestralFileNumber("ancestral_file_number");
    node.setUserReferenceNumber("12345");
    node.setUserReferenceType("userref");
    node.setAutomatedRecordId("67890");
    CHECK(node.getSex() == "M");
    CHECK(node.getPermanentRecordFileNumber() == "permanent_record_file_number");
    CHECK(node.getAncestralFileNumber() == "ancestral_file_number");
    CHECK(node.getUserReferenceNumber() == "12345");
    CHECK(node.getUserReferenceType() == "userref");
    CHECK(node.getAutomatedRecordId() == "67890");
    //
    CHECK(node.isValid() == true);
    //
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();