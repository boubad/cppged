#pragma once
#ifndef ADDRESNODES_H__
#define ADDRESSNODE_H__
//////////////////////
#include "multinode.h"
//////////////////////
namespace infoged
{
    class addressstructure : public multinode
    {
    public:
        addressstructure(int level = -1, const string &addrline = string());
        addressstructure(const addressstructure &other);
        addressstructure &operator=(const addressstructure &other);
        virtual ~addressstructure();

    public:
        string getAddrLine(void) const;
        void setAddrLine(const string &addrline);
        string getAddr1(void) const;
        void setAddr1(const string &addr1);
        string getAddr2(void) const;
        void setAddr2(const string &addr2);
        string getAddr3(void) const;
        void setAddr3(const string &addr3);
        string getCity(void) const;
        void setCity(const string &city);
        string getState(void) const;
        void setState(const string &state);
        string getPost(void) const;
        void setPost(const string &post);
        string getCountry(void) const;
        void setCountry(const string &country);
        //
        string getPhone(void) const;
        void setPhone(const string &phone);
        string getFax(void) const;
        void setFax(const string &fax);
        string getEmail(void) const;
        void setEmail(const string &email);
        string getWebsite(void) const;
        void setWebsite(const string &website);
        //
    public:
        virtual void check(void) override;
        virtual bool isValid(void) const override;
        virtual nodetype getType(void) const override;
    }; // class Address
} // namespace infoged
//////////////////////////////
#endif // ADDRESSNODE_H__
