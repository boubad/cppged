#include "nodeutils.h"
////////////////////
#include "gedconstants.h"
#include "stringutils.h"
/////////////////////
#include <mutex>
#include <atomic>
/////////////////////
namespace infoged
{
    static const stringset NOCHILDREN_TAGS({gedconstants::GED_ADR1,
                                            gedconstants::GED_ADR2,
                                            gedconstants::GED_ADR3,
                                            gedconstants::GED_AFN,
                                            gedconstants::GED_AGE,
                                            gedconstants::GED_AGNC,
                                            gedconstants::GED_ALIA,
                                            gedconstants::GED_ANCE,
                                            gedconstants::GED_ANCI,
                                            gedconstants::GED_CAUS,
                                            gedconstants::GED_CHIL,
                                            gedconstants::GED_CITY,
                                            gedconstants::GED_CONC,
                                            gedconstants::GED_CONT,
                                            gedconstants::GED_CTRY,
                                            gedconstants::GED_DESC,
                                            gedconstants::GED_DESI,
                                            gedconstants::GED_DEST,
                                            gedconstants::GED_EMAIL,
                                            gedconstants::GED_FAMF,
                                            gedconstants::GED_FAX,
                                            gedconstants::GED_GIVN,
                                            gedconstants::GED_LANG,
                                            gedconstants::GED_LATI,
                                            gedconstants::GED_LONG,
                                            gedconstants::GED_MEDI,
                                            gedconstants::GED_NICK,
                                            gedconstants::GED_NPFX,
                                            gedconstants::GED_NSFX,
                                            gedconstants::GED_ORDI,
                                            gedconstants::GED_PEDI,
                                            gedconstants::GED_PHON,
                                            gedconstants::GED_POST,
                                            gedconstants::GED_QUAY,
                                            gedconstants::GED_RELA,
                                            gedconstants::GED_RESN,
                                            gedconstants::GED_RFN,
                                            gedconstants::GED_RIN,
                                            gedconstants::GED_ROLE,
                                            gedconstants::GED_SFXA,
                                            gedconstants::GED_SFXX,
                                            gedconstants::GED_SEX,
                                            gedconstants::GED_SPFX,
                                            gedconstants::GED_STAE,
                                            gedconstants::GED_SUBM,
                                            gedconstants::GED_SUBN,
                                            gedconstants::GED_SURN,
                                            gedconstants::GED_TEMP,
                                            gedconstants::GED_TIME,
                                            gedconstants::GED_TYPE,
                                            gedconstants::GED_TYPE,
                                            gedconstants::GED_VERS,
                                            gedconstants::GED_WWWW,
                                            gedconstants::GED_WTUSER,
                                            gedconstants::GED_WTPRIM,
                                            gedconstants::GED_WTUID,
                                            gedconstants::GED_WTMARNM});
    /////////////////////////////
    static std::map<string, stringset> CHILDREN_TAGS_MAP;
    static std::mutex NODE_CREATORS_MUTEX;
    static std::atomic<bool> NODE_CREATORS_INITIALIZED(false);
    //////////////////////////////
    static void initializeChildrenTagsMap(void)
    {
        if (!CHILDREN_TAGS_MAP.empty())
        {
            return;
        }
        CHILDREN_TAGS_MAP[gedconstants::GED_FILE] = stringset({
            gedconstants::GED_FORM,
            gedconstants::GED_TITL,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_FORM] = stringset({
            gedconstants::GED_TYPE,
            gedconstants::GED_MEDI,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_REFN] = stringset({
            gedconstants::GED_TYPE,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_CHAR] = stringset({
            gedconstants::GED_VERS,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_GEDC] = stringset({
            gedconstants::GED_VERS,
            gedconstants::GED_FORM,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_DATE] = stringset({
            gedconstants::GED_TIME,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_COPR] = stringset({
            gedconstants::GED_CONT,
            gedconstants::GED_CONC,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_CORP] = stringset({
            gedconstants::GED_ADDR,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_DATA] = stringset({
            gedconstants::GED_DATE,
            gedconstants::GED_COPR,
            gedconstants::GED_EVEN,
            gedconstants::GED_AGNC,
            gedconstants::GED_NOTE,
            gedconstants::GED_TEXT,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_HEAD] = stringset(
            {gedconstants::GED_SOUR, gedconstants::GED_DEST, gedconstants::GED_DATE,
             gedconstants::GED_SUBM, gedconstants::GED_SUBN, gedconstants::GED_FILE,
             gedconstants::GED_COPR, gedconstants::GED_GEDC, gedconstants::GED_CHAR,
             gedconstants::GED_LANG, gedconstants::GED_PLAC, gedconstants::GED_NOTE,
             gedconstants::GED_PHON, gedconstants::GED_EMAIL, gedconstants::GED_FAX,
             gedconstants::GED_WWWW});
        CHILDREN_TAGS_MAP[gedconstants::GED_SOUR] = stringset(
            {gedconstants::GED_ABBR, gedconstants::GED_AUTH, gedconstants::GED_CHAN,
             gedconstants::GED_CORP, gedconstants::GED_DATA, gedconstants::GED_EMAIL,
             gedconstants::GED_EVEN, gedconstants::GED_FAX, gedconstants::GED_NAME,
             gedconstants::GED_NOTE, gedconstants::GED_OBJE, gedconstants::GED_PAGE,
             gedconstants::GED_PHON, gedconstants::GED_PUBL, gedconstants::GED_QUAY,
             gedconstants::GED_REFN, gedconstants::GED_REPO, gedconstants::GED_RIN,
             gedconstants::GED_TEXT, gedconstants::GED_TITL, gedconstants::GED_VERS,
             gedconstants::GED_WWWW

            });
        CHILDREN_TAGS_MAP[gedconstants::GED_ADDR] = stringset(
            {gedconstants::GED_ADR1, gedconstants::GED_ADR2, gedconstants::GED_ADR3,
             gedconstants::GED_CITY, gedconstants::GED_CONT, gedconstants::GED_CONC,
             gedconstants::GED_STAE, gedconstants::GED_POST, gedconstants::GED_CTRY});
        CHILDREN_TAGS_MAP[gedconstants::GED_ASSO] = stringset(
            {gedconstants::GED_RELA, gedconstants::GED_SOUR, gedconstants::GED_NOTE});
        CHILDREN_TAGS_MAP[gedconstants::GED_CHAN] =
            stringset({gedconstants::GED_DATE, gedconstants::GED_TIME,
                       gedconstants::GED_NOTE, gedconstants::GED_WTUSER});
        CHILDREN_TAGS_MAP[gedconstants::GED_FAMC] = stringset({
            gedconstants::GED_PEDI,
            gedconstants::GED_ADOP,
            gedconstants::GED_STAT,
            gedconstants::GED_NOTE,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_FAM] = stringset(
            {gedconstants::GED_ADDR, gedconstants::GED_AGNC, gedconstants::GED_ANUL,
             gedconstants::GED_CAUS, gedconstants::GED_CENS, gedconstants::GED_CHAN,
             gedconstants::GED_CHIL, gedconstants::GED_DATE, gedconstants::GED_DIV,
             gedconstants::GED_DIVF, gedconstants::GED_ENGA, gedconstants::GED_EVEN,
             gedconstants::GED_HUSB, gedconstants::GED_MARB, gedconstants::GED_MARC,
             gedconstants::GED_MARL, gedconstants::GED_MARR, gedconstants::GED_MARS,
             gedconstants::GED_NCHI, gedconstants::GED_NOTE, gedconstants::GED_OBJE,
             gedconstants::GED_PLAC, gedconstants::GED_REFN, gedconstants::GED_RELI,
             gedconstants::GED_RESI, gedconstants::GED_RESN, gedconstants::GED_RIN,
             gedconstants::GED_SLGC, gedconstants::GED_SOUR, gedconstants::GED_SUBM,
             gedconstants::GED_TYPE, gedconstants::GED_WIFE});
        CHILDREN_TAGS_MAP[gedconstants::GED_INDI] = stringset(
            {gedconstants::GED_ADOP, gedconstants::GED_AFN, gedconstants::GED_ALIA,
             gedconstants::GED_ANCI, gedconstants::GED_ASSO, gedconstants::GED_BAPL,
             gedconstants::GED_BAPM, gedconstants::GED_BARM, gedconstants::GED_BASM,
             gedconstants::GED_BIRT, gedconstants::GED_BLES, gedconstants::GED_BURI,
             gedconstants::GED_CAST, gedconstants::GED_CENS, gedconstants::GED_CHAN,
             gedconstants::GED_CHR, gedconstants::GED_CHRA, gedconstants::GED_CONF,
             gedconstants::GED_CONL, gedconstants::GED_CREM, gedconstants::GED_DEAT,
             gedconstants::GED_DESI, gedconstants::GED_DSCR, gedconstants::GED_EDUC,
             gedconstants::GED_ENDL, gedconstants::GED_EMIG, gedconstants::GED_EVEN,
             gedconstants::GED_FACT, gedconstants::GED_FAMC, gedconstants::GED_FAMS,
             gedconstants::GED_FCOM, gedconstants::GED_GRAD, gedconstants::GED_IDNO,
             gedconstants::GED_IMMI, gedconstants::GED_NAME, gedconstants::GED_NATI,
             gedconstants::GED_NATU, gedconstants::GED_NCHI, gedconstants::GED_NMR,
             gedconstants::GED_NOTE, gedconstants::GED_OBJE, gedconstants::GED_OCCU,
             gedconstants::GED_ORDN, gedconstants::GED_PROB, gedconstants::GED_PROP,
             gedconstants::GED_REFN, gedconstants::GED_RELA, gedconstants::GED_RELI,
             gedconstants::GED_REPO, gedconstants::GED_RESI, gedconstants::GED_RESN,
             gedconstants::GED_RETI, gedconstants::GED_RFN, gedconstants::GED_RIN,
             gedconstants::GED_SEX, gedconstants::GED_SLGC, gedconstants::GED_SSN,
             gedconstants::GED_SUBM, gedconstants::GED_TITL, gedconstants::GED_WILL});
        CHILDREN_TAGS_MAP[gedconstants::GED_SLGC] = stringset(
            {gedconstants::GED_DATE, gedconstants::GED_TEMP, gedconstants::GED_PLAC,
             gedconstants::GED_STAT, gedconstants::GED_SOUR, gedconstants::GED_NOTE});
        CHILDREN_TAGS_MAP[gedconstants::GED_OBJE] = stringset(
            {gedconstants::GED_FILE, gedconstants::GED_CHAN, gedconstants::GED_NOTE,
             gedconstants::GED_REFN, gedconstants::GED_RIN, gedconstants::GED_SOUR,
             gedconstants::GED_TITL, gedconstants::GED_WTUID});
        CHILDREN_TAGS_MAP[gedconstants::GED_NOTE] = stringset({
            gedconstants::GED_CONT,
            gedconstants::GED_CONC,
            gedconstants::GED_REFN,
            gedconstants::GED_RIN,
            gedconstants::GED_SOUR,
            gedconstants::GED_CHAN,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_NAME] = stringset({
            gedconstants::GED_TYPE,
            gedconstants::GED_FONE,
            gedconstants::GED_ROMN,
            gedconstants::GED_NPFX,
            gedconstants::GED_GIVN,
            gedconstants::GED_NICK,
            gedconstants::GED_SURN,
            gedconstants::GED_SPFX,
            gedconstants::GED_NSFX,
            gedconstants::GED_SOUR,
            gedconstants::GED_NOTE,
            gedconstants::GED_WTMARNM,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_FONE] = stringset({
            gedconstants::GED_TYPE,
            gedconstants::GED_FONE,
            gedconstants::GED_ROMN,
            gedconstants::GED_NPFX,
            gedconstants::GED_GIVN,
            gedconstants::GED_NICK,
            gedconstants::GED_SURN,
            gedconstants::GED_SPFX,
            gedconstants::GED_NSFX,
            gedconstants::GED_SOUR,
            gedconstants::GED_NOTE,
            gedconstants::GED_WTMARNM,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_ROMN] = stringset({
            gedconstants::GED_TYPE,
            gedconstants::GED_FONE,
            gedconstants::GED_ROMN,
            gedconstants::GED_NPFX,
            gedconstants::GED_GIVN,
            gedconstants::GED_NICK,
            gedconstants::GED_SURN,
            gedconstants::GED_SPFX,
            gedconstants::GED_NSFX,
            gedconstants::GED_SOUR,
            gedconstants::GED_NOTE,
            gedconstants::GED_WTMARNM,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_PLAC] = stringset({
            gedconstants::GED_CONT,
            gedconstants::GED_CONC,
            gedconstants::GED_FORM,
            gedconstants::GED_MAP,
            gedconstants::GED_FONE,
            gedconstants::GED_ROMN,
            gedconstants::GED_NOTE,
        });
        CHILDREN_TAGS_MAP[gedconstants::GED_REPO] = stringset(
            {gedconstants::GED_ADDR, gedconstants::GED_CALN, gedconstants::GED_CHAN,
             gedconstants::GED_EMAIL, gedconstants::GED_FAX, gedconstants::GED_NAME,
             gedconstants::GED_NOTE, gedconstants::GED_PHON, gedconstants::GED_REFN,
             gedconstants::GED_RIN, gedconstants::GED_WWWW});

        CHILDREN_TAGS_MAP[gedconstants::GED_FAMS] =
            stringset({gedconstants::GED_NOTE});

        CHILDREN_TAGS_MAP[gedconstants::GED_SUBN] = stringset(
            {gedconstants::GED_SUBM, gedconstants::GED_FAMF, gedconstants::GED_TEMP,
             gedconstants::GED_ANCE, gedconstants::GED_DESC, gedconstants::GED_ORDI,
             gedconstants::GED_NOTE, gedconstants::GED_RIN, gedconstants::GED_CHAN});
        CHILDREN_TAGS_MAP[gedconstants::GED_SUBM] = stringset(
            {gedconstants::GED_NAME, gedconstants::GED_ADDR, gedconstants::GED_OBJE,
             gedconstants::GED_LANG, gedconstants::GED_RFN, gedconstants::GED_RIN,
             gedconstants::GED_NOTE, gedconstants::GED_CHAN, gedconstants::GED_PHON,
             gedconstants::GED_EMAIL, gedconstants::GED_FAX, gedconstants::GED_WWWW});
        CHILDREN_TAGS_MAP[gedconstants::GED_CHAN] =
            stringset({gedconstants::GED_DATE});

    } // initializeChildrenTagsMap
    /////////////////////////////////
    static void initAll(void)
    {
        if (!NODE_CREATORS_INITIALIZED.load())
        {
            std::lock_guard<std::mutex> lock(NODE_CREATORS_MUTEX);
            initializeChildrenTagsMap();
            NODE_CREATORS_INITIALIZED.store(true);
        }
    } // initAll
    ///////////////////////////////
    bool nodeutils::canHaveChild(const string &parentTag, const string &childTag)
    {
        initAll();
        string ptag = stringutils::uppercase(stringutils::trim(parentTag));
        string ctag = stringutils::uppercase(stringutils::trim(childTag));
        auto it = CHILDREN_TAGS_MAP.find(ptag);
        if (it == CHILDREN_TAGS_MAP.end())
        {
            return true;
        }
        const auto &children = it->second;
        if (children.empty())
        {
            return true;
        }
        if (children.find(ctag) == children.end())
        {
            return false;
        }
        return true;
    }
    bool nodeutils::isTagHasNoChidren(const string &tag)
    {
        string stag = stringutils::uppercase(stringutils::trim(tag));
        return NOCHILDREN_TAGS.find(stag) != NOCHILDREN_TAGS.end();
    }
    //////////////////////////////////
} // namespace infoged