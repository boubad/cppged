///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <notestructure.h>
////////////////////////
#include "nodefixture.h"
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("notestructure tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
  notestructure node;
  node.check();
  //
  CHECK(node.getType() == nodetype::NoteStructure);
  CHECK(node.isValid() == false);
  CHECK(node.getLevel() == -1);
  CHECK(node.getId().empty());
  CHECK(node.getTag() == gedconstants::GED_NOTE);
  CHECK(node.getValue().empty());
  //
  const notestructure *pNode = &node;
  CHECK(pNode->getNoteReference().empty());
  CHECK(pNode->getSubmitterText().empty());

} // TEST_CASE
TEST_CASE("constructor reference")
{
  static const char *NOTESTRUCTURE_STRING_1 = "1 TEST\n"
                                              "2 NOTE @notereference@";
  const nodefixture &fixture = nodefixture::getInstance();
  //
  string data = NOTESTRUCTURE_STRING_1;
  node::nodePtr oNodeTest = fixture.createNode(data);
  const multinode *pTestNode = dynamic_cast<const multinode *>(oNodeTest.get());
  CHECK(pTestNode != nullptr);
  const node *p0 = pTestNode->findChild(gedconstants::GED_NOTE);
  CHECK(p0 != nullptr);
  const notestructure *pnotestructure = dynamic_cast<const notestructure *>(p0);
  CHECK(pnotestructure != nullptr);
  //
  CHECK(pnotestructure->getType() == nodetype::NoteStructure);
  CHECK(pnotestructure->isValid() == true);
  // CHECK(pnotestructure->getLineNumber() == Node::BAD_LINENUMBER);
  CHECK(pnotestructure->getLevel() == 2);
  CHECK(pnotestructure->getId().empty() == true);
  CHECK(pnotestructure->getTag() == gedconstants::GED_NOTE);
  CHECK(pnotestructure->getValue() == "@notereference@");
  //
  string ref = pnotestructure->getNoteReference();
  CHECK(ref == "@notereference@");
  string submittertext = pnotestructure->getSubmitterText();
  CHECK(submittertext.empty());
} // TEST_CASE
TEST_CASE("constructor data")
{
  static const char *NOTESTRUCTURE_STRING_2 = "1 TEST\n"
                                              "2 NOTE submitter_text\n"
                                              "3 CONC submitter_text_2\n"
                                              "3 CONT submitter_text_3";
  const nodefixture &fixture = nodefixture::getInstance();
  //
  string data = NOTESTRUCTURE_STRING_2;
  std::pair<const notestructure *, std::shared_ptr<node>> pPair =
      fixture.createTagNode<notestructure>(data, gedconstants::GED_NOTE);
  const notestructure *p = pPair.first;
  CHECK(p != nullptr);
  //
  CHECK(p->isValid() == true);
  CHECK(p->getType() == nodetype::NoteStructure);
  CHECK(p->getLevel() == 2);
  CHECK(p->getId().empty() == true);
  CHECK(p->getTag() == gedconstants::GED_NOTE);
  CHECK(p->getValue() == "submitter_text");
  //
  string ref = p->getNoteReference();
  CHECK(ref.empty());
  string submittertext = p->getSubmitterText();
  CHECK(submittertext.empty() == false);
} // TEST_CASE
TEST_CASE("Copy constructor")
{
  notestructure note(2);
  note.check();
  note.setSubmitterText("bla bla bla");
  CHECK(note.isValid() == true);
  CHECK(note.getType() == nodetype::NoteStructure);
  string subtext = note.getSubmitterText();
  CHECK(subtext == "bla bla bla");
  //
  notestructure note2(note);
  note2.check();
  CHECK(note2.isValid() == true);
  CHECK(note2.getType() == nodetype::NoteStructure);
  subtext = note2.getSubmitterText();
  CHECK(subtext == "bla bla bla");
  //
  notestructure note3;
  note3 = note;
  note3.check();
  CHECK(note3.isValid() == true);
  CHECK(note3.getType() == nodetype::NoteStructure);
  subtext = note3.getSubmitterText();
  CHECK(subtext == "bla bla bla");
} //
TEST_CASE("Mutator")
{
  notestructure note(2);
  note.check();
  CHECK(note.isValid() == false);
  CHECK(note.getType() == nodetype::NoteStructure);
  string ref = note.getNoteReference();
  CHECK(ref.empty() == true);
  note.setNoteReference("@toto@");
  ref = note.getNoteReference();
  CHECK(ref == "@toto@");
  note.setSubmitterText("bla bla bla");
  string subtext = note.getSubmitterText();
  CHECK(subtext == "bla bla bla");
}
//////////////////////////////
TEST_SUITE_END();