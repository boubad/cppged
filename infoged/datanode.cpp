#include "datanode.h"
#include "stringutils.h"
//////////////////////////////
namespace infoged
{
    /////////////////////////
    datanode::datanode(int level, const string &tag, const string &value, const string &id) : node(), linedata(level, tag, value, id)
    {
    }
    datanode::datanode(const datanode &other) : node(other), linedata(other)
    {
    }
    datanode &datanode::operator=(const datanode &other)
    {
        if (this != &other)
        {
            node::operator=(other);
            linedata::operator=(other);
        }
        return *this;
    }
    datanode::~datanode()
    {
    }
    ////////////////////////////
    int datanode::getLevel(void) const
    {
        return linedata::getLevel();
    }
    void datanode::setLevel(int level)
    {
        linedata::setLevel(level);
    }
    const string &datanode::getId(void) const
    {
        return linedata::getId();
    }
    multinode *datanode::getParent(void) const
    {
        return linedata::getParent();
    }
    void datanode::setParent(multinode *p)
    {
        linedata::setParent(p);
    }
    status datanode::getStatus(void) const
    {
        return linedata::getStatus();
    }
    void datanode::setStatus(status st)
    {
        linedata::setStatus(st);
    }
    nodetype datanode::getType(void) const
    {
        return nodetype::Single;
    }
    const string &datanode::getTag(void) const
    {
        return linedata::getTag();
    }
    const string &datanode::getValue(void) const
    {
        return linedata::getValue();
    }
    void datanode::setValue(const string &value)
    {
        linedata::setValue(value);
    }
    bool datanode::isValid(void) const
    {
        return linedata::isValid();
    }
    void datanode::check(void)
    {
        linedata::check();
    }
    ostream &datanode::write(ostream &os) const
    {
        return linedata::write(os);
    }
    string datanode::getLineString(void) const
    {
        stringstream os;
        datanode::write(os);
        return os.str();
    }
    void datanode::clear(void)
    {
        linedata::clear();
    }

    void datanode::mutate(const std::function<void(node *)> &func)
    {
        func(this);
    }
    void datanode::visit(const std::function<void(const node *)> &func) const
    {
        func(this);
    }
    ///////////////////////////
} // namespace infoged