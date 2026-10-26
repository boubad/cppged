///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <repositoryrecord.h>
#include <addressstructure.h>
#include <changedate.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("repositoryrecord tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    repositoryrecord node;
    CHECK(node.getType() == nodetype::Repository);
    node.check();
    CHECK(node.isValid() == false);
    CHECK(node.getNameOfRepository().empty());
    CHECK(node.findAddress() == nullptr);
    CHECK(node.findNote() == nullptr);
    CHECK(node.findChangedate() == nullptr);
    CHECK(node.getUserReferenceNumber().empty());
    CHECK(node.getUserReferenceType().empty());
    CHECK(node.getAutomatedRecordId().empty());
    //
    CHECK(node.getAddress() != nullptr);
    CHECK(node.getNote() != nullptr);
    CHECK(node.getChangedate() != nullptr);
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *REPOSITORY_RECORD_STRING =
        "0 @repository_reference@ REPO\n"
        "1 NAME name_of_repository\n"
        "1 ADDR repository_address\n"
        "1 NOTE @repository_note@\n"
        "1 REFN user_reference_number\n"
        "2 TYPE user_reference_type\n"
        "1 RIN automated_record_id\n"
        "1 CHAN\n"
        "2 DATE change_date\n"
        "3 TIME change_time";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = REPOSITORY_RECORD_STRING;
    node::nodePtr oNodeTest = fixture.createNode(data);
    const node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    const repositoryrecord *pCur = dynamic_cast<const repositoryrecord *>(pTestNode);
    CHECK(pCur != nullptr);
    repositoryrecord *p = const_cast<repositoryrecord *>(pCur);
    p->check();
    repositoryrecord &node = *p;
    //
    CHECK(node.getType() == nodetype::Repository);
    CHECK(node.isValid() == true);
    CHECK(node.getId() == "@repository_reference@");
    CHECK(node.getNameOfRepository() == "name_of_repository");
    CHECK(node.findAddress() != nullptr);
    CHECK(node.findNote() != nullptr);
    CHECK(node.findChangedate() != nullptr);
    CHECK(node.getUserReferenceNumber() == "user_reference_number");
    CHECK(node.getUserReferenceType() == "user_reference_type");
    CHECK(node.getAutomatedRecordId() == "automated_record_id");
} // TEST_CASE
TEST_CASE("Mutator")
{
    repositoryrecord node("@repository_reference@");
    node.setNameOfRepository("name_of_repository");
    addressstructure *pAddr = node.getAddress();
    CHECK(pAddr != nullptr);
    notestructure *pNote = node.getNote();
    CHECK(pNote != nullptr);
    node.setUserReferenceNumber("user_reference_number");
    node.setUserReferenceType("user_reference_type");
    node.setAutomatedRecordId("automated_record_id");
    changedate *pChangeDate = node.getChangedate();
    CHECK(pChangeDate != nullptr);
    node.check();
    //
    CHECK(node.getType() == nodetype::Repository);
    CHECK(node.isValid() == true);
    CHECK(node.getId() == "@repository_reference@");
    CHECK(node.getNameOfRepository() == "name_of_repository");
    CHECK(node.findAddress() != nullptr);
    CHECK(node.findNote() != nullptr);
    CHECK(node.findChangedate() != nullptr);
    CHECK(node.getUserReferenceNumber() == "user_reference_number");
    CHECK(node.getUserReferenceType() == "user_reference_type");
    CHECK(node.getAutomatedRecordId() == "automated_record_id");

} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();