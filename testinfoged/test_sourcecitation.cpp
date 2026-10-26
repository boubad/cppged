///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <sourcecitation.h>
#include <multimedialink.h>
#include <notestructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("sourcecitation tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    sourcecitation node;
    node.check();
    CHECK(node.getType() == nodetype::SourceCitation);
    CHECK(node.isValid() == false);
    CHECK(node.getSourceRef().empty());
    CHECK(node.getWhereWithinSource().empty());
    CHECK(node.getEventTypeCitedFrom().empty());
    CHECK(node.getRoleInEvent().empty());
    CHECK(node.getRecordingDate().empty());
    CHECK(node.getTextFromSource().empty());
    CHECK(node.getMultiMediaLink() != nullptr);
    CHECK(node.getNote() != nullptr);
    CHECK(node.getCertaintyAssessment().empty());
} // TEST_CASE
TEST_CASE("from string")
{
    static const char *SOURCECITATION_STRING =
        "1 TEST\n"
        "2 SOUR @sourcereference@\n"
        "3 PAGE where_within_source\n"
        "3 EVEN event_type_cited_from\n"
        "4 ROLE role_in_event\n"
        "3 DATA\n"
        "4 DATE entry_revording_date\n"
        "4 TEXT text_from_source_main\n"
        "3 OBJE @objectreference@\n"
        "3 NOTE @notereference@\n"
        "3 QUAY certaintyy_assessment";
    string expected_text("text_from_source_main");
    const nodefixture &fixture = nodefixture::getInstance();
    string data = SOURCECITATION_STRING;
    std::pair<const sourcecitation *, std::shared_ptr<node>> pPair = fixture.createTagNode<sourcecitation>(data, gedconstants::GED_SOUR);
    const sourcecitation *pCur = pPair.first;
    CHECK(pCur != nullptr);
    //
    CHECK(pCur->getType() == nodetype::SourceCitation);
    CHECK(pCur->isValid() == true);
    CHECK(pCur->getSourceRef() == "@sourcereference@");
    CHECK(pCur->getWhereWithinSource() == "where_within_source");
    CHECK(pCur->getEventTypeCitedFrom() == "event_type_cited_from");
    CHECK(pCur->getRoleInEvent() == "role_in_event");
    CHECK(pCur->getRecordingDate() == "entry_revording_date");
    CHECK(pCur->getTextFromSource() == expected_text);
    CHECK(pCur->findMultiMediaLink() != nullptr);
    CHECK(pCur->findNote() != nullptr);
    CHECK(pCur->getCertaintyAssessment() == "certaintyy_assessment");
    //
} // TEST_CASE
TEST_CASE("Mutator")
{
    sourcecitation node(1);
    node.setSourceRef("@sourcereference@");
    node.setWhereWithinSource("where_within_source");
    node.setEventTypeCitedFrom("event_type_cited_from");
    node.setRoleInEvent("role_in_event");
    node.setRecordingDate("entry_recording_date");
    node.setTextFromSource("text_from_source");
    node.setCertaintyAssessment("certainty_assessment");
    node.check();
    CHECK(node.getType() == nodetype::SourceCitation);
    CHECK(node.isValid() == true);
    CHECK(node.getSourceRef() == "@sourcereference@");
    CHECK(node.getWhereWithinSource() == "where_within_source");
    CHECK(node.getEventTypeCitedFrom() == "event_type_cited_from");
    CHECK(node.getRoleInEvent() == "role_in_event");
    CHECK(node.getRecordingDate() == "entry_recording_date");
    CHECK(node.getTextFromSource() == "text_from_source");
    CHECK(node.getMultiMediaLink() != nullptr);
    CHECK(node.getNote() != nullptr);
    CHECK(node.getCertaintyAssessment() == "certainty_assessment");
} // TEST_CASE}
//////////////////////////////
TEST_SUITE_END();