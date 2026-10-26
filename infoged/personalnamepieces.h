#pragma once
#ifndef NAMEPIECES_H__
#define NAMEPIECES_H__
//////////////////////////
#include "proxynode.h"
///////////////////////
namespace infoged
{
    class sourcecitation;
    class notestructure;
    class personalnamepieces : public proxynode
    {
    public:
        personalnamepieces(multinode *proxy = nullptr);
        personalnamepieces(const personalnamepieces &other);
        personalnamepieces &operator=(const personalnamepieces &other);
        virtual ~personalnamepieces();

    public:
        string getNamePrefix(void) const;
        void setNamePrefix(const string &name);
        string getNameGiven(void) const;
        void setNameGiven(const string &given);
        string getNameNickname(void) const;
        void setNameNickname(const string &nickname);
        string getNameSurname(void) const;
        void setNameSurname(const string &surname);
        string getNameSuffix(void) const;
        void setNameSuffix(const string &suffix);
        const notestructure *findNote(void) const;
        notestructure *getNote();
        const sourcecitation *findSourceCitation(void) const;
        sourcecitation *getSourceCitation();
        //
    };
} // namespace infoged
#endif // NAMEPIECES_H__
