///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <sourcerecord.h>
#include <sourcerepositorycitation.h>
#include <addressstructure.h>
#include <multimedialink.h>
#include <changedate.h>
#include <notestructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("sourcerecord tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    sourcerecord node;
    CHECK(node.getType() == nodetype::Source);
    node.check();
    sourcerecord *p = &node;
    CHECK(node.isValid() == false);
    CHECK(node.getEventsRecorded().empty());
    CHECK(node.getDatePeriod().empty());
    CHECK(node.getJurisdictionPlace().empty());
    CHECK(node.getResponsibleAgency().empty());
    CHECK(p->findDataNote() == nullptr);
    CHECK(node.getSourceOriginators().empty());
    CHECK(node.getSourceDescriptiveTitles().empty());
    CHECK(node.getSourceFiledByEntry().empty());
    CHECK(node.getSourcePublicationFacts().empty());
    CHECK(node.getSourceTexts().empty());
    CHECK(p->findSourceRepositoryCitation() == nullptr);
    CHECK(node.getUserReferenceNumber().empty());
    CHECK(node.getUserReferenceType().empty());
    CHECK(node.getAutomatedRecordId().empty());
    CHECK(p->findChangedate() == nullptr);
    CHECK(p->findNote() == nullptr);
    stringset multimedialinks;
    CHECK(!node.getMultimediaLinks(multimedialinks));
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *SOURCE_RECORD_STRING =
        "0 @source_id@ SOUR\n"
        "1 DATA\n"
        "2 EVEN events_recorded\n"
        "3 DATE date_period\n"
        "3 PLAC jurisdiction_place\n"
        "2 AGNC responsible_agency\n"
        "2 NOTE @data_note@\n"
        "1 AUTH source_originators\n"
        "1 TITL source_descriptive_titles\n"
        "1 ABBR source_filed_by_entry\n"
        "1 PUBL source_publication_facts\n"
        "1 TEXT source_texts\n"
        "1 REFN user_reference_number\n"
        "2 TYPE user_reference_type\n"
        "1 RIN automated_record_id\n"
        "1 CHAN\n"
        "2 DATE change_date\n"
        "3 TIME change_time\n"
        "1 NOTE @repository_note@\n"
        "1 OBJE @multimedia_link@\n";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = SOURCE_RECORD_STRING;
    node::nodePtr oNodeTest = fixture.createNode(data);
    const node *pTestNode = oNodeTest.get();
    CHECK(pTestNode != nullptr);
    const sourcerecord *pCur = dynamic_cast<const sourcerecord *>(pTestNode);
    CHECK(pCur != nullptr);
    sourcerecord *p = const_cast<sourcerecord *>(pCur);
    p->check();
    sourcerecord &node = *p;
    CHECK(node.getType() == nodetype::Source);
    CHECK(node.isValid() == true);
    CHECK(node.getId() == "@source_id@");
    CHECK(node.getEventsRecorded() == "events_recorded");
    CHECK(node.getDatePeriod() == "date_period");
    CHECK(node.getJurisdictionPlace() == "jurisdiction_place");
    CHECK(node.getResponsibleAgency() == "responsible_agency");
    CHECK(node.getDataNote() != nullptr);
    CHECK(node.getSourceOriginators() == "source_originators");
    CHECK(node.getSourceDescriptiveTitles() == "source_descriptive_titles");
    CHECK(node.getSourceFiledByEntry() == "source_filed_by_entry");
    CHECK(node.getSourcePublicationFacts() == "source_publication_facts");
    CHECK(node.getSourceTexts() == "source_texts");
    CHECK(node.getSourceRepositoryCitation() != nullptr);
    CHECK(node.getUserReferenceNumber() == "user_reference_number");
    CHECK(node.getUserReferenceType() == "user_reference_type");
    CHECK(node.getAutomatedRecordId() == "automated_record_id");
    CHECK(node.getChangedate() != nullptr);
    CHECK(node.getNote() != nullptr);
    stringset multimedialinks;
    CHECK(node.getMultimediaLinks(multimedialinks));
} // TEST_CASE
TEST_CASE("Mutator")
{
    sourcerecord node("@source_id@");
    sourcerecord *p = &node;
    node.setEventsRecorded("events_recorded");
    node.setDatePeriod("date_period");
    node.setJurisdictionPlace("jurisdiction_place");
    node.setResponsibleAgency("responsible_agency");
    notestructure *pDataNote = node.getDataNote();
    CHECK(pDataNote != nullptr);
    pDataNote->setNoteReference("@data_note@");
    node.setSourceOriginator("source_originators");
    node.setSourceDescriptiveTitle("source_descriptive_titles");
    node.setSourceFiledByEntry("source_filed_by_entry");
    node.setSourcePublicationFact("source_publication_facts");
    node.setSourceText("source_texts");
    sourcerepositorycitation *pRepoCitation = p->getSourceRepositoryCitation();
    CHECK(pRepoCitation != nullptr);
    pRepoCitation->setRepositoryRef("@repository_reference@");
    notestructure *pNote = p->getNote();
    CHECK(pNote != nullptr);
    pNote->setNoteReference("@repository_note@");
    node.setUserReferenceNumber("user_reference_number");
    node.setUserReferenceType("user_reference_type");
    node.setAutomatedRecordId("automated_record_id");
    changedate *pChangeDate = p->getChangedate();
    CHECK(pChangeDate != nullptr);
    CHECK(pChangeDate->getNote() != nullptr);
    node.check();
    CHECK(node.getType() == nodetype::Source);
    CHECK(node.getId() == "@source_id@");
    CHECK(node.getEventsRecorded() == "events_recorded");
    CHECK(node.getDatePeriod() == "date_period");
    CHECK(node.getJurisdictionPlace() == "jurisdiction_place");
    CHECK(node.getResponsibleAgency() == "responsible_agency");
    CHECK(node.findDataNote() != nullptr);
    CHECK(node.getSourceOriginators() == "source_originators");
    CHECK(node.getSourceDescriptiveTitles() == "source_descriptive_titles");
    CHECK(node.getSourceFiledByEntry() == "source_filed_by_entry");
    CHECK(node.getSourcePublicationFacts() == "source_publication_facts");
    CHECK(node.getSourceTexts() == "source_texts");
    CHECK(p->findSourceRepositoryCitation() != nullptr);
    CHECK(node.getUserReferenceNumber() == "user_reference_number");
    CHECK(node.getUserReferenceType() == "user_reference_type");
    CHECK(node.getAutomatedRecordId() == "automated_record_id");
    CHECK(p->findChangedate() != nullptr);
    CHECK(p->findNote() != nullptr);
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();