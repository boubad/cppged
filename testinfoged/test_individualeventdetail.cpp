///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <individualeventdetail.h>
#include <multinode.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("individualeventdetail tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
     multinode parent(2, "TEST");
    individualeventdetail node(&parent);
    //
    CHECK(node.getAgeAtEvent().empty());
    //
} // TEST_CASE
TEST_CASE("constructor from string")
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
    individualeventdetail node(dynamic_cast<multinode *>(pTestNode));
    //
    CHECK(node.getAgeAtEvent() == "indiv_age");
    //
} // TEST_CASE

//////////////////////////////
TEST_SUITE_END();