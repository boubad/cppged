///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <indivordinance.h>
#include <notestructure.h>
#include <sourcecitation.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("indivordinance tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    multinode parent(2, gedconstants::GED_ABBR);
    individualordinance node(&parent);
    //
    CHECK(node.getDateLdsOrd() == "");
    CHECK(node.getTempleCode() == "");
    CHECK(node.getPlaceLivingOrdinance() == "");
    CHECK(node.getFamilyReference() == "");
    CHECK(node.getLdsStatus() == "");
    CHECK(node.getLdsStatusDate() == "");
    //
    const individualordinance *pCur = &node;
    CHECK(pCur->findSourceCitation() == nullptr);
    CHECK(pCur->findNote() == nullptr);
    //
     individualordinance *p = &node;
    CHECK(p->getSourceCitation() != nullptr);
    CHECK(p->getNote() != nullptr);
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *INDIVIDUAL_ORDINANCE_STRING =
        "1 TEST\n"
        "2 DATE 1 JAN 2000\n"
        "2 TEMP temple_code\n"
        "2 PLAC place_living_ordinance\n"
        "2 FAMC @family_reference@\n"
        "2 STAT lds_status\n"
        "3 DATE lds_status_date\n"
        "2 NOTE @ordinance_note@\n"
        "2 SOUR @source_citation@";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = INDIVIDUAL_ORDINANCE_STRING;
    node::nodePtr oNodeTest = fixture.createNode(data);
    const node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    multinode *pz = dynamic_cast<multinode *>(const_cast<node *>(pTestNode));
    CHECK(pz != nullptr);
    individualordinance node(pz);
    //
    CHECK(node.getDateLdsOrd() == "1 JAN 2000");
    CHECK(node.getTempleCode() == "temple_code");
    CHECK(node.getPlaceLivingOrdinance() == "place_living_ordinance");
    CHECK(node.getFamilyReference() == "@family_reference@");
    CHECK(node.getLdsStatus() == "lds_status");
    CHECK(node.getLdsStatusDate() == "lds_status_date");
    //
    const individualordinance *pCur2 = &node;
    CHECK(pCur2->findSourceCitation() != nullptr);
    CHECK(pCur2->findNote() != nullptr);
} // TEST_CASE
TEST_CASE("Mutator")
{
    multinode parent(2, gedconstants::GED_ABBR);
    individualordinance node(&parent);
    //
    node.setDateLdsOrd("1 JAN 2000");
    node.setTempleCode("temple_code");
    node.setPlaceLivingOrdinance("place_living_ordinance");
    node.setFamilyReference("@family_reference@");
    node.setLdsStatus("lds_status");
    node.setLdsStatusDate("lds_status_date");
    //
    sourcecitation *pSourceCitation = node.getSourceCitation();
    CHECK(pSourceCitation != nullptr);
    pSourceCitation->setSourceRef("@source_citation@");
    notestructure *pNote = node.getNote();
    CHECK(pNote != nullptr);
    pNote->setNoteReference("@ordinance_note@");
    //
    CHECK(node.getDateLdsOrd() == "1 JAN 2000");
    CHECK(node.getTempleCode() == "temple_code");
    CHECK(node.getPlaceLivingOrdinance() == "place_living_ordinance");
    CHECK(node.getFamilyReference() == "@family_reference@");
    CHECK(node.getLdsStatus() == "lds_status");
    CHECK(node.getLdsStatusDate() == "lds_status_date");
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();