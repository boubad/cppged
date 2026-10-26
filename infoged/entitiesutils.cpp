#include "entitiesutils.h"
#include "gedconstants.h"
//////////////////////////////
namespace infoged
{
    const char_type entitiesutils::AROBAS('@');
    const string entitiesutils::SPACE(" ");
    //
    const string entitiesutils::GED_INC("(INC)");
    const string entitiesutils::GED_QUESTION("?");
    const string entitiesutils::GED_Y("Y");
    const string entitiesutils::GED_ANY("ANY");
    const string entitiesutils::GED_ONE_SLASH("/");
    const string entitiesutils::GED_DOUBLE_SLASH("//");
    //
    const string entitiesutils::GED_PREFIX_INDIVIDUAL("I");
    const string entitiesutils::GED_PREFIX_FAMILY("F");
    const string entitiesutils::GED_PREFIX_MULTIMEDIA("M");
    const string entitiesutils::GED_PREFIX_NOTE("T");
    const string entitiesutils::GED_PREFIX_SOURCE("S");
    const string entitiesutils::GED_PREFIX_SUBMITTER("U");
    const string entitiesutils::GED_PREFIX_SUBMISSION("V");
    const string entitiesutils::GED_PREFIX_REPOSITORY("R");
    const string entitiesutils::GED_PREFIX_DEFAULT("X");
    //
    const string entitiesutils::GED_TEXT_INDIVIDUALS("INDIVIDUALS: ");
    const string entitiesutils::GED_TEXT_FAMILIES("FAMILIES: ");
    const string entitiesutils::GED_TEXT_MULTIMEDIAS("MULTIMEDIAS: ");
    const string entitiesutils::GED_TEXT_NOTES("NOTES: ");
    const string entitiesutils::GED_TEXT_SOURCEs("SOURCES: ");
    const string entitiesutils::GED_TEXT_SUBMITTERS("SUBMITTERS: ");
    const string entitiesutils::GED_TEXT_SUBMISSIONS("SUBMISSIONS: ");
    const string entitiesutils::GED_PREFIX_REPOSITORIES("REPOSITORIES: ");
    //
    ////////////////////////////////
    const stringmap &entitiesutils::getEntityNamesMap(void)
    {
        static stringmap _entityNamesMap;
        if (_entityNamesMap.empty())
        {
            _entityNamesMap[entitiesutils::GED_PREFIX_INDIVIDUAL] =
                entitiesutils::GED_TEXT_INDIVIDUALS;
            _entityNamesMap[entitiesutils::GED_PREFIX_FAMILY] =
                entitiesutils::GED_TEXT_FAMILIES;
            _entityNamesMap[entitiesutils::GED_PREFIX_MULTIMEDIA] =
                entitiesutils::GED_TEXT_MULTIMEDIAS;
            _entityNamesMap[entitiesutils::GED_PREFIX_NOTE] =
                entitiesutils::GED_TEXT_NOTES;
            _entityNamesMap[entitiesutils::GED_PREFIX_SOURCE] =
                entitiesutils::GED_TEXT_SOURCEs;
            _entityNamesMap[entitiesutils::GED_PREFIX_SUBMITTER] =
                entitiesutils::GED_TEXT_SUBMITTERS;
            _entityNamesMap[entitiesutils::GED_PREFIX_SUBMISSION] =
                entitiesutils::GED_TEXT_SUBMISSIONS;
            _entityNamesMap[entitiesutils::GED_PREFIX_REPOSITORY] =
                entitiesutils::GED_PREFIX_REPOSITORIES;
        }
        return _entityNamesMap;
    } // getEntityNamesMap
} // namespace infoged
///////////////////////////////////