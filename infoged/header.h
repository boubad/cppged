#pragma once
#ifndef HEADX_H__
#define HEADX_H__
//////////////
#include "guardnode.h"

///////////////////////////
namespace infoged
{
    class addressstructure;
    class notestructure;
    class header : public guardnode
    {
    public:
        header();
        header(const header &other);
        header &operator=(const header &other);
        virtual ~header();

    public:
        string getSourceApprovedId(void) const;
        void setSourceApprovedId(const string &source);
        string getSourceVersion(void) const;
        void setSourceVersion(const string &version);
        string getSourceName(void) const;
        void setSourceName(const string &name);
        string getSourceCorporation(void) const;
        void setSourceCorporation(const string &corporation);
        const addressstructure *findCorporationAddress() const;
        addressstructure *getCorporationAddress();
        string getSourceDataName(void) const;
        void setSourceDataName(const string &sourceData);
        string getSourcePublicationDate(void) const;
        void setSourcePublicationDate(const string &publicationDate);
        string getSourceCopyright() const;
        void setSourceCopyright(const string &copyright);
        string getReceivingSystemName(void) const;
        void setReceivingSystemName(const string &destName);
        string getTransmissionDate(void) const;
        void setTransmissionDate(const string &transmissionDate);
        string getTransmissionTime(void) const;
        void setTransmissionTime(const string &transmissionTime);
        string getSubmitterReference(void) const;
        void setSubmitterReference(const string &submitter);
        string getSubmissionReference(void) const;
        void setSubmissionReference(const string &subXRef);
        string getFileName(void) const;
        void setFileName(const string &fileName);
        string getGedcomFileCopyright(void) const;
        void setGedcomFileCopyright(const string &gedcomFileCopyright);
        string getGedcomVersion(void) const;
        void setGedcomVersion(const string &gedcomVersion);
        string getGedcomFormat(void) const;
        void setGedcomFormat(const string &gedcomFormat);
        string getCharacterSet(void) const;
        void setCharacterSet(const string &characterSet);
        string getCharacterSetVersion(void) const;
        void setCharacterSetVersion(const string &characterSetVersion);
        string getLanguage(void) const;
        void setLanguage(const string &language);
        string getPlaceHierarchy(void) const;
        void setPlaceHierarchy(const string &placeHierarchy);
        //
        const notestructure *findNote(void) const;
        notestructure *getNote();
        //
    public:
        virtual bool isValid(void) const override;
        virtual nodetype getType(void) const override;
    }; // class Head
} // namespace infoged
#endif // !HEAD_H__