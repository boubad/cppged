///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <personalnamepieces.h>
#include <notestructure.h>
#include <sourcecitation.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("personalnamepieces tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    multinode parent(2, gedconstants::GED_ABBR);
    personalnamepieces node(&parent);
    CHECK(node.getNamePrefix() == "");
    CHECK(node.getNameGiven() == "");
    CHECK(node.getNameNickname() == "");
    CHECK(node.getNameSurname() == "");
    CHECK(node.getNameSuffix() == "");
    CHECK(node.findNote() == nullptr);
    CHECK(node.findSourceCitation() == nullptr);
    CHECK(node.getNote() != nullptr);
    CHECK(node.getSourceCitation() != nullptr);
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *PERSONALNAMEPIECES_STRING =
        "1 TEST\n"
        "2 NPFX name_prefix\n"
        "2 GIVN name_given\n"
        "2 NICK name_nickname\n"
        "2 SPFX name_surname_prefix\n"
        "2 SURN name_surname\n"
        "2 NSFX name_suffix\n"
        "2 NOTE @notereference@\n"
        "2 SOUR @sourcereference@";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = PERSONALNAMEPIECES_STRING;
    node::nodePtr oNodeTest = fixture.createNode(data);
    node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    multinode *pz = dynamic_cast<multinode *>(pTestNode);
    personalnamepieces node(pz);
    //
    CHECK(node.getNamePrefix() == "name_prefix");
    CHECK(node.getNameGiven() == "name_given");
    CHECK(node.getNameNickname() == "name_nickname");
    CHECK(node.getNameSurname() == "name_surname");
    CHECK(node.getNameSuffix() == "name_suffix");
    CHECK(node.findNote() != nullptr);
    CHECK(node.findSourceCitation() != nullptr);
} // TEST_CASE
TEST_CASE("Mutator")
{
    multinode parent(2, gedconstants::GED_ABBR);
    personalnamepieces node(&parent);
    node.setNamePrefix("name_prefix");
    node.setNameGiven("name_given");
    node.setNameNickname("name_nickname");
    node.setNameSurname("name_surname");
    node.setNameSuffix("name_suffix");
    notestructure *pNote = node.getNote();
    CHECK(pNote != nullptr);
    sourcecitation *pSource = node.getSourceCitation();
    CHECK(pSource != nullptr);
    //
    CHECK(node.getNamePrefix() == "name_prefix");
    CHECK(node.getNameGiven() == "name_given");
    CHECK(node.getNameNickname() == "name_nickname");
    CHECK(node.getNameSurname() == "name_surname");
    CHECK(node.getNameSuffix() == "name_suffix");
    CHECK(node.findNote() != nullptr);
    CHECK(node.findSourceCitation() != nullptr);
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();