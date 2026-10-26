///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <token.h>
//////////////////////
#include "fixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("token tests suite");
//////////////////////
TEST_CASE("parseFile")
{
    fixture fix;
    string filepath = fix.get_test_ged_filename();
    tokensLine::tokensLinesList lines;
    bool b = tokensLine::parseFile(filepath, lines);
    CHECK(b);
    CHECK(lines.size() > 0);
} // TEST_CASE
TEST_CASE("parseEntities")
{
    fixture fix;
    string filepath = fix.get_test_ged_filename();
    tokensLine::tokensLinesList lines;
    bool b = tokensLine::parseFile(filepath, lines);
    CHECK(b);
    CHECK(lines.size() > 0);
    tokensLine::tokensLinesArray ar;
    b = tokensLine::parseEntities(lines, ar);
    CHECK(b);
    CHECK(ar.size() > 0);
} // TEST_CASE
////////////////////////E
TEST_SUITE_END();
//////////////////////
