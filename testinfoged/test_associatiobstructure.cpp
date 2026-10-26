///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <associationstructure.h>
#include <sourcecitation.h>
#include <notestructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("associationstructure tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    associationstructure node;
    node.check();
    //
    CHECK(node.getType() == nodetype::Association);
    CHECK(node.getStatus() != status::Normal);
    CHECK(node.getLevel() == -1);
    CHECK(node.getId().empty());
    CHECK(node.getTag() == gedconstants::GED_ASSO);
    CHECK(node.getValue().empty());
    CHECK(node.isValid() == false);
    CHECK(node.getIndivReference().empty());
    CHECK(node.getRelationDescriptor().empty());
    //
    const associationstructure *pCur = &node;
    CHECK(pCur->findNote() == nullptr);
    CHECK(pCur->findSourceCitation() == nullptr);
    //
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *ASSOCIATION_STRING =
        "1 TEST\n"
        "2 ASSO @indiv_reference@\n"
        "3 RELA relation_descriptor\n"
        "3 SOUR @source_citation@\n"
        "3 NOTE @repository_note@";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = ASSOCIATION_STRING;
    std::pair<const associationstructure *, std::shared_ptr<node>> pPair = 
    fixture.createTagNode<associationstructure>(data, gedconstants::GED_ASSO);
    const associationstructure *p = pPair.first;
    CHECK(p != nullptr);
    //
    CHECK(p->getType() == nodetype::Association);
    CHECK(p->isValid() == true);
    CHECK(p->getIndivReference() == "@indiv_reference@");
    CHECK(p->getRelationDescriptor() == "relation_descriptor");
    CHECK(p->findNote() != nullptr);
    CHECK(p->findSourceCitation() != nullptr);
} // TEST_CASE
TEST_CASE("Mutator")
{
    multinode parent(1, "TEST");
    node *pAss = parent.getChild(gedconstants::GED_ASSO, "@indiv_reference@");
    CHECK(pAss != nullptr);
    associationstructure *pCur = dynamic_cast<associationstructure *>(pAss);
    CHECK(pCur != nullptr);
    associationstructure &node = *pCur;
    node.setRelationDescriptor("relation_descriptor");
    notestructure *pNote = node.getNote();
    CHECK(pNote != nullptr);
    sourcecitation *pSource = node.getSourceCitation();
    CHECK(pSource != nullptr);
    //
    CHECK(node.getIndivReference() == "@indiv_reference@");
    CHECK(node.getRelationDescriptor() == "relation_descriptor");
    CHECK(node.getNote() != nullptr);
    CHECK(node.getSourceCitation() != nullptr);
}
//////////////////////////////
TEST_SUITE_END();