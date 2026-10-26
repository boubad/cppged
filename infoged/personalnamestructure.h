#pragma once
#ifndef PERSONALNAMEPIECES_H__
#define PERSONALNAMEPIECES_H__
///////////////////////
#include "multinode.h"
/////////////////////////
namespace infoged
{
    class personalnamepieces;
    class personalnamestructure : public multinode
    {
    public:
        personalnamestructure(int level = -1, const string &name = string());
        personalnamestructure(const personalnamestructure &other);
        personalnamestructure &operator=(const personalnamestructure &other);
        virtual ~personalnamestructure();

    public:
        string getName(void) const;
        void setName(const string &name);
        string getNameType(void) const;
        void setNameType(const string &nameType);
        void getNamePieces(personalnamepieces &namePieces);
        //
        string getNamePhoneticVariation(void) const;
        void setNamePhoneticVariation(const string &namePhoneticVariation);
        string getPhoneticType(void) const;
        void setPhoneticType(const string &phoneticType);
        bool getPhoneticNamePieces(personalnamepieces &namePieces);
        //
        string getRomanizedVariation(void) const;
        void setRomanizedVariation(const string &romanizedVariation);
        string getRomanizedType(void) const;
        void setRomanizedType(const string &romanizedType);
        bool getRomanizedNamePieces(personalnamepieces &namePiece);

    public:
        virtual bool isValid(void) const override;
        virtual nodetype getType(void) const override;
    };
} // namespace infoged

#endif // PERSONALNAMEPIECES_H__
