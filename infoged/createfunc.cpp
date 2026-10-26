#include "createfunc.h"
///////////////////////
#include "stringutils.h"
#include "gedconstants.h"
/////////////////////////
#include "addressstructure.h"
#include "notestructure.h"
#include "place.h"
#include "changedate.h"
#include "sourcecitation.h"
#include "sourcerepositorycitation.h"
#include "spousetofamily.h"
#include "childtofamilylink.h"
#include "associationstructure.h"
#include "ldsspousesealing.h"
#include "familyrecord.h"
#include "header.h"
#include "trailer.h"
#include "personalnamestructure.h"
#include "individualrecord.h"
#include "repositoryrecord.h"
#include "sourcerecord.h"
#include "multimedialink.h"
#include "multimediarecord.h"
#include "noterecord.h"
#include "submissionrecord.h"
#include "submitterrecord.h"
#include "gedcomline.h"
///////////////////////
#include <cassert>
#include <map>
#include <mutex>
#include <atomic>
//////////////////////
namespace infoged
{
    /////////////////////////////////
    static std::map<string, node::nodeCreateFunc> NODE_CREATORS;
    static std::mutex NODE_CREATORS_MUTEX;
    static std::atomic<bool> NODE_CREATORS_INITIALIZED(false);
    //////////////////////////////
    static void initializeFuncMap(void)
    {
        if (NODE_CREATORS_INITIALIZED.load())
        {
            return;
        }
        {
            std::lock_guard<std::mutex> lock(NODE_CREATORS_MUTEX);
            /////////////////////////////////
            NODE_CREATORS[gedconstants::GED_ADDR] =
                [](int level, const string &value, const string & /*id*/,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level > 0)
                {
                    return std::make_shared<addressstructure>(level, value);
                }
                else
                {
                    return node::nodePtr();
                }
            }; // ADDR
            NODE_CREATORS[gedconstants::GED_NOTE] =
                [](int level, const string &value, const string &id,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level == 0 && stringutils::isPointer(id))
                {
                    return std::make_shared<noterecord>(id, value);
                }
                else
                {
                    return std::make_shared<notestructure>(level, value);
                }
            }; //
            NODE_CREATORS[gedconstants::GED_PLAC] =
                [](int level, const string &value, const string & /*id*/,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level > 0)
                {
                    return std::make_shared<place>(level, value);
                }
                else
                {
                    return node::nodePtr();
                }
            }; // PLAC
            NODE_CREATORS[gedconstants::GED_CHAN] =
                [](int level, const string & /*value*/, const string & /*id*/,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level > 0)
                {
                    return std::make_shared<changedate>(level);
                }
                else
                {
                    return node::nodePtr();
                }
            }; // CHAN
            NODE_CREATORS[gedconstants::GED_SOUR] =
                [](int level, const string &value, const string &id,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level == 0 && stringutils::isPointer(id))
                {
                    return std::make_shared<sourcerecord>(id);
                }
                else
                {
                    return std::make_shared<sourcecitation>(level, value);
                }
            }; // SOUR
            NODE_CREATORS[gedconstants::GED_REPO] =
                [](int level, const string &value, const string &id,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level == 0 && stringutils::isPointer(id))
                {
                    return std::make_shared<repositoryrecord>(id);
                }
                else
                {
                    return std::make_shared<sourcerepositorycitation>(level, value);
                }
            }; // REPO
            NODE_CREATORS[gedconstants::GED_FAMS] =
                [](int level, const string &value, const string & /*id*/,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level > 0)
                {
                    return std::make_shared<spousetofamilylink>(level, value);
                }
                else
                {
                    return node::nodePtr();
                }
            }; // FAMS
            NODE_CREATORS[gedconstants::GED_FAMC] =
                [](int level, const string &value, const string & /*id*/,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level > 0)
                {
                    return std::make_shared<childtofamilylink>(level, value);
                }
                else
                {
                    return node::nodePtr();
                }
            }; // FAMC
            NODE_CREATORS[gedconstants::GED_ASSO] =
                [](int level, const string &value, const string & /*id*/,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level > 0)
                {
                    return std::make_shared<associationstructure>(level, value);
                }
                else
                {
                    return node::nodePtr();
                }
            }; // ASSO
            NODE_CREATORS[gedconstants::GED_SLGC] =
                [](int level, const string & /*value*/, const string & /*id*/,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level > 0)
                {
                    return std::make_shared<ldsspousesealing>(level);
                }
                else
                {
                    return node::nodePtr();
                }
            }; // SLGC
            NODE_CREATORS[gedconstants::GED_FAM] =
                [](int level, const string & /*value*/, const string &id,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level == 0 && stringutils::isPointer(id))
                {
                    return std::make_shared<familyrecord>(id);
                }
                else
                {
                    return node::nodePtr();
                }
            }; // FAM
            NODE_CREATORS[gedconstants::GED_HEAD] =
                [](int level, const string & /*value*/, const string & /*id*/,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level == 0)
                {
                    return std::make_shared<header>();
                }
                else
                {
                    return node::nodePtr();
                }
            }; // HEAD
            NODE_CREATORS[gedconstants::GED_TRLR] =
                [](int level, const string & /*value*/, const string & /*id*/,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level == 0)
                {
                    return std::make_shared<trailer>();
                }
                else
                {
                    return node::nodePtr();
                }
            }; // TRLR
            NODE_CREATORS[gedconstants::GED_NAME] =
                [](int level, const string &value, const string & /*id*/,
                   const string &parentTag) -> node::nodePtr
            {
                if (level > 0 && parentTag == gedconstants::GED_INDI)
                {
                    return std::make_shared<personalnamestructure>(level, value);
                }
                else
                {
                    return std::make_shared<multinode>(level, gedconstants::GED_NAME, value);
                }
            }; // NAME
            NODE_CREATORS[gedconstants::GED_INDI] =
                [](int level, const string & /*value*/, const string &id,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level == 0 && stringutils::isPointer(id))
                {
                    return std::make_shared<individualrecord>(id);
                }
                else
                {
                    return node::nodePtr();
                }
            }; // INDI
            NODE_CREATORS[gedconstants::GED_OBJE] =
                [](int level, const string &value, const string &id,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level == 0 && stringutils::isPointer(id))
                {
                    return std::make_shared<multimediarecord>(id);
                }
                else
                {
                    return std::make_shared<multimedialink>(level, value);
                }
            }; // OBJE
            NODE_CREATORS[gedconstants::GED_SUBN] =
                [](int level, const string &value, const string &id,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level == 0 && stringutils::isPointer(id))
                {
                    return std::make_shared<submissionrecord>(id);
                }
                else
                {
                    return std::make_shared<multinode>(level, gedconstants::GED_SUBN, value);
                }
            }; // SUBN
            NODE_CREATORS[gedconstants::GED_SUBM] =
                [](int level, const string &value, const string &id,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level == 0 && stringutils::isPointer(id))
                {
                    return std::make_shared<submitterrecord>(id);
                }
                else
                {
                    return std::make_shared<multinode>(level, gedconstants::GED_SUBM, value);
                }
            }; // SUBM
            NODE_CREATORS[gedconstants::GED_DEST] =
                [](int level, const string &value, const string & /*id*/,
                   const string & /*parentTag*/) -> node::nodePtr
            {
                if (level > 0)
                {
                    return std::make_shared<gedcomline>(level, gedconstants::GED_DEST,
                                                        value, value);
                }
                else
                {
                    return node::nodePtr();
                }
            }; // DEST
            ///////////////////////////////////
            NODE_CREATORS_INITIALIZED.store(true);
        } // lock
    } // initializeFuncMap
    /////////////////////////////////
    const node::nodeCreateFunc *createfunc::getCreateFunc(const string &tag)
    {

        initializeFuncMap();
        string stag = stringutils::uppercase(stringutils::trim(tag));
        auto it = NODE_CREATORS.find(stag);
        if (it != NODE_CREATORS.end())
        {
            return &it->second;
        }
        return nullptr;
    }
} // namespace infoged