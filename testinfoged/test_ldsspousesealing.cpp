///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <ldsspousesealing.h>
#include <notestructure.h>
#include <sourcecitation.h>
#include <createnode.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("ldsindividualordinance tests suite");
///////////////////////
TEST_CASE("default constructor")
{
    ldsspousesealing node;
    node.check();
    //
    CHECK(node.getType() == nodetype::LdsSpouseSealing);
    CHECK(node.isValid() == false);
    CHECK(node.getDate() == "");
    CHECK(node.getTempleCode() == "");
    CHECK(node.getPlaceLivingOrdinance() == "");
    CHECK(node.getLesSpouseSealingDateStatus() == "");
    CHECK(node.getStatusDate() == "");
    //
    const ldsspousesealing *pCur = &node;
    CHECK(pCur->findNote() == nullptr);
    CHECK(pCur->findSourceCitation() == nullptr);
    //
} // TEST_CASE
TEST_CASE("constructor from string")
{
    static const char *LDS_SPOUSE_SEALING_STRING =
        "1 TEST\n"
        "2 SLGC\n"
        "3 DATE 1 JAN 2000\n"
        "3 TEMP temple_code\n"
        "3 PLAC place_living_ordinance\n"
        "3 STAT les_spouse_sealing_date_status\n"
        "4 DATE 2 FEB 2000\n"
        "3 NOTE @note_reference@\n"
        "3 SOUR @source_reference@";
    const nodefixture &fixture = nodefixture::getInstance();
    string data = LDS_SPOUSE_SEALING_STRING;
    std::pair<const ldsspousesealing *, std::shared_ptr<node>> pPair = fixture.createTagNode<ldsspousesealing>(data, gedconstants::GED_SLGC);
    const ldsspousesealing *p = pPair.first;
    CHECK(p != nullptr);
    //
    CHECK(p->getType() == nodetype::LdsSpouseSealing);
    CHECK(p->isValid() == true);
    CHECK(p->getDate() == "1 JAN 2000");
    CHECK(p->getTempleCode() == "temple_code");
    CHECK(p->getPlaceLivingOrdinance() == "place_living_ordinance");
    CHECK(p->getLesSpouseSealingDateStatus() == "les_spouse_sealing_date_status");
    CHECK(p->getStatusDate() == "2 FEB 2000");
    CHECK(p->findNote() != nullptr);
    CHECK(p->findSourceCitation() != nullptr);
    //
} // TEST_CASE
TEST_CASE("Mutator")
{
    ldsspousesealing node(2);
    node.setDate("1 JAN 2000");
    node.setTempleCode("temple_code");
    node.setPlaceLivingOrdinance("place_living_ordinance");
    node.setLesSpouseSealingDateStatus("les_spouse_sealing_date_status");
    node.setStatusDate("2 FEB 2000");
    notestructure *pNote = node.getNote();
    CHECK(pNote != nullptr);
    pNote->setNoteReference("@note_reference@");
    sourcecitation *pSource = node.getSourceCitation();
    CHECK(pSource != nullptr);
    pSource->setSourceRef("@source_reference@");
    node.check();
    //
    CHECK(node.getType() == nodetype::LdsSpouseSealing);
    CHECK(node.isValid() == true);
    CHECK(node.getDate() == "1 JAN 2000");
    CHECK(node.getTempleCode() == "temple_code");
    CHECK(node.getPlaceLivingOrdinance() == "place_living_ordinance");
    CHECK(node.getLesSpouseSealingDateStatus() == "les_spouse_sealing_date_status");
    CHECK(node.getStatusDate() == "2 FEB 2000");
    //
    const ldsspousesealing *pCur2 = &node;
    CHECK(pCur2->findNote() != nullptr);
    CHECK(pCur2->findSourceCitation() != nullptr);
    //
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();