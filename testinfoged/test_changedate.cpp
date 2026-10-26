///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <changedate.h>
#include <notestructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("changedate tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    changedate node;
    node.check();
    //
    CHECK(node.getType() == nodetype::ChangeDate);
    CHECK(node.isValid() == false);
    CHECK(node.getDate().empty());
    CHECK(node.getTime().empty());
    //
    const changedate *pCur = &node;
    CHECK(pCur->findNote() == nullptr);
    //
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *CHANGEDATE_STRING =
        "1 TEST\n"
        "2 CHAN\n"
        "3 DATE change_date\n"
        "4 TIME change_time\n"
        "3 NOTE @repository_note@";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = CHANGEDATE_STRING;
    std::pair<const changedate *, std::shared_ptr<node>> pPair = fixture.createTagNode<changedate>(data, gedconstants::GED_CHAN);
    const changedate *p = pPair.first;
    CHECK(p != nullptr);
    //
    CHECK(p->getType() == nodetype::ChangeDate);
    CHECK(p->isValid() == true);
    CHECK(p->getDate() == "change_date");
    CHECK(p->getTime() == "change_time");
    CHECK(p->findNote() != nullptr);
} // TEST_CASE
TEST_CASE("Mutator")
{
    changedate node(2);
    node.setDate("change_date");
    node.setTime("change_time");
    notestructure *pNote = node.getNote();
    CHECK(pNote != nullptr);
    pNote->setNoteReference("@repository_note@");
    //
    CHECK(node.getType() == nodetype::ChangeDate);
    CHECK(node.isValid() == true);
    CHECK(node.getDate() == "change_date");
    CHECK(node.getTime() == "change_time");
    //
    CHECK(node.getNote() != nullptr);
}
//////////////////////////////
TEST_SUITE_END();