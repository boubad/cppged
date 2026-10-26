///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <multimedialink.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("multimedialink tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    multimedialink node;
    node.check();
    CHECK(node.isValid() == false);
    CHECK(node.getObjectReference() == "");
    CHECK(node.getFileRef() == "");
    CHECK(node.getFormat() == "");
    CHECK(node.getMediaType() == "");
    CHECK(node.getTitle() == "");
    CHECK(node.getType() == nodetype::MultimediaLink);
} // TEST_CASE
TEST_CASE("constructor 1")
{
    multimedialink node(1, "@xref@");
    node.check();
    CHECK(node.isValid() == true);
    CHECK(node.getObjectReference() == "@xref@");
    CHECK(node.getFileRef() == "");
    CHECK(node.getFormat() == "");
    CHECK(node.getMediaType() == "");
    CHECK(node.getTitle() == "");
    CHECK(node.getType() == nodetype::MultimediaLink);
} // TEST_CASE
TEST_CASE("constructor 2")
{
    static const char *MULTIMEDIALINK_STRING_2 =
        "1 TEST\n"
        "2 OBJE\n"
        "3 FILE multimedia_file_refn\n"
        "4 FORM multimedia_file_format\n"
        "5 MEDI source_media_type\n"
        "3 TITL descroptive_title";
    const nodefixture &fixture = nodefixture::getInstance();
    //
    string data = MULTIMEDIALINK_STRING_2;
    std::pair<const multimedialink *, std::shared_ptr<node>> pPair = fixture.createTagNode<multimedialink>(data, gedconstants::GED_OBJE);
    const multimedialink *p = pPair.first;
    CHECK(p != nullptr);
    //
    CHECK(p->isValid() == true);
    CHECK(p->getObjectReference() == "");
    CHECK(p->getFileRef() == "multimedia_file_refn");
    CHECK(p->getFormat() == "multimedia_file_format");
    CHECK(p->getMediaType() == "source_media_type");
    CHECK(p->getTitle() == "descroptive_title");
    CHECK(p->getType() == nodetype::MultimediaLink);
    //
} // TEST_CASE
TEST_CASE("Mutator")
{
    multimedialink node(1);
    node.setFileRef("multimedia_file_refn");
    node.setFormat("multimedia_file_format");
    node.setMediaType("source_media_type");
    node.setTitle("descroptive_title");
    node.check();
    CHECK(node.isValid() == true);
    CHECK(node.getFileRef() == "multimedia_file_refn");
    CHECK(node.getFormat() == "multimedia_file_format");
    CHECK(node.getMediaType() == "source_media_type");
    CHECK(node.getTitle() == "descroptive_title");
    CHECK(node.getType() == nodetype::MultimediaLink);
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();