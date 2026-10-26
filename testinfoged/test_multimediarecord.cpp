///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <multimediarecord.h>
#include <sourcecitation.h>
#include <changedate.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("multimediarecord tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    multimediarecord node;
    CHECK(node.getType() == nodetype::Multimedia);
    node.check();
    CHECK(node.isValid() == false);
    CHECK(node.getMediaFileName() == "");
    CHECK(node.getFormat() == "");
    CHECK(node.getMediaType() == "");
    CHECK(node.getMediaDescriptiveTitle() == "");
    CHECK(node.getUserReferenceNumber() == "");
    CHECK(node.getUserReferenceType() == "");
    CHECK(node.getAutomatedRecordId() == "");
    CHECK(node.getNote() != nullptr);
    CHECK(node.getSourceCitation() != nullptr);
    CHECK(node.getChangedate() != nullptr);
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *MULTIMEDIA_RECORD_STRING =
        "0 @multimedia_reference@ OBJE\n"
        "1 FILE media_file_name\n"
        "2 FORM format\n"
        "3 TYPE media_type\n"
        "2 TITL media_descriptive_title\n"
        "1 REFN user_reference_number\n"
        "2 TYPE user_reference_type\n"
        "1 RIN automated_record_id\n"
        "1 NOTE @repository_note@\n"
        "1 SOUR @repository_reference@\n"
        "1 CHAN\n"
        "2 DATE change_date\n"
        "3 TIME change_time";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = MULTIMEDIA_RECORD_STRING;
    node::nodePtr oNodeTest = fixture.createNode(data);
    const node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    const multimediarecord *pCur = dynamic_cast<const multimediarecord *>(pTestNode);
    CHECK(pCur != nullptr);
    multimediarecord *p = const_cast<multimediarecord *>(pCur);
    p->check();
    multimediarecord &node = *p;
    //
    CHECK(node.getType() == nodetype::Multimedia);
    CHECK(node.isValid() == true);
    CHECK(node.getId() == "@multimedia_reference@");
    CHECK(node.getMediaFileName() == "media_file_name");
    CHECK(node.getFormat() == "format");
    CHECK(node.getMediaType() == "media_type");
    CHECK(node.getMediaDescriptiveTitle() == "media_descriptive_title");
    CHECK(node.getUserReferenceNumber() == "user_reference_number");
    CHECK(node.getUserReferenceType() == "user_reference_type");
    CHECK(node.getAutomatedRecordId() == "automated_record_id");
    CHECK(node.getNote() != nullptr);
    CHECK(node.getSourceCitation() != nullptr);
    CHECK(node.getChangedate() != nullptr);
} // TEST_CASE
TEST_CASE("Mutator")
{
    multimediarecord node("@multimedia_reference@");
    node.setMediaFileName("media_file_name");
    node.setFormat("format");
    node.setMediaType("media_type");
    node.setMediaDescriptiveTitle("media_descriptive_title");
    node.setUserReferenceNumber("user_reference_number");
    node.setUserReferenceType("user_reference_type");
    node.setAutomatedRecordId("automated_record_id");
    notestructure *pNote = node.getNote();
    CHECK(pNote != nullptr);
    sourcecitation *pSour = node.getSourceCitation();
    CHECK(pSour != nullptr);
    changedate *pChan = node.getChangedate();
    CHECK(pChan != nullptr);
    //
    node.check();
    CHECK(node.getType() == nodetype::Multimedia);
    CHECK(node.getId() == "@multimedia_reference@");
    CHECK(node.getMediaFileName() == "media_file_name");
    CHECK(node.getFormat() == "format");
    CHECK(node.getMediaType() == "media_type");
    CHECK(node.getMediaDescriptiveTitle() == "media_descriptive_title");
    CHECK(node.getUserReferenceNumber() == "user_reference_number");
    CHECK(node.getUserReferenceType() == "user_reference_type");
    CHECK(node.getAutomatedRecordId() == "automated_record_id");
    CHECK(node.getNote() != nullptr);
    CHECK(node.getSourceCitation() != nullptr);
    CHECK(node.getChangedate() != nullptr);
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();