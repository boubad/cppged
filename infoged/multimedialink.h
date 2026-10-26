#pragma once
#ifndef MULTIMEDIANODE_H__
#define MULTIMEDIANODE_H__
//////////////////////////
#include "multinode.h"
//////////////////////////////
namespace infoged
{
    class multimedialink : public multinode
    {
    public:
        multimedialink(int level = -1, const string &xref = string());
        multimedialink(const multimedialink &other);
        multimedialink &operator=(const multimedialink &other);
        virtual ~multimedialink();

    public:
        string getObjectReference(void) const;
        void setObjectReference(const string &xref);
        string getFileRef(void) const;
        void setFileRef(const string &fileref);
        string getFormat(void) const;
        void setFormat(const string &format);
        string getMediaType(void) const;
        void setMediaType(const string &mediatype);
        string getTitle(void) const;
        void setTitle(const string &title);

    public:
        virtual nodetype getType(void) const override;
        virtual bool isValid(void) const override;
        virtual void check(void) override;
    }; // class MultiMediaNode
} // namespace infoged
#endif // MULTIMEDIANODE_H__