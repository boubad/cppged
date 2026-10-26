#pragma once
#ifndef MULTIMEDIAENTITYNODE_H__
#define MULTIMEDIAENTITYNODE_H__
///////////////////////////////
#include "entitynode.h"
//////////////////////////////////////
namespace infoged
{
    class notestructure;
    class sourcecitation;
    class changedate;
    class multimediarecord : public entitynode
    {
    public:
        multimediarecord(const string &id = string());
        multimediarecord(const multimediarecord &rec);
        multimediarecord &operator=(const multimediarecord &rec);
        virtual ~multimediarecord();

    public:
        string getMediaFileName(void) const;
        void setMediaFileName(const string &mediaFileName);
        string getFormat(void) const;
        void setFormat(const string &format);
        string getMediaType(void) const;
        void setMediaType(const string &mediaType);
        string getMediaDescriptiveTitle(void) const;
        void setMediaDescriptiveTitle(const string &mediaDescriptiveTitle);
        //

        string getUserReferenceNumber(void) const;
        void setUserReferenceNumber(const string &userReferenceNumber);
        string getUserReferenceType(void) const;
        void setUserReferenceType(const string &userReferenceType);
        string getAutomatedRecordId(void) const;
        void setAutomatedRecordId(const string &sAutomatedRecordId);
        const notestructure *findNote() const;
        notestructure *getNote();
        const sourcecitation *findSourceCitation(void) const;
        sourcecitation *getSourceCitation();
        const changedate *findChangedate(void) const;
        changedate *getChangedate();
        //
        void setMediaDir(const string &mediadir);
        bool existsFile(const string &mediadir = string()) const;

    public:
        virtual void check() override;
        virtual bool isValid() const override;
        virtual nodetype getType(void) const override;
    }; // class MultiMediaEntityNode
} // namespace infoged

#endif // MULTIMEDIAENTITYNODE_H__
