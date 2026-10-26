///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <place.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("place tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    place node;
    node.check();
    CHECK(node.getType() == nodetype::Place);
    CHECK(node.isValid() == false);
    CHECK(node.getName().empty());
    CHECK(node.getHierachy().empty());
    CHECK(node.getPhoneticVariation().empty());
    CHECK(node.getRomanizedVariation().empty());
    CHECK(node.getLatitude().empty());
    CHECK(node.getLongitude().empty());
    const place *pCur = &node;
    CHECK(pCur->findNote() == nullptr);
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *PLACE_STRING =
        "1 TEST\n"
        "2 PLAC place_name\n"
        "3 FORM place_hierachy\n"
        "3 FONE place_phonetic_variation\n"
        "4 TYPE phonetic_type\n"
        "3 ROMN place_romanized_variation\n"
        "4 TYPE romanized_type\n"
        "3 MAP place_name\n"
        "4 LATI place_latitude\n"
        "4 LONG place_longitude\n"
        "3 NOTE @place_note@";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = PLACE_STRING;
    std::pair<const place *, std::shared_ptr<node>> pPair = fixture.createTagNode<place>(data, gedconstants::GED_PLAC);
    const place *pCur = pPair.first;
    CHECK(pCur != nullptr);
    //
    CHECK(pCur->isValid() == true);
    CHECK(pCur->getName() == "place_name");
    CHECK(pCur->getHierachy() == "place_hierachy");
    CHECK(pCur->getPhoneticVariation() == "place_phonetic_variation");
    CHECK(pCur->getRomanizedVariation() == "place_romanized_variation");
    CHECK(pCur->getLatitude() == "place_latitude");
    CHECK(pCur->getLongitude() == "place_longitude");
    CHECK(pCur->findNote() != nullptr);
    CHECK(pCur->getType() == nodetype::Place);
} // TEST_CASE
TEST_CASE("Mutator")
{
    place node(1);
    node.setName("place_name");
    node.setHierachy("place_hierachy");
    node.setPhoneticVariation("place_phonetic_variation");
    node.setRomanizedVariation("place_romanized_variation");
    node.setLatitude("place_latitude");
    node.setLongitude("place_longitude");
    node.check();
    CHECK(node.getType() == nodetype::Place);
    CHECK(node.isValid() == true);
    CHECK(node.getName() == "place_name");
    CHECK(node.getHierachy() == "place_hierachy");
    CHECK(node.getPhoneticVariation() == "place_phonetic_variation");
    CHECK(node.getRomanizedVariation() == "place_romanized_variation");
    CHECK(node.getLatitude() == "place_latitude");
    CHECK(node.getLongitude() == "place_longitude");
    CHECK(node.getNote() != nullptr);
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();