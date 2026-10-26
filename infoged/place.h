#pragma once
#ifndef PLACENODE_H__
#define PLACENODE_H__
///////////////////////////
#include "multinode.h"
///////////////////////////////
namespace infoged
{
    class notestructure;
    class place : public multinode
    {
    public:
        place(int level = -1, const string &placeName = string());
        place(const place &other);
        place &operator=(const place &other);
        virtual ~place();

    public:
        string getName(void) const;
        void setName(const string &placeName);
        string getHierachy(void) const;
        void setHierachy(const string &placeHierachy);
        //
        string getPhoneticVariation(void) const;
        void setPhoneticVariation(const string &phoneticVariation);
        string getPhoneticVariationType(void) const;
        void setPhoneticVariationType(const string &phoneticVariationType);
        string getRomanizedVariation(void) const;
        void setRomanizedVariation(const string &romanizedVariation);
        string getRomanizedVariationType(void) const;
        void setRomanizedVariationType(const string &romanizedVariationType);
        //
        string getLatitude(void) const;
        void setLatitude(const string &placeLatitude);
        string getLongitude(void) const;
        void setLongitude(const string &placeLongitude);
        const notestructure *findNote(void) const;
        notestructure *getNote(void);

    public:
        virtual void check(void) override;
        virtual bool isValid(void) const override;
        virtual nodetype getType(void) const override;
    };
} // namespace infoged
#endif // PLACENODE_H__