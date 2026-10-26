///////////////////////
#include <doctest/doctest.h>
//////////////////////
#include <stringutils.h>
#include <stringconstants.h>
//////////////////////
using namespace infoged;
///////////////////////
TEST_SUITE("stringutils tests suite")
{
    TEST_CASE("uppercase")
    {
        string s = stringutils::uppercase("hello");
        CHECK(s == "HELLO");
    }
    TEST_CASE("trim")
    {
        string s = stringutils::trim("  hello  ");
        CHECK(s == "hello");
    }
    TEST_CASE("splitlinevalue")
    {
        string s = "hello world";
        stringvector values;
        stringutils::splitlinevalue(s, values, 5);
        CHECK(values.size() == 3);
        CHECK(values[0] == "hello");
        CHECK(values[1] == " worl");
        CHECK(values[2] == "d");
    }
    TEST_CASE("isPointer")
    {
        string s = "@hello@";
        CHECK(stringutils::isPointer(s));
        s = "hello";
        CHECK(!stringutils::isPointer(s));
        s = "@hello";
        CHECK(!stringutils::isPointer(s));
        s = "hello@";
        CHECK(!stringutils::isPointer(s));
        s = string();
        CHECK(!stringutils::isPointer(s));
    }
    TEST_CASE("isTag")
    {
        string s = stringconstants::AROBAS + "hello" + stringconstants::AROBAS;
        CHECK(!stringutils::isTag(s));
        s = "hello";
        CHECK(stringutils::isTag(s));
        s = stringconstants::AROBAS + "hello";
        CHECK(!stringutils::isTag(s));
        s = "hello" + stringconstants::AROBAS;
        CHECK(!stringutils::isTag(s));
        s = string();
        CHECK(!stringutils::isTag(s));
        s = "_wt_uwer";
        CHECK(stringutils::isTag(s));
        s = "_primary";
        CHECK(stringutils::isTag(s));
    }
    TEST_CASE("isNumber")
    {
        string s = "123";
        CHECK(stringutils::isNumber(s));
        s = "1.23";
        CHECK(stringutils::isNumber(s));
        s = "afr.23.4";
        CHECK(!stringutils::isNumber(s));
        s = string();
        CHECK(!stringutils::isNumber(s));
    }
} // TEST_SUITE