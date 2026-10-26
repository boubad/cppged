#pragma once
#ifndef BASEDATA_H
#define BASEDATA_H
/////////////////////////
#include "mydefs.h"
#include "status.h"
/////////////////////////
namespace infoged
{
    class multinode;
    ////////////////////////////
    class basedata
    {
    public:
        basedata(int level = -1, const string &tag = string());
        basedata(const basedata &other);
        basedata &operator=(const basedata &other);
        virtual ~basedata();

    public:
        multinode *getParent(void) const;
        void setParent(multinode *p);
        status getStatus(void) const;
        void setStatus(status st);
        int getLevel(void) const;
        void setLevel(int level);
        const string &getTag(void) const;
        void setTag(const string &tag);
        //
        bool isValid(void) const;
        void check(void);

    public:
        virtual ostream &write(ostream &os) const;
        virtual void clear(void);
        virtual status getStatusValue(void) const;

    private:
        multinode *m_parent;
        status m_status;
        int m_level;
        string m_tag;
    }; // class basedata
    ///////////////////////
} // namespace infoged
////////////////////////////
#endif // BASEDATA_H