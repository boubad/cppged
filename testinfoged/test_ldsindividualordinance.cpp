///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <ldsindividualordinance.h>
#include <indivordinance.h>
#include <createnode.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("ldsindividualordinance tests suite");
//////////////////////
class LdsindividualordinanceFixture : public gedconstants
{
public:
    LdsindividualordinanceFixture()
    {
    }

    ~LdsindividualordinanceFixture()
    {
    }
    std::vector<string> getEventTags() const
    {
        return {GED_BAPL, GED_CONL, GED_ENDL, GED_SLGC};
    }
    node::nodePtr createNode(int level, const string &ParentTag) const
    {
        static const char *INDIVIDUAL_ORDINANCE_STRING =
            "1 TEST\n"
            "2 DATE 1 JAN 2000\n"
            "2 TEMP temple_code\n"
            "2 PLAC place_living_ordinance\n"
            "2 FAMC @family_reference@\n"
            "2 STAT lds_status\n"
            "3 DATE lds_status_date\n"
            "2 NOTE @ordinance_note@\n"
            "2 SOUR @source_citation@";
        const nodefixture &fixture = nodefixture::getInstance();
        string data = INDIVIDUAL_ORDINANCE_STRING;
        node::nodePtr oNodeTest = fixture.createNode(data);
        node *pTestNode = oNodeTest.get();
        CHECK(pTestNode != nullptr);
        multinode *pz = dynamic_cast<multinode *>(pTestNode);
        CHECK(pz != nullptr);
        // Node::Ptr oret = gedcomenv::create(level, ParentTag);
        node::nodePtr oret = createnode::createNode(level, ParentTag);
        node *pret = oret.get();
        CHECK(pret != nullptr);
        multinode *pmultinode = dynamic_cast<multinode *>(pret);
        CHECK(pmultinode != nullptr);
        pmultinode->setParent(pz);
        return oret;
    }
}; // class LdsindividualordinanceFixture
///////////////////////
TEST_CASE_FIXTURE(LdsindividualordinanceFixture, "get details for all family event tags")
{
    //
    std::vector<string> eventTags = getEventTags();
    multinode parent(1, GED_ABBR);
    const int addLevel = parent.getLevel() + 1;
    for (const auto &tag : eventTags)
    {
        node *pCurrent = parent.getChild(tag);
        pCurrent->setLevel(addLevel);
    } // tag
//
#if 0
    std::cout  << std::endl << "Parent Node: " << std::endl;
    parent.write(std::cout);
    std::cout << std::endl;
#endif
    //
    ldsindividualordinance ldsindividualordinance(&parent);
    //
    {
        individualordinance detail(&parent);
        bool bRet = ldsindividualordinance.getBaplOrdinance(detail);
        CHECK(bRet == true);
    }
    {
        individualordinance detail(&parent);
        bool bRet = ldsindividualordinance.getConlOrdinance(detail);
        CHECK(bRet == true);
    }
    {
        individualordinance detail(&parent);
        bool bRet = ldsindividualordinance.getEndlOrdinance(detail);
        CHECK(bRet == true);
    }
    {
        individualordinance detail(&parent);
        bool bRet = ldsindividualordinance.getSlgcOrdinance(detail);
        CHECK(bRet == true);
    }
} // TEST_CASE

//////////////////////////////
TEST_SUITE_END();