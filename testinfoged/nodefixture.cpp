#include "nodefixture.h"
//////////////////////////////
#include <multinode.h>
#include <gedcomline.h>
#include <createnode.h>
//////////////////////////
#include <cassert>
/////////////////////////////////
namespace infoged
{
    namespace test
    {
        nodefixture::nodefixture()
        {
        }
        nodefixture::~nodefixture()
        {
        }
        const nodefixture &nodefixture::getInstance(void)
        {
            static nodefixture fixture_;
            return fixture_;
        }
        std::shared_ptr<node> nodefixture::createFromStream(istream &is) const
        {
           return createnode::createNode(is);
        }
        std::shared_ptr<node> nodefixture::createNode(const string &data) const
        {
            return createnode::createNode(data);
        }
    } // namespace test
} // namespace infoged
