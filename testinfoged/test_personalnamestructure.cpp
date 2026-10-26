///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <multinode.h>
#include <personalnamestructure.h>
#include <personalnamepieces.h>
#include <createnode.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("personalnamestructure tests suite");
///////////////////////
TEST_CASE("default constructor")
{
    personalnamestructure node;
    node.check();
    //
    CHECK(node.getType() == nodetype::PersonalName);
    CHECK(node.getName() == "");
    CHECK(node.getNameType() == "");
    CHECK(node.getNamePhoneticVariation() == "");
    CHECK(node.getPhoneticType() == "");
    CHECK(node.getRomanizedVariation() == "");
    CHECK(node.getRomanizedType() == "");
    //
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *INDIV_STRING =
        "0 @person_id@ INDI\n"
        "1 NAME John /Doe/\n"
        "2 TYPE Birth Name\n"
        "2 NPFX name_prefix\n"
        "2 GIVN name_given\n"
        "2 NICK name_nickname\n"
        "2 SPFX name_surname_prefix\n"
        "2 SURN name_surname\n"
        "2 NSFX name_suffix\n"
        "2 NOTE @notereference@\n"
        "2 SOUR @sourcereference@\n"
        "2 FONE John /Doe/\n"
        "3 TYPE Phonetic\n"
        "3 NPFX name_prefix\n"
        "3 GIVN name_given\n"
        "3 NICK name_nickname\n"
        "3 SPFX name_surname_prefix\n"
        "3 SURN name_surname\n"
        "3 NSFX name_suffix\n"
        "3 NOTE @notereference@\n"
        "3 SOUR @sourcereference@\n"
        "2 ROMN John /Doe/\n"
        "3 TYPE Romanized\n"
        "3 NPFX name_prefix\n"
        "3 GIVN name_given\n"
        "3 NICK name_nickname\n"
        "3 SPFX name_surname_prefix\n"
        "3 SURN name_surname\n"
        "3 NSFX name_suffix\n"
        "3 NOTE @notereference@\n"
        "3 SOUR @sourcereference@";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = INDIV_STRING;
    std::pair<const personalnamestructure *, std::shared_ptr<node>> pPair = fixture.createTagNode<personalnamestructure>(data, gedconstants::GED_NAME);
    const personalnamestructure *pCur = pPair.first;
    CHECK(pCur != nullptr);
    //
    CHECK(pCur->getType() == nodetype::PersonalName);
    CHECK(pCur->getName() == "John /Doe/");
    CHECK(pCur->getNameType() == "Birth Name");
    CHECK(pCur->getNamePhoneticVariation() == "John /Doe/");
    CHECK(pCur->getPhoneticType() == "Phonetic");
    CHECK(pCur->getRomanizedVariation() == "John /Doe/");
    CHECK(pCur->getRomanizedType() == "Romanized");
} // TEST_CASE
TEST_CASE("Mutator")
{
    multinode parent(0, gedconstants::GED_INDI);
    node *pTestNode = parent.getChild(gedconstants::GED_NAME, "John /Doe/");
    CHECK(pTestNode != nullptr);
    personalnamestructure *pCur = dynamic_cast<personalnamestructure *>(pTestNode);
    CHECK(pCur != nullptr);
    personalnamestructure &node = *pCur;
    //
    node.setName("John /Doe/");
    node.setNameType("Birth Name");
    node.setNamePhoneticVariation("John /Doe/");
    node.setPhoneticType("Phonetic");
    node.setRomanizedVariation("John /Doe/");
    node.setRomanizedType("Romanized");
    //
    CHECK(node.getType() == nodetype::PersonalName);
    CHECK(node.getName() == "John /Doe/");
    CHECK(node.getNameType() == "Birth Name");
    CHECK(node.getNamePhoneticVariation() == "John /Doe/");
    CHECK(node.getPhoneticType() == "Phonetic");
    CHECK(node.getRomanizedVariation() == "John /Doe/");
    CHECK(node.getRomanizedType() == "Romanized");
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();