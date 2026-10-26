#pragma once
#ifndef ENTITIESUTILS_H__
#define ENTITIESUTILS_H__
//////////////////////////
#include "mydefs.h"
/////////////////////////
namespace infoged
{
    class entitiesutils
    {
    public:
        static const stringmap &getEntityNamesMap(void);
        //
        static const char_type AROBAS;
        static const string SPACE;
        //
        static const string GED_INC;
        static const string GED_QUESTION;
        static const string GED_Y;
        static const string GED_ANY;
        static const string GED_ONE_SLASH;
        static const string GED_DOUBLE_SLASH;
        //
        static const string GED_PREFIX_INDIVIDUAL;
        static const string GED_PREFIX_FAMILY;
        static const string GED_PREFIX_MULTIMEDIA;
        static const string GED_PREFIX_NOTE;
        static const string GED_PREFIX_SOURCE;
        static const string GED_PREFIX_SUBMITTER;
        static const string GED_PREFIX_SUBMISSION;
        static const string GED_PREFIX_REPOSITORY;
        static const string GED_PREFIX_DEFAULT;
        //
        static const string GED_TEXT_INDIVIDUALS;
        static const string GED_TEXT_FAMILIES;
        static const string GED_TEXT_MULTIMEDIAS;
        static const string GED_TEXT_NOTES;
        static const string GED_TEXT_SOURCEs;
        static const string GED_TEXT_SUBMITTERS;
        static const string GED_TEXT_SUBMISSIONS;
        static const string GED_PREFIX_REPOSITORIES;
        //
    }; // class entitiesutils
} // namespace infoged
///////////////////////
#endif // ENTITIESUTILS_H__