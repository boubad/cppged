///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <trailer.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("trailer tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    trailer node;
    node.check();
    CHECK(node.getType() == nodetype::Trailer);
    CHECK(node.isValid() == true);
    CHECK(node.getId().empty());
    CHECK(node.getTag() == "TRLR");
    CHECK(node.getValue().empty());
    CHECK(node.getLevel() == 0);
    //
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *TRAILER_STRING = "0 TRLR";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = TRAILER_STRING;
    node::nodePtr oNodeTest = fixture.createNode(data);
    const node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    const trailer *pCur = dynamic_cast<const trailer *>(pTestNode);
    CHECK(pCur != nullptr);
    trailer *p = const_cast<trailer *>(pCur);
    p->check();
    trailer &node = *p;
    //
    CHECK(node.getType() == nodetype::Trailer);
    CHECK(node.isValid() == true);
    CHECK(node.getId().empty());
    CHECK(node.getTag() == "TRLR");
    CHECK(node.getValue().empty());
    CHECK(node.getLevel() == 0);
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();