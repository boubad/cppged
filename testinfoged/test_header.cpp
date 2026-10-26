///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <header.h>
#include <addressstructure.h>
#include <notestructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("header tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    header node;
    node.check();
    CHECK(node.getType() == nodetype::Header);
    CHECK(node.isValid() == false);
    CHECK(node.getSourceApprovedId() == "");
    CHECK(node.getSourceVersion() == "");
    CHECK(node.getSourceName() == "");
    CHECK(node.getSourceCorporation() == "");
    CHECK(node.getCorporationAddress() != nullptr);
    CHECK(node.getSourceDataName() == "");
    CHECK(node.getSourcePublicationDate() == "");
    CHECK(node.getSourceCopyright() == "");
    CHECK(node.getReceivingSystemName() == "");
    CHECK(node.getTransmissionDate() == "");
    CHECK(node.getTransmissionTime() == "");
    CHECK(node.getSubmitterReference() == "");
    CHECK(node.getSubmissionReference() == "");
    CHECK(node.getFileName() == "");
    CHECK(node.getGedcomFileCopyright() == "");
    CHECK(node.getGedcomVersion() == "");
    CHECK(node.getGedcomFormat() == "");
    CHECK(node.getCharacterSet() == "");
    CHECK(node.getCharacterSetVersion() == "");
    CHECK(node.getLanguage() == "");
    CHECK(node.getPlaceHierarchy() == "");
    CHECK(node.getNote() != nullptr);
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *HEADER_STRING =
        "0 HEAD\n"
        "1 SOUR source_approved_id\n"
        "2 VERS source_version\n"
        "2 NAME source_name\n"
        "2 CORP source_corporation\n"
        "3 ADDR source_corporation_address\n"
        "2 DATA source_data_name\n"
        "3 DATE source_publication_date\n"
        "3 COPR source_copyright\n"
        "4 CONT source_copyright_cont\n"
        "1 DEST ANY\n"
        "1 DATE transmission_date\n"
        "2 TIME transmission_time\n"
        "1 SUBM @submitter_reference@\n"
        "1 SUBN @submission_reference@\n"
        "1 FILE file_name\n"
        "1 COPR gedcom_file_copyright\n"
        "1 GEDC\n"
        "2 VERS gedcom_version\n"
        "2 FORM gedcom_format\n"
        "1 CHAR character_set\n"
        "2 VERS character_set_version\n"
        "1 LANG language\n"
        "1 PLAC\n"
        "2 FORM place_hierarchy\n"
        "1 NOTE gedcom_content_description\n"
        "2 CONT gedcom_content_description_cont";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = HEADER_STRING;
    node::nodePtr oNodeTest = fixture.createNode(data);
    const node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    const header *pCur = dynamic_cast<const header *>(pTestNode);
    CHECK(pCur != nullptr);
    header *p = const_cast<header *>(pCur);
    p->check();
    header &node = *p;
    //
    CHECK(node.getType() == nodetype::Header);
    CHECK(node.getSourceApprovedId() == "source_approved_id");
    CHECK(node.getSourceVersion() == "source_version");
    CHECK(node.getSourceName() == "source_name");
    CHECK(node.getSourceCorporation() == "source_corporation");
    CHECK(node.getCorporationAddress() != nullptr);
    CHECK(node.getSourceDataName() == "source_data_name");
    CHECK(node.getSourcePublicationDate() == "source_publication_date");
    CHECK(node.getSourceCopyright() == "source_copyright");
    CHECK(node.getReceivingSystemName() == "ANY");
    CHECK(node.getTransmissionDate() == "transmission_date");
    CHECK(node.getTransmissionTime() == "transmission_time");
    CHECK(node.getSubmitterReference() == "@submitter_reference@");
    CHECK(node.getSubmissionReference() == "@submission_reference@");
    CHECK(node.getFileName() == "file_name");
    CHECK(node.getGedcomFileCopyright() == "gedcom_file_copyright");
    CHECK(node.getGedcomVersion() == "gedcom_version");
    CHECK(node.getGedcomFormat() == "gedcom_format");
    CHECK(node.getCharacterSet() == "character_set");
    CHECK(node.getCharacterSetVersion() == "character_set_version");
    CHECK(node.getLanguage() == "language");
    CHECK(node.getPlaceHierarchy() == "place_hierarchy");
    CHECK(node.getNote() != nullptr);
} // TEST_CASE
TEST_CASE("Mutator")
{
    header node;
    node.setSourceApprovedId("source_approved_id");
    node.setSourceVersion("source_version");
    node.setSourceName("source_name");
    node.setSourceCorporation("source_corporation");
    addressstructure *pAddr = node.getCorporationAddress();
    CHECK(pAddr != nullptr);
    node.setSourceDataName("source_data_name");
    node.setSourcePublicationDate("source_publication_date");
    node.setSourceCopyright("source_copyright");
    node.setReceivingSystemName("ANY");
    node.setTransmissionDate("transmission_date");
    node.setTransmissionTime("transmission_time");
    node.setSubmitterReference("@submitter_reference@");
    node.setSubmissionReference("@submission_reference@");
    node.setFileName("file_name");
    node.setGedcomFileCopyright("gedcom_file_copyright");
    node.setGedcomVersion("gedcom_version");
    node.setGedcomFormat("gedcom_format");
    node.setCharacterSet("character_set");
    node.setCharacterSetVersion("character_set_version");
    node.setLanguage("language");
    node.setPlaceHierarchy("place_hierarchy");
    notestructure *pNote = node.getNote();
    CHECK(pNote != nullptr);
    pNote->setSubmitterText("gedcom_content_description");
    node.check();
    //
    CHECK(node.getType() == nodetype::Header);
    CHECK(node.getSourceApprovedId() == "source_approved_id");
    CHECK(node.getSourceVersion() == "source_version");
    CHECK(node.getSourceName() == "source_name");
    CHECK(node.getSourceCorporation() == "source_corporation");
    CHECK(node.getCorporationAddress() != nullptr);
    CHECK(node.getSourceDataName() == "source_data_name");
    CHECK(node.getSourcePublicationDate() == "source_publication_date");
    CHECK(node.getSourceCopyright() == "source_copyright");
    CHECK(node.getReceivingSystemName() == "ANY");
    CHECK(node.getTransmissionDate() == "transmission_date");
    CHECK(node.getTransmissionTime() == "transmission_time");
    CHECK(node.getSubmitterReference() == "@submitter_reference@");
    CHECK(node.getSubmissionReference() == "@submission_reference@");
    CHECK(node.getFileName() == "file_name");
    CHECK(node.getGedcomFileCopyright() == "gedcom_file_copyright");
    CHECK(node.getGedcomVersion() == "gedcom_version");
    CHECK(node.getGedcomFormat() == "gedcom_format");
    CHECK(node.getCharacterSet() == "character_set");
    CHECK(node.getCharacterSetVersion() == "character_set_version");
    CHECK(node.getLanguage() == "language");
    CHECK(node.getPlaceHierarchy() == "place_hierarchy");
    CHECK(node.getNote() != nullptr);
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();