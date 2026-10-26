///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <multinode.h>
////////////////////////
#include "nodefixture.h"
#include <gedconstants.h>
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("misc tests suite");
///////////////////////
TEST_CASE("Marnm tag")
{
    static const char *INDIVIDUAL_STRING =
        "0 @I1@ INDI\n"
        "1 RESN privacy\n"
        "1 NAME john /Smith/\n"
        "2 GIVN John\n"
        "2 SURN Smith\n"
        "2 _MARNM MereHawa /Touré/\n"
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
    const multinode *pz = dynamic_cast<const multinode *>(pTestNode);
    CHECK(pz != nullptr);
    const node *p1 = pz->findChild(gedconstants::GED_NAME);
    CHECK(p1 != nullptr);
    const multinode *pz1 = dynamic_cast<const multinode *>(p1);
    CHECK(pz1 != nullptr);
    const node *p2 = pz1->findChild(gedconstants::GED_WTMARNM);
    CHECK(p2 != nullptr);
    //
    multinode *pn = const_cast<multinode *>(pz);
    CHECK(pn != nullptr);
    auto filterfunc = [](const node *p) -> bool
    {
        return p->getTag() == gedconstants::GED_WTMARNM;
    };
    pn->remove(filterfunc);
    //
    const node *p2x = pz1->findChild(gedconstants::GED_WTMARNM);
    CHECK(p2x == nullptr);
} // TEST_CASE Constructor

//////////////////////////////
TEST_SUITE_END();
