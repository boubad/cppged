///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <individualeventstructure.h>
#include <individualeventdetail.h>
#include <createnode.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("individualeventstructure tests suite");
//////////////////////
class individualeventstructureFixture : public gedconstants
{
public:
    individualeventstructureFixture()
    {
    }
    ~individualeventstructureFixture()
    {
    }
    std::vector<string> getEventTags() const
    {
        return {GED_BIRT, GED_CHR, GED_DEAT, GED_BURI, GED_CREM, GED_ADOP,
                GED_BAPM, GED_BARM, GED_BASM, GED_BLES,
                GED_CHRA, GED_CONF, GED_FCOM, GED_ORDN,
                GED_NATU, GED_EMIG, GED_IMMI,
                GED_CENS, GED_PROB, GED_WILL,
                GED_GRAD, GED_RETI, GED_EVEN};
    }
    node::nodePtr createNode(int level, const string &ParentTag, const string &value = string()) const
    {
        static const char *INDIVIDUALEVENTDETAIL_STRING =
            "1 TEST\n"
            "2 AGE indiv_age\n"
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
            "2 OBJE @objectreference@2\n"
            "2 FAMC @familyreference@\n"
            "3 ADOP adopted_by_which_parent\n";

        const nodefixture &fixture = nodefixture::getInstance();
        string data = INDIVIDUALEVENTDETAIL_STRING;
        node::nodePtr oNodeTest = fixture.createNode(data);
        node *pTestNode = oNodeTest.get();
        CHECK(pTestNode != nullptr);
        multinode *pz = dynamic_cast<multinode *>(pTestNode);
        CHECK(pz != nullptr);
        node::nodePtr oret = createnode::createNode(level, ParentTag, value);
        node *pret = oret.get();
        CHECK(pret != nullptr);
        multinode *pmultinode = dynamic_cast<multinode *>(pret);
        CHECK(pmultinode != nullptr);
        pmultinode->setParent(pz);    
        return oret;
    }
}; // class individualeventstructureFixture
//////////////////////////
TEST_CASE("Default constructor")
{
    multinode parent(2, "TEST");
    individualeventstructure individualEventStructure(&parent);
    //
    CHECK(individualEventStructure.getBirth().empty());
    CHECK(individualEventStructure.getChr().empty());
    CHECK(individualEventStructure.getDeath().empty());
   //
   {
       individualeventdetail detail;
       CHECK(!individualEventStructure.getBirthDetail(detail));
   }
   //
   {
       individualeventdetail detail;
       CHECK(!individualEventStructure.getChrDetail(detail));
   }
   //
   {
       individualeventdetail detail;
       CHECK(!individualEventStructure.getDeathDetail(detail));
   }
    //
    CHECK(individualEventStructure.getBirthFamilyReference().empty());
    CHECK(individualEventStructure.getChrFamilyReference().empty());
    CHECK(individualEventStructure.getAdoptionFamilyReference().empty());
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getAdoptionDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getBurialDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getCremationDetail(detail));
    }   
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getBapmDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getBarmDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getBasmDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getBlesDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getChraDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getConfDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getFcomDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getOrdnDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getNatuDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getEmigDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getImmiDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getCensDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getProbDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getWillDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getGradDetail(detail));
    }    
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getRetiDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getAdoptionDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getWillDetail(detail));
    }
    //
    {
        individualeventdetail detail;
        CHECK(!individualEventStructure.getRetiDetail(detail));
    }
}
TEST_CASE_FIXTURE(individualeventstructureFixture, "createNode")
{
    multinode parent(2, "TEST");
    for (const string &tag : getEventTags())
    {
        string value;
        node::nodePtr oNode = createNode(3, tag, value);
        node *pNode = oNode.get();
        CHECK(pNode != nullptr);
        parent.getChildren().push_back(oNode);
    }
    //
    individualeventstructure individualEventStructure(&parent);
    //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getBirthDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getChrDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getDeathDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getBurialDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getCremationDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getAdoptionDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getBapmDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getBarmDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getBasmDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getBlesDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getChraDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getConfDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getFcomDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getOrdnDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getNatuDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getEmigDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getImmiDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getCensDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getProbDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getWillDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getGradDetail(detail));
    } //
    {
        individualeventdetail detail;
        CHECK(individualEventStructure.getRetiDetail(detail));
    }
}
///////////////////////
TEST_SUITE_END();