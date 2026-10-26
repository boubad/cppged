///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <familyeventdetail.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("familyeventdetail tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    multinode parent(2, gedconstants::GED_ABBR);
    familyeventdetail node(&parent);
    //
    CHECK(node.getHusbAge().empty());
    CHECK(node.getWifeAge().empty());
    //
} // TEST_CASE
TEST_CASE("constructor from string")
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
    familyeventdetail node(dynamic_cast<multinode *>(pTestNode));
    //
    CHECK(node.getHusbAge() == "husb_age");
    CHECK(node.getWifeAge() == "wife_age");
    //
} // TEST_CASE

//////////////////////////////
TEST_SUITE_END();