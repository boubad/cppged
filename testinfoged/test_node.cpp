///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <node.h>
////////////////////////
#include "fixture.h"
#include <gedconstants.h>
/////////////////////////
#include <sstream>
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("node tests suite");
///////////////////////
TEST_CASE("Constructor")
{
    node::nodePtr oNode = node::createTest();
    node *p = oNode.get();
    CHECK(p != nullptr);
    //
    CHECK(p->getLevel() == -1);
    CHECK(p->getId().empty());
    multinode *pParent = p->getParent();
    CHECK(pParent == nullptr);
    p->setParent(pParent);
    CHECK(p->getStatus() == status::NotValid);
    p->setStatus(status::Normal);
    CHECK(p->getType() == nodetype::Base);
    CHECK(p->getTag().empty());
    CHECK(p->getValue().empty());
    p->setValue("value");
    CHECK(p->isValid() == false);
    CHECK(p->isNonCompliant() == true);
    p->check();
    //
    {
        stringstream ss;
        ss << *p;
        CHECK(ss.str().empty());
    }
    p->clear();
} // TEST_CASE Constructor
//////////////////////////////
TEST_SUITE_END();