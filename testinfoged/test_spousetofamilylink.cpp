///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <spousetofamily.h>
#include <notestructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("spousetofamilylink tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    spousetofamilylink node;
    node.check();
    CHECK(node.getType() == nodetype::SpouseToFamilyLink);
    CHECK(node.isValid() == false);
    CHECK(node.getFamilyRef() == "");
    CHECK(node.findNote() == nullptr);
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *SPOUSETOFAMILY_STRING =
        "1 TEST\n"
        "2 FAMS @family_reference@\n"
        "3 NOTE @repository_note@";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = SPOUSETOFAMILY_STRING;
    std::pair<const spousetofamilylink *, std::shared_ptr<node>> pPair = fixture.createTagNode<spousetofamilylink>(data, gedconstants::GED_FAMS);
    const spousetofamilylink *pCur = pPair.first;
    CHECK(pCur != nullptr);
    //
    CHECK(pCur->getType() == nodetype::SpouseToFamilyLink);
    CHECK(pCur->isValid() == true);
    CHECK(pCur->getFamilyRef() == "@family_reference@");
    CHECK(pCur->findNote() != nullptr);
} // TEST_CASE
TEST_CASE("Mutator")
{
    spousetofamilylink node(1);
    node.setFamilyRef("@family_reference@");
    notestructure *pNote = node.getNote();
    CHECK(pNote != nullptr);
    pNote->setNoteReference("@repository_note@");
    node.check();
    CHECK(node.getType() == nodetype::SpouseToFamilyLink);
    CHECK(node.isValid() == true);
    CHECK(node.getFamilyRef() == "@family_reference@");
    CHECK(node.findNote() != nullptr);

} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();