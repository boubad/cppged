#include "node.h"
#include "multinode.h"
///////////////////////
namespace infoged
{
  ///////////////////////////////
  // node class implementation
  node::node()
  {
  }
  node::node(const node & /*other*/)
  {
  }
  node &node::operator=(const node & /*other*/)
  {
    return *this;
  }
  node::~node()
  {
  }
  ///////////////////////////////////////
  int node::getLevel(void) const
  {
    return -1;
  }
  void node::setLevel(int /*level*/)
  {
    // do nothing here
  }
  const string &node::getId(void) const
  {
    static const string empty;
    return empty;
  }
  multinode *node::getParent(void) const
  {
    return nullptr;
  }
  void node::setParent(multinode * /*p*/)
  {
    // do nothing here
  }
  status node::getStatus(void) const
  {
    return status::NotValid;
  }
  void node::setStatus(status /*st*/)
  {
    // do nothing here
  }
  nodetype node::getType(void) const
  {
    return nodetype::Base;
  }
  const string &node::getTag(void) const
  {
    static const string empty;
    return empty;
  }
  const string &node::getValue(void) const
  {
    static const string empty;
    return empty;
  }

  void node::setValue(const string & /*value*/)
  {
    // do nothing here
  }
  bool node::isValid(void) const
  {
    return false;
  }
  bool node::isNonCompliant(void) const
  {
    return getStatus() != status::Normal;
  }
  void node::check(void)
  {
    // do nothing here
  }
  ostream &node::write(ostream &os) const
  {
    return os;
  }
  void node::clear(void)
  {
    // do nothing here
  }
  node::nodePtr node::createTest(void)
  {
    nodePtr oRet(new node());
    return oRet;
  }
  ///////////////////////////////////
  void node::mutate(const std::function<void(node *)> & /*func*/)
  {
  }
  void node::visit(const std::function<void(const node *)> & /*func*/) const
  {
  }
  void node::remove(const std::function<bool(const node *)> & /*func*/)
  {
  }
  string node::getLineString(void) const
  {
    return string();
  }
  ////////////////////////////////
} // namespace infoged