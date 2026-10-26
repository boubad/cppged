///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <proxynode.h>
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
    proxynode pnode(p);
    //
    stringset values;
    CHECK(pnode.getAllStringValues(tag1, values));
    CHECK(!values.empty());
    //
    CHECK(pnode.getChildValue(tag1) == testValue1);
    CHECK(pnode.getChildValue(tag1, tag2) == testValue2);
    CHECK(pnode.getChildValue(tag1, tag2, tag3) == testValue3);
    CHECK(pnode.getChildValue(tag1, tag2, tag3, tag4) == testValue4);
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
    multinode parent(testLevel, testTag, testValue, testId);
    //
    proxynode pnode(&parent);
    //
    pnode.setChildValue(tag1, testValue1);
    pnode.setChildValue(tag1, tag2, testValue2);
    pnode.setChildValue(tag1, tag2, tag3, testValue3);
    pnode.setChildValue(tag1, tag2, tag3, tag4, testValue4);
    //
    CHECK(pnode.getChildValue(tag1) == testValue1);
    CHECK(pnode.getChildValue(tag1, tag2) == testValue2);
    CHECK(pnode.getChildValue(tag1, tag2, tag3) == testValue3);
    CHECK(pnode.getChildValue(tag1, tag2, tag3, tag4) == testValue4);
}// TEST_CASE Proxynode functions
//////////////////////////////
TEST_SUITE_END();
