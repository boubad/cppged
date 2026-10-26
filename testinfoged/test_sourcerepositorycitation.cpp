///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <sourcerepositorycitation.h>
#include <notestructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("sourcerepositorycitation tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    sourcerepositorycitation node;
    node.check();
    CHECK(node.getType() == nodetype::SourceRepositoryCitation);
    CHECK(node.isValid() == false);
    CHECK(node.getRepositoryRef() == "");
    CHECK(node.getSourceCallNumber() == "");
    CHECK(node.getSourceMediaType() == "");
    //
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *SOURCE_REPOSITORY_STRING =
        "2 REPO @repository_reference@\n"
        "3 NOTE @repository_note@\n"
        "3 CALN source_call_number\n"
        "4 MEDI source_media_type";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = SOURCE_REPOSITORY_STRING;
    node::nodePtr oNodeTest = fixture.createNode(data);
    const node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    const sourcerepositorycitation *pCur = dynamic_cast<const sourcerepositorycitation *>(pTestNode);
    CHECK(pCur != nullptr);
    sourcerepositorycitation *p = const_cast<sourcerepositorycitation *>(pCur);
    p->check();
    sourcerepositorycitation &node = *p;
    //
    CHECK(node.getType() == nodetype::SourceRepositoryCitation);
    CHECK(node.isValid() == true);
    CHECK(node.getRepositoryRef() == "@repository_reference@");
    CHECK(node.getSourceCallNumber() == "source_call_number");
    CHECK(node.getSourceMediaType() == "source_media_type");
} // TEST_CASE
TEST_CASE("Mutator")
{
    sourcerepositorycitation node(1);
    node.setRepositoryRef("@repository_reference@");
    notestructure *pNote = node.getNote();
    CHECK(pNote != nullptr);
    pNote->setNoteReference("@repository_note@");
    node.setSourceCallNumber("source_call_number");
    node.setSourceMediaType("source_media_type");

    node.check();
    //
    CHECK(node.getType() == nodetype::SourceRepositoryCitation);
    CHECK(node.isValid() == true);
    CHECK(node.getRepositoryRef() == "@repository_reference@");
    CHECK(node.getNote() != nullptr);
    CHECK(node.getSourceCallNumber() == "source_call_number");
    CHECK(node.getSourceMediaType() == "source_media_type");
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();