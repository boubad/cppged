///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <gedcomline.h>
//////////////////////
using namespace infoged;
///////////////////////
TEST_SUITE_BEGIN("gedcomline tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    gedcomline tl;
    CHECK(tl.isValid() == false);
    CHECK(tl.getLevel() == -1);
    CHECK(tl.getId().empty());
    CHECK(tl.getTag().empty());
    CHECK(tl.getValue().empty());
} // TEST_CASE
TEST_CASE("constructor normal")
{
    gedcomline tl(2, "tag", "value", "@id@");
    CHECK(tl.isValid() == true);
    CHECK(tl.getLevel() == 2);
    CHECK(tl.getId() == "@id@");
    CHECK(tl.getTag() == "TAG");
    CHECK(tl.getValue() == "value");
    //
    gedcomline tl2 = tl;
    CHECK(tl2.isValid() == true);
    CHECK(tl2.getLevel() == 2);
    CHECK(tl2.getId() == "@id@");
    CHECK(tl2.getTag() == "TAG");
    CHECK(tl2.getValue() == "value");
    //
    gedcomline tl3(tl);
    CHECK(tl3.isValid() == true);
    CHECK(tl3.getLevel() == 2);
    CHECK(tl3.getId() == "@id@");
    CHECK(tl3.getTag() == "TAG");
    CHECK(tl3.getValue() == "value");
    //
    tl.clear();
    CHECK(tl.isValid() == false);
    CHECK(tl.getLevel() == -1);
    CHECK(tl.getId().empty());
    CHECK(tl.getTag().empty());
    CHECK(tl.getValue().empty());
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();