///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <addressstructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("addressstructure tests suite");
///////////////////////

TEST_CASE("constructor from string")
{
    static const char *ADDRESS_STRING =
        "1 TEST\n"
        "2 ADDR address_line\n"
        "3 ADR1 address_line1\n"
        "3 ADR2 address_line2\n"
        "3 ADR3 address_line3\n"
        "3 CITY address_city\n"
        "3 STAE address_state\n"
        "3 POST address_postcode\n"
        "3 CTRY address_country\n"
        "2 PHON phone_number\n"
        "2 EMAIL address_email\n"
        "2 FAX address_fax\n"
        "2 WWWW address_web_page";
    //
    const nodefixture &fixture = nodefixture::getInstance();
    string data = ADDRESS_STRING;
    std::pair<const addressstructure *, std::shared_ptr<node>> pPair = fixture.createTagNode<addressstructure>(data, gedconstants::GED_ADDR);
    const addressstructure *p = pPair.first;
    CHECK(p != nullptr);
    //
    CHECK(p->getType() == nodetype::Address);
    CHECK(p->getLevel() == 2);
    CHECK(p->getStatus() == status::Normal);
    CHECK(p->isValid() == true);
    CHECK(p->getAddrLine() == "address_line");
    CHECK(p->getAddr1() == "address_line1");
    CHECK(p->getAddr2() == "address_line2");
    CHECK(p->getAddr3() == "address_line3");
    CHECK(p->getCity() == "address_city");
    CHECK(p->getState() == "address_state");
    CHECK(p->getPost() == "address_postcode");
    CHECK(p->getCountry() == "address_country");
    CHECK(p->getPhone() == "phone_number");
    CHECK(p->getEmail() == "address_email");
    CHECK(p->getFax() == "address_fax");
    CHECK(p->getWebsite() == "address_web_page");
} // TEST_CASE
TEST_CASE("Mutator")
{
    multinode parent(1, "TEST");
    node *pAddr0 = parent.getChild(gedconstants::GED_ADDR, "address_line");
    CHECK(pAddr0 != nullptr);
    node *pTestNode = parent.getChild(gedconstants::GED_ADDR);
    CHECK(pTestNode != nullptr);
    addressstructure *pCur = dynamic_cast<addressstructure *>(pTestNode);
    CHECK(pCur != nullptr);
    addressstructure &node = *pCur;
    //
    node.setAddrLine("address_line");
    node.setAddr1("address_line1");
    node.setAddr2("address_line2");
    node.setAddr3("address_line3");
    node.setCity("address_city");
    node.setState("address_state");
    node.setPost("address_postcode");
    node.setCountry("address_country");
    node.setPhone("phone_number");
    node.setEmail("address_email");
    node.setFax("address_fax");
    node.setWebsite("address_web_page");
    node.check();
    //
    CHECK(node.getLevel() == 2);
    CHECK(node.getStatus() == status::Normal);
    CHECK(node.getType() == nodetype::Address);
    CHECK(node.isValid() == true);
    CHECK(node.getAddrLine() == "address_line");
    CHECK(node.getAddr1() == "address_line1");
    CHECK(node.getAddr2() == "address_line2");
    CHECK(node.getAddr3() == "address_line3");
    CHECK(node.getCity() == "address_city");
    CHECK(node.getState() == "address_state");
    CHECK(node.getPost() == "address_postcode");
    CHECK(node.getCountry() == "address_country");
    CHECK(node.getPhone() == "phone_number");
    CHECK(node.getEmail() == "address_email");
    CHECK(node.getFax() == "address_fax");
    CHECK(node.getWebsite() == "address_web_page");
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();