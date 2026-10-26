///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <childtofamilylink.h>
#include <notestructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("childtofamilylink tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    childtofamilylink node;
    node.check();
    //
    CHECK(node.getType() == nodetype::ChildToFamilyLink);
    CHECK(node.isValid() == false);
    CHECK(node.getFamilyReference().empty());
    CHECK(node.getPedigreeLinkageType().empty());
    CHECK(node.getChildLinkageStatus().empty());
    CHECK(node.findNote() == nullptr);
    //
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *CHILDTOFAMILYLINK_STRING =
        "1 TEST\n"
        "2 FAMC @family_reference@\n"
        "3 PEDI pedigree_linkage_type\n"
        "3 STAT child_linkage_status\n"
        "3 NOTE @notereference@\n";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = CHILDTOFAMILYLINK_STRING;
    std::pair<const childtofamilylink *, std::shared_ptr<node>> pPair = fixture.createTagNode<childtofamilylink>(data, gedconstants::GED_FAMC);
    const childtofamilylink *p = pPair.first;
    CHECK(p != nullptr);
    //
    CHECK(p->getType() == nodetype::ChildToFamilyLink);
    CHECK(p->isValid() == true);
    CHECK(p->getFamilyReference() == "@family_reference@");
    CHECK(p->getPedigreeLinkageType() == "pedigree_linkage_type");
    CHECK(p->getChildLinkageStatus() == "child_linkage_status");
    CHECK(p->findNote() != nullptr);
}
TEST_CASE("Mutator")
{
    childtofamilylink node(1);
    node.setFamilyReference("@family_reference@");
    node.setPedigreeLinkageType("pedigree_linkage_type");
    node.setChildLinkageStatus("child_linkage_status");
    notestructure *pNote = node.getNote();
    CHECK(pNote != nullptr);
    pNote->setNoteReference("@notereference@");
    node.check();
    //
    CHECK(node.getType() == nodetype::ChildToFamilyLink);
    CHECK(node.isValid() == true);
    CHECK(node.getFamilyReference() == "@family_reference@");
    CHECK(node.getPedigreeLinkageType() == "pedigree_linkage_type");
    CHECK(node.getChildLinkageStatus() == "child_linkage_status");
    //
    CHECK(node.getNote() != nullptr);
}
//////////////////////////////
TEST_SUITE_END();