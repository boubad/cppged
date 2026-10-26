#pragma once
#ifndef sourcecitationNodeNODE_H__
#define sourcecitationNodeNODE_H__
//
#include "multinode.h"
//
namespace infoged
{
    class notestructure;
    class multimedialink;
    class sourcecitation : public multinode
    {
    public:
        sourcecitation(int level = -1, const string &xref = string());
        sourcecitation(const sourcecitation &src);
        sourcecitation &operator=(const sourcecitation &src);
        virtual ~sourcecitation();

    public:
        string getSourceRef(void) const;
        void setSourceRef(const string &text);
        string getWhereWithinSource(void) const;
        void setWhereWithinSource(const string &text);
        string getEventTypeCitedFrom(void) const;
        void setEventTypeCitedFrom(const string &evenTypeCitedFrom);
        string getRoleInEvent(void) const;
        void setRoleInEvent(const string &roleInEvent);
        string getRecordingDate(void) const;
        void setRecordingDate(const string &recordingDaye);
        string getTextFromSource(void) const;
        void setTextFromSource(const string &textFromSource);
        const multimedialink *findMultiMediaLink(void) const;
        multimedialink *getMultiMediaLink(void);
        const notestructure *findNote(void) const;
        notestructure *getNote(void);
        string getCertaintyAssessment(void) const;
        void setCertaintyAssessment(const string &certaintyAssessment);

    public:
        virtual void check(void) override;
        virtual bool isValid(void) const override;
        virtual nodetype getType(void) const override;
    }; // class sourcecitationNode
} // namespace infoged
#endif // sourcecitationNodeNODE_H__
