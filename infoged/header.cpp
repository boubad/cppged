
//////////////////////
#include "header.h"
//////////////////////
#include "addressstructure.h"
#include "notestructure.h"
#include "gedconstants.h"
///////////////////////
#include <cassert>
//////////////////////
namespace infoged
{
    header::header() : guardnode(gedconstants::GED_HEAD)
    {
    }
    header::header(const header &other) : guardnode(other)
    {
    }

    header &header::operator=(const header &other)
    {
        if (this != &other)
        {
            guardnode::operator=(other);
        }
        return *this;
    }

    header::~header()
    {
    }
    //////////////////////////////
    string header::getSourceApprovedId(void) const
    {
        return getChildValue(gedconstants::GED_SOUR);
    }
    void header::setSourceApprovedId(const string &source)
    {
        setChildValue(gedconstants::GED_SOUR, source);
    } // setSource
    string header::getSourceVersion(void) const
    {
        return getChildValue(gedconstants::GED_SOUR, gedconstants::GED_VERS);
    }
    void header::setSourceVersion(const string &version)
    {
        setChildValue(gedconstants::GED_SOUR, gedconstants::GED_VERS, version);
    } // setSourceVersion
    string header::getSourceName(void) const
    {
        return getChildValue(gedconstants::GED_SOUR, gedconstants::GED_NAME);
    } // getSourceName
    void header::setSourceName(const string &name)
    {
        setChildValue(gedconstants::GED_SOUR, gedconstants::GED_NAME, name);
    }
    string header::getSourceCorporation(void) const
    {
        return getChildValue(gedconstants::GED_SOUR, gedconstants::GED_CORP);
    } // getSourceCorporation
    void header::setSourceCorporation(const string &corporation)
    {
        setChildValue(gedconstants::GED_SOUR, gedconstants::GED_CORP, corporation);
    }
    const addressstructure *header::findCorporationAddress() const
    {
        const node *pSource0 = findChild(gedconstants::GED_SOUR);
        const multinode *pSource = dynamic_cast<const multinode *>(pSource0);
        if (pSource != nullptr)
        {
            const node *pSourCorp0 = pSource->findChild(gedconstants::GED_CORP);
            const multinode *pSourCorp = dynamic_cast<const multinode *>(pSourCorp0);
            if (pSourCorp != nullptr)
            {
                const addressstructure *pAddr = pSourCorp->findChildNodeByTag<addressstructure>(gedconstants::GED_ADDR);
                if (pAddr != nullptr)
                {
                    return pAddr;
                }
            }
        }
        return nullptr;
    } // getCorporationAddress
    addressstructure *header::getCorporationAddress()
    {
        node *pSource0 = getChild(gedconstants::GED_SOUR);
        assert(pSource0 != nullptr);
        multinode *pSource = dynamic_cast<multinode *>(pSource0);
        assert(pSource != nullptr);
        node *pSourCorp0 = pSource->getChild(gedconstants::GED_CORP);
        assert(pSourCorp0 != nullptr);
        multinode *pSourCorp = dynamic_cast<multinode *>(pSourCorp0);
        assert(pSourCorp != nullptr);
        addressstructure *pAddr = pSourCorp->getChildNodeByTag<addressstructure>(gedconstants::GED_ADDR);
        return pAddr;
    } // setCorporationAddress
    string header::getSourceDataName(void) const
    {
        return getChildValue(gedconstants::GED_SOUR, gedconstants::GED_DATA);
    } // getSourceData
    void header::setSourceDataName(const string &sourceData)
    {
        setChildValue(gedconstants::GED_SOUR, gedconstants::GED_DATA, sourceData);
    } // setSourceData
    string header::getSourcePublicationDate(void) const
    {
        return getChildValue(gedconstants::GED_SOUR, gedconstants::GED_DATA, gedconstants::GED_DATE);
    } // getSourcePublicationDate
    void header::setSourcePublicationDate(const string &publicationDate)
    {
        setChildValue(gedconstants::GED_SOUR, gedconstants::GED_DATA,
                       gedconstants::GED_DATE, publicationDate);
    } // setSourcePublicationDate
    string header::getSourceCopyright() const
    {
        return getChildValue(gedconstants::GED_SOUR, gedconstants::GED_DATA, gedconstants::GED_COPR);
    } // getSourceCopyright
    void header::setSourceCopyright(const string &copyright)
    {
        setChildValue(gedconstants::GED_SOUR, gedconstants::GED_DATA,
                       gedconstants::GED_COPR, copyright);
    }
    string header::getReceivingSystemName(void) const
    {
        return getChildValue(gedconstants::GED_DEST);
    } // getDestName
    void header::setReceivingSystemName(const string &destName)
    {
        setChildValue(gedconstants::GED_DEST, destName);
    } // setDestName
    string header::getTransmissionDate(void) const
    {
        return getChildValue(gedconstants::GED_DATE);
    }
    void header::setTransmissionDate(const string &sval)
    {
        setChildValue(gedconstants::GED_DATE, sval);
    } // setTransmissionDate
    string header::getTransmissionTime(void) const
    {
        return getChildValue(gedconstants::GED_DATE, gedconstants::GED_TIME);
    }
    void header::setTransmissionTime(const string &sval)
    {
        setChildValue(gedconstants::GED_DATE, gedconstants::GED_TIME, sval);
    } // setTransmissionTime
    string header::getSubmitterReference(void) const
    {
        return getChildValue(gedconstants::GED_SUBM);
    }
    void header::setSubmitterReference(const string &submitter)
    {
        setChildValue(gedconstants::GED_SUBM, submitter);
    } // setSubmitter
    string header::getSubmissionReference(void) const
    {
        return getChildValue(gedconstants::GED_SUBN);
    }
    void header::setSubmissionReference(const string &subxref)
    {
        setChildValue(gedconstants::GED_SUBN, subxref);
    } // setSubXRef
    string header::getFileName(void) const
    {
        return getChildValue(gedconstants::GED_FILE);
    }
    void header::setFileName(const string &filename)
    {
        setChildValue(gedconstants::GED_FILE, filename);
    } // setFileName
    string header::getGedcomFileCopyright(void) const
    {
        return getChildValue(gedconstants::GED_COPR);
    }
    void header::setGedcomFileCopyright(const string &copyright)
    {
        setChildValue(gedconstants::GED_COPR, copyright);
    } // setGedcomFileCopyright
    string header::getGedcomVersion(void) const
    {
        return getChildValue(gedconstants::GED_GEDC, gedconstants::GED_VERS);
    } // getGedcomVersion
    void header::setGedcomVersion(const string &version)
    {
        setChildValue(gedconstants::GED_GEDC, gedconstants::GED_VERS, version);
    } // setGedcomVersion
    string header::getGedcomFormat(void) const
    {
        return getChildValue(gedconstants::GED_GEDC, gedconstants::GED_FORM);
    }
    void header::setGedcomFormat(const string &format)
    {
        setChildValue(gedconstants::GED_GEDC, gedconstants::GED_FORM, format);
    } // setGedcomFormat
    string header::getCharacterSet(void) const
    {
        return getChildValue(gedconstants::GED_CHAR);
    } // getCharacterSet
    void header::setCharacterSet(const string &cset)
    {
        setChildValue(gedconstants::GED_CHAR, cset);
    } // setCharacterSet
    string header::getCharacterSetVersion(void) const
    {
        return getChildValue(gedconstants::GED_CHAR, gedconstants::GED_VERS);
    }
    void header::setCharacterSetVersion(const string &version)
    {
        setChildValue(gedconstants::GED_CHAR, gedconstants::GED_VERS, version);
    } // setCharacterSet
    string header::getLanguage(void) const
    {
        return getChildValue(gedconstants::GED_LANG);
    } // getLanguage
    void header::setLanguage(const string &language)
    {
        setChildValue(gedconstants::GED_LANG, language);
    } // setLanguage
    string header::getPlaceHierarchy(void) const
    {
        return getChildValue(gedconstants::GED_PLAC, gedconstants::GED_FORM);
    } // getPlaceHierarchy
    void header::setPlaceHierarchy(const string &placeHierarchy)
    {
        setChildValue(gedconstants::GED_PLAC, gedconstants::GED_FORM, placeHierarchy);
    } // setPlaceHierarchy
    const notestructure *header::findNote(void) const
    {
        return findChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    notestructure *header::getNote()
    {
        return getChildNodeByTag<notestructure>(gedconstants::GED_NOTE);
    }
    ///////////////////////////////////
    nodetype header::getType(void) const
    {
        return nodetype::Header;
    }
    bool header::isValid(void) const
    {
        if (!guardnode::isValid())
        {
            return false;
        }
        if (getTag() != gedconstants::GED_HEAD || getLevel() != 0)
        {
            return false;
        }
        const string source = getSourceApprovedId();
        if (source.empty())
        {
            return false;
        }
        const string dest = getReceivingSystemName();
        if (dest.empty())
        {
            return false;
        }
        const string submitter = getSubmitterReference();
        if (submitter.empty())
        {
            return false;
        }
        const string version = getGedcomVersion();
        if (version.empty())
        {
            return false;
        }
        const string format = getGedcomFormat();
        if (format.empty())
        {
            return false;
        }
        const string charset = getCharacterSet();
        if (charset.empty())
        {
            return false;
        }
        return true;
    } // isValid

    /////////////////////////////////
} // namespace infoged
