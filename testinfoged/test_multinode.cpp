///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <multinode.h>
////////////////////////
#include "fixture.h"
#include <gedconstants.h>
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("multinode tests suite");
///////////////////////
TEST_CASE("Constructor")
{
    multinode node;
    node.check();
    multinode *p = &node;
    //
    CHECK(p->getLevel() == -1);
    //
    CHECK(p->getId().empty());
    CHECK(p->getTag().empty());
    CHECK(p->getValue().empty());
    //
} // TEST_CASE Constructor
TEST_CASE("Base functions")
{
    int testLevel = 2;
    string testId = "@id@";
    string testTag = "TAG";
    string testValue = "value";
    string tag1 = "TAG1";
    string tag2 = "TAG2";
    string tag3 = "TAG3";
    //
    multinode node(testLevel, testTag, testValue, testId);
    infoged::node *p1 = node.getChild(tag1, testValue);
    CHECK(p1 != nullptr);
    multinode *p1m = dynamic_cast<multinode *>(p1);
    CHECK(p1m != nullptr);
    infoged::node *p2 = p1m->getChild(tag2, testValue);
    CHECK(p2 != nullptr);
    multinode *p2m = dynamic_cast<multinode *>(p2);
    CHECK(p2m != nullptr);
    infoged::node *p3 = p2m->getChild(tag3, testValue);
    CHECK(p3 != nullptr);
    //
    node.check();
    multinode *p = &node;
    //
    CHECK(p->getLevel() == testLevel);
    CHECK(p->getId() == testId);
    CHECK(p->getTag() == testTag);
    CHECK(p->getValue() == testValue);
    //
    CHECK(p->getChildren().size() == 1);
    //
    CHECK(p->findChild(tag1) != nullptr);
    //
} // TEST_CASE Base functions
TEST_CASE("Children functions")
{
    int testLevel = 2;
    string testId = "@id@";
    string testTag = "TAG";
    string testValue = "value";
    string testValue1 = "value1";
    string testValue2 = "value2";
    string testValue3 = "value3";
    string testValue4 = "value4";
    string tag1 = "TAG1";
    string tag2 = "TAG2";
    string tag3 = "TAG3";
    string tag4 = "TAG4";
    //
    multinode node(testLevel, testTag, testValue, testId);
    infoged::node *p1 = node.getChild(tag1, testValue1);
    CHECK(p1 != nullptr);
    multinode *p1m = dynamic_cast<multinode *>(p1);
    CHECK(p1m != nullptr);
    infoged::node *p2 = p1m->getChild(tag2, testValue2);
    CHECK(p2 != nullptr);
    multinode *p2m = dynamic_cast<multinode *>(p2);
    CHECK(p2m != nullptr);
    infoged::node *p3 = p2m->getChild(tag3, testValue3);
    CHECK(p3 != nullptr);
    multinode *p3m = dynamic_cast<multinode *>(p3);
    CHECK(p3m != nullptr);
    infoged::node *p4 = p3m->getChild(tag4, testValue4);
    CHECK(p4 != nullptr);
    //
    node.check();
    //
    multinode *p = &node;
    //
    stringset values;
    CHECK(p->getAllStringValues(tag1, values));
    CHECK(!values.empty());
    //
    CHECK(p->getValue() == testValue);
    CHECK(p->getChildValue(tag1) == testValue1);
    CHECK(p->getChildValue(tag1, tag2) == testValue2);
    CHECK(p->getChildValue(tag1, tag2, tag3) == testValue3);
    CHECK(p->getChildValue(tag1, tag2, tag3, tag4) == testValue4);
    //
} // TEST_CASE Children functions
TEST_CASE("Proxynode functions")
{
    int testLevel = 2;
    string testId = "@id@";
    string testTag = "TAG";
    string testValue = "value";
    string testValue1 = "value1";
    string testValue2 = "value2";
    string testValue3 = "value3";
    string testValue4 = "value4";
    string tag1 = "TAG1";
    string tag2 = "TAG2";
    string tag3 = "TAG3";
    string tag4 = "TAG4";
    //
    multinode node(testLevel, testTag, testValue, testId);
    node.setChildValue(tag1, testValue1);
    node.setChildValue(tag1, tag2, testValue2);
    node.setChildValue(tag1, tag2, tag3, testValue3);
    node.setChildValue(tag1, tag2, tag3, tag4, testValue4);
    //
    CHECK(node.getChildValue(tag1) == testValue1);
    CHECK(node.getChildValue(tag1, tag2) == testValue2);
    CHECK(node.getChildValue(tag1, tag2, tag3) == testValue3);
    CHECK(node.getChildValue(tag1, tag2, tag3, tag4) == testValue4);
} // TEST_CASE Proxynode functions
//////////////////////////////
TEST_SUITE_END();
