///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <eventdetail.h>
#include <place.h>
#include <addressstructure.h>
#include <sourcecitation.h>
#include <multimedialink.h>
#include <notestructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("eventdetail tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    multinode parent(2, gedconstants::GED_ABBR);
    eventdetail node(&parent);
    //
    CHECK(node.getEventOrFactClassification().empty());
    CHECK(node.getDate().empty());
    CHECK(node.getAgency().empty());
    CHECK(node.getReligiousAffiliation().empty());
    CHECK(node.getCauseOfEvent().empty());
    CHECK(node.getRestrictionNotice().empty());
    stringset oset;
    CHECK(!node.getMultimediaLinks(oset));
    //
    const eventdetail *pCur = &node;
    CHECK(pCur->findNote() == nullptr);
    CHECK(pCur->findSourceCitation() == nullptr);
    CHECK(pCur->findPlace() == nullptr);
    CHECK(pCur->findAddress() == nullptr);
    //
    CHECK(node.getNote() != nullptr);
    CHECK(node.getSourceCitation() != nullptr);
    CHECK(node.getPlace() != nullptr);
    CHECK(node.getAddress() != nullptr);
    //
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *EVENTDETAIL_STRING =
        "1 TEST\n"
        "2 TYPE event_classification\n"
        "2 DATE date\n"
        "2 PLAC placere\n"
        "2 ADDR address\n"
        "2 AGNC agency\n"
        "2 RELI religious_affiliation\n"
        "2 CAUS cause_of_event\n"
        "2 RESN restriction_notice\n"
        "2 NOTE @notereference@\n"
        "2 SOUR @sourcereference@\n"
        "2 OBJE @objectreference@1\n"
        "2 OBJE @objectreference@2";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = EVENTDETAIL_STRING;
    std::shared_ptr<node> oNodeTest = fixture.createNode(data);
    node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    eventdetail node(dynamic_cast<multinode *>(pTestNode));
    //
    CHECK(node.getEventOrFactClassification() == "event_classification");
    CHECK(node.getDate() == "date");
    CHECK(node.getAgency() == "agency");
    CHECK(node.getReligiousAffiliation() == "religious_affiliation");
    CHECK(node.getCauseOfEvent() == "cause_of_event");
    CHECK(node.getRestrictionNotice() == "restriction_notice");
    stringset oset;
    CHECK(node.getMultimediaLinks(oset));
    //
    const eventdetail *pCur = &node;
    CHECK(pCur->findNote() != nullptr);
    CHECK(pCur->findSourceCitation() != nullptr);
    CHECK(pCur->findPlace() != nullptr);
    CHECK(pCur->findAddress() != nullptr);
    //
} // TEST_CASE

//////////////////////////////
TEST_SUITE_END();