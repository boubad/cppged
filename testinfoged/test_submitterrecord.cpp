///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <submitterrecord.h>
#include <addressstructure.h>
#include <changedate.h>
#include <multimedialink.h>
#include <notestructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("submitterrecord tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    submitterrecord node;
    node.check();
    CHECK(node.getType() == nodetype::Submitter);
    CHECK(node.isValid() == false);
    CHECK(node.getId().empty());
    CHECK(node.getSubmitterName().empty());
    CHECK(node.getLanguagePreference().empty());
    CHECK(node.getSubmitterRegisteredRfn().empty());
    CHECK(node.getAutomatedRecordId().empty());
    //
    const submitterrecord *pConst = &node;
    CHECK(pConst->findAddress() == nullptr);
    CHECK(pConst->findMultimediaLink() == nullptr);
    CHECK(pConst->findNote() == nullptr);
    CHECK(pConst->findChangedate() == nullptr);
    //
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *SUBMITTER_STRING =
        "0 @submitter_id@ SUBM\n"
        "1 NAME submitter_name\n"
        "1 ADDR\n"
        "2 ADR1 address_line_1\n"
        "2 ADR2 address_line_2\n"
        "2 CITY city_name\n"
        "2 STAE state_name\n"
        "2 POST postal_code\n"
        "2 CTRY country_name\n"
        "1 LANG language_preference\n"
        "1 RFN submitter_registered_rfn\n"
        "1 RIN automated_record_id\n"
        "1 NOTE @notereference@\n"
        "1 CHAN\n"
        "2 DATE change_date\n"
        "1 OBJE @objectreference@";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = SUBMITTER_STRING;
    node::nodePtr oNodeTest = fixture.createNode(data);
    const node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    const submitterrecord *pCur = dynamic_cast<const submitterrecord *>(pTestNode);
    CHECK(pCur != nullptr);
    submitterrecord *p = const_cast<submitterrecord *>(pCur);
    p->check();
    submitterrecord &node = *p;
    //
    CHECK(node.getType() == nodetype::Submitter);
    CHECK(node.getId() == "@submitter_id@");
    CHECK(node.getSubmitterName() == "submitter_name");
    CHECK(node.getLanguagePreference() == "language_preference");
    CHECK(node.getSubmitterRegisteredRfn() == "submitter_registered_rfn");
    CHECK(node.getAutomatedRecordId() == "automated_record_id");
    //
    const submitterrecord *pConst = &node;
    CHECK(pConst->findAddress() != nullptr);
    CHECK(pConst->findMultimediaLink() != nullptr);
    CHECK(pConst->findNote() != nullptr);
    CHECK(pConst->findChangedate() != nullptr);
} // TEST_CASE
TEST_CASE("Mutator")
{
    submitterrecord node("@submitter_id@");
    node.setSubmitterName("submitter_name");
    node.setLanguagePreference("language_preference");
    node.setSubmitterRegisteredRfn("submitter_registered_rfn");
    node.setAutomatedRecordId("automated_record_id");
    addressstructure *pAddress = node.getAddress();
    CHECK(pAddress != nullptr);
    changedate *pChangedate = node.getChangedate();
    CHECK(pChangedate != nullptr);
    notestructure *pNote = pChangedate->getNote();
    CHECK(pNote != nullptr);
    node.check();
    //
    CHECK(node.getType() == nodetype::Submitter);
    CHECK(node.getId() == "@submitter_id@");
    CHECK(node.getSubmitterName() == "submitter_name");
    CHECK(node.getLanguagePreference() == "language_preference");
    CHECK(node.getSubmitterRegisteredRfn() == "submitter_registered_rfn");
    CHECK(node.getAutomatedRecordId() == "automated_record_id");
    CHECK(node.getAddress() != nullptr);
    CHECK(node.getChangedate() != nullptr);
    CHECK(node.getNote() != nullptr);
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();