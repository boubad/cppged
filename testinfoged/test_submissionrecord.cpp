///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <submissionrecord.h>
#include <changedate.h>
#include <notestructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("submissionrecord tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    submissionrecord node;
    node.check();
    CHECK(node.getType() == nodetype::Submission);
    CHECK(node.isValid() == false);
    CHECK(node.getSubmitterId().empty());
    CHECK(node.getNameOfFamilyFile().empty());
    CHECK(node.getTempleCode().empty());
    CHECK(node.getAncestorsGenerations().empty());
    CHECK(node.getDescendantsGenerations().empty());
    CHECK(node.getOrdinanceProcessFlag().empty());
    //
    const submissionrecord *pConst = &node;
    CHECK(pConst->findNote() == nullptr);
    CHECK(pConst->findChangedate() == nullptr);
    //
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *SUBMISSION_STRING =
        "0 @submission_id@ SUBN\n"
        "1 SUBM @submitter_id@\n"
        "1 FAMF name_of_family_file\n"
        "1 TEMP temple_code\n"
        "1 ANCE ancestors_generations\n"
        "1 DESC descendants_generations\n"
        "1 ORDI ordinance_process_flag\n"
        "1 RIN automated_record_id\n"
        "1 NOTE @notereference@\n"
        "1 CHAN\n"
        "2 DATE change_date\n"
        "3 TIME change_time";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = SUBMISSION_STRING;
    node::nodePtr oNodeTest = fixture.createNode(data);
    const node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    const submissionrecord *pCur = dynamic_cast<const submissionrecord *>(pTestNode);
    CHECK(pCur != nullptr);
    submissionrecord *p = const_cast<submissionrecord *>(pCur);
    p->check();
    submissionrecord &node = *p;
    //
    CHECK(node.getType() == nodetype::Submission);
    CHECK(node.isValid() == true);
    CHECK(node.getSubmitterId() == "@submitter_id@");
    CHECK(node.getNameOfFamilyFile() == "name_of_family_file");
    CHECK(node.getTempleCode() == "temple_code");
    CHECK(node.getAncestorsGenerations() == "ancestors_generations");
    CHECK(node.getDescendantsGenerations() == "descendants_generations");
    CHECK(node.getOrdinanceProcessFlag() == "ordinance_process_flag");
    //
    const submissionrecord *pConst = &node;
    CHECK(pConst->findNote() != nullptr);
    CHECK(pConst->findChangedate() != nullptr);
    //
} // TEST_CASE
TEST_CASE("Mutator")
{
    submissionrecord node("@submission_id@");
    node.setSubmitterId("@submitter_id@");
    node.setNameOfFamilyFile("name_of_family_file");
    node.setTempleCode("temple_code");
    node.setAncestorsGenerations("ancestors_generations");
    node.setDescendantsGenerations("descendants_generations");
    node.setOrdinanceProcessFlag("ordinance_process_flag");
    notestructure *pNote = node.getNote();
    CHECK(pNote != nullptr);
    changedate *pChangedate = node.getChangedate();
    CHECK(pChangedate != nullptr);
    node.check();
    //
    CHECK(node.getType() == nodetype::Submission);
    CHECK(node.getId() == "@submission_id@");
    CHECK(node.getSubmitterId() == "@submitter_id@");
    CHECK(node.getNameOfFamilyFile() == "name_of_family_file");
    CHECK(node.getTempleCode() == "temple_code");
    CHECK(node.getAncestorsGenerations() == "ancestors_generations");
    CHECK(node.getDescendantsGenerations() == "descendants_generations");
    CHECK(node.getOrdinanceProcessFlag() == "ordinance_process_flag");
    CHECK(node.getNote() != nullptr);
    CHECK(node.getChangedate() != nullptr);
}
//////////////////////////////
TEST_SUITE_END();