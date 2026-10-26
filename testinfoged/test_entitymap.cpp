///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <entitymap.h>
#include <individualrecord.h>
////////////////////////
#include "nodefixture.h"
#include <createnode.h>
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
using testrecordclass = individualrecord;
///////////////////////
TEST_SUITE_BEGIN("entitymap tests suite");
/////////////////////////
static const char *INDIVIDUAL1_STRING =
    "0 @I1@ INDI\n"
    "1 RESN privacy\n"
    "1 NAME\n"
    "2 GIVN John\n"
    "2 SURN Smith\n"
    "1 SEX M\n"
    "1 BIRT\n"
    "2 DATE 01 JAN 2000\n"
    "2 PLAC New York, USA\n"
    "1 FAMC @F11@\n"
    "1 FAMS @F21\n"
    "1 SUBM @submitter_reference1@\n"
    "1 ASSO @association_reference1@\n"
    "2 RELA relation_descriptor\n"
    "1 ALIA @alias_reference@\n"
    "1 ANCI @ancestry_reference1@\n"
    "1 DESI @descendant_reference1@\n"
    "1 RFN permanent_record_file_number\n5\n"
    "1 AFN ancestral_file_number\n5\n"
    "1 REFN 12345\n"
    "2 TYPE userref\n"
    "1 RIN 67890\n"
    "1 CHAN\n"
    "2 DATE 02 FEB 2020\n"
    "2 TIME 12:34:56";
static const char *INDIVIDUAL2_STRING =
    "0 @I2@ INDI\n"
    "1 RESN privacy2\n"
    "1 NAME\n"
    "2 GIVN John2\n"
    "2 SURN Smith2\n"
    "1 SEX F\n"
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
static const char *INDIVIDUAL3_STRING =
    "0 @I3@ INDI\n"
    "1 RESN privacy3\n"
    "1 NAME\n"
    "2 GIVN John3\n"
    "2 SURN Smith3\n"
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
class EntityMapFixture
{
public:
    EntityMapFixture() {}
    ~EntityMapFixture() {}
    node::nodePtr createIndiv(const string &data) const
    {
        const nodefixture &fixture = nodefixture::getInstance();
        node::nodePtr oNodeTest = fixture.createNode(data);
        const node *pTestNode = oNodeTest.get();
        CHECK(pTestNode != nullptr);
        return oNodeTest;
    } // createIndiv
    void addIndivs(entitymap<testrecordclass> &em, const char *pdatastring) const
    {
        string data = pdatastring;
        node::nodePtr oIndiv = createIndiv(pdatastring);
        const node *pIndiv = oIndiv.get();
        CHECK(pIndiv != nullptr);
        const individualrecord *pIndivRec = dynamic_cast<const individualrecord *>(pIndiv);
        CHECK(pIndivRec != nullptr);
        em.add(*pIndivRec);
    }
    void initializeMap(entitymap<testrecordclass> &em) const
    {
        addIndivs(em, INDIVIDUAL1_STRING);
        addIndivs(em, INDIVIDUAL2_STRING);
        addIndivs(em, INDIVIDUAL3_STRING);
    }
}; // EntityMapFixture
////////////////////////////
TEST_CASE("Default constructor")
{
    entitymap<testrecordclass> em;
    CHECK(em.size() == 0);
    //
    entitymap<testrecordclass> em2(em);
    CHECK(em2.size() == 0);
    //
    entitymap<testrecordclass> em3 = em2;
    CHECK(em3.size() == 0);
} // TEST_CASE
TEST_CASE_FIXTURE(EntityMapFixture, "entitymap")
{
    entitymap<testrecordclass> em;
    initializeMap(em);
    //
    CHECK(em.size() == 3);
    //
    string id("@I1@");
    const testrecordclass *pRec = em.find(id);
    CHECK(pRec != nullptr);
    CHECK(pRec->getId() == id);
    id = "@I2@";
    pRec = em.find(id);
    CHECK(pRec != nullptr);
    CHECK(pRec->getId() == id);
    id = "@I3@";
    pRec = em.find(id);
    CHECK(pRec != nullptr);
    CHECK(pRec->getId() == id);
    CHECK(em.find("notfound") == nullptr);
    //
    CHECK(em.update(*pRec));
    //
    stringset keyysset;
    em.keys(keyysset);
    CHECK(keyysset.size() == 3);
    CHECK(keyysset.find("@I1@") != keyysset.end());
    CHECK(keyysset.find("@I2@") != keyysset.end());
    CHECK(keyysset.find("@I3@") != keyysset.end());
    //
    CHECK(em.size() == 3);
    CHECK(em.remove("@I1@"));
    CHECK(em.size() == 2);
    CHECK(em.remove("@I2@"));
    CHECK(em.size() == 1);
    CHECK(em.remove("@I3@"));
    CHECK(em.size() == 0);
} // TEST_CASE
TEST_CASE_FIXTURE(EntityMapFixture, "entitymap iterator")
{
    entitymap<testrecordclass> em;
    initializeMap(em);
    CHECK(em.size() == 3);
    //
    stringset keys;
    auto visitor = [&keys](const node *pNode)
    {
        string id = pNode->getId();
        if (!id.empty())
        {
            keys.insert(id);
        }
    };
    em.visit(visitor);
    CHECK(keys.size() == 3);
    //
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();