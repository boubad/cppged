///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <linedata.h>
#include <stringutils.h>
////////////////////////
using namespace infoged;
///////////////////////
TEST_SUITE_BEGIN("linedata tests suite");
///////////////////////
TEST_CASE("Constructor")
{
    linedata node;
    //
    CHECK(node.getLevel() == -1);
    node.setLevel(3);
    CHECK(node.getLevel() == 3);
    //
    string id = node.getId();
    CHECK(id.empty());
    node.setId("@id@");
    CHECK(node.getId() == "@id@");
    node.setId("cxdser");
    CHECK(node.getId().empty());
    node.clear();
    //
    string tag = node.getTag();
    CHECK(tag.empty());
    node.setTag("TAG");
    CHECK(node.getTag() == "TAG");
    node.setTag("1235");
    CHECK(!node.getTag().empty());
    node.clear();
    //
    string value = node.getValue();
    CHECK(value.empty());
    node.setValue("value");
    CHECK(node.getValue() == "value");
     node.clear();
    //
    CHECK(node.isValid() == false);
    CHECK(node.getStatus() == status::NotValid);
    node.setStatus(status::Normal);
    CHECK(node.getStatus() == status::Normal);
    node.clear();
    //
    multinode *pParent = node.getParent();
    CHECK(pParent == nullptr);
    node.setParent(pParent);
    CHECK(node.getParent() == nullptr);
    //
    node.clear();
} // TEST_CASE Constructor
TEST_CASE("full constructor")
{
    const int level = 3;
    const string tag = "tag";
    const string expectedTag = stringutils::uppercase(stringutils::trim(tag));
    const string value = "value";
    const string id = "@id@";
    //
    linedata node(level, tag, value, id);
    //
    CHECK(node.getLevel() == level);
    CHECK(node.getTag() == expectedTag);
    CHECK(node.getValue() == value);
    CHECK(node.getId() == id);
}// TEST_CASE
//////////////////////////////
TEST_SUITE_END();