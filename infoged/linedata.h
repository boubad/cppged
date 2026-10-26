#pragma once
#ifndef LINEDATA_H
#define LINEDATA_H
/////////////////////////
#include "basedata.h"
/////////////////////////
namespace infoged
{
    class multinode;
    ////////////////////////////
    class linedata : public basedata
    {
    public:
        linedata(int level = -1, const string &tag = string(), const string &value = string(), const string &id = string());
        linedata(const linedata &other);
        linedata &operator=(const linedata &other);
        virtual ~linedata();

    public:
        const string &getId(void) const;
        void setId(const string &id);
        const string &getValue(void) const;
        void setValue(const string &value);
        public:
        //
        virtual ostream &write(ostream &os) const override;
        virtual void clear(void) override;
        virtual status getStatusValue(void) const override;

    private:
        string m_id;
        string m_value;
    }; // class linedata
    ///////////////////////
} // namespace infoged
////////////////////////////
#endif // LINEDATA_H