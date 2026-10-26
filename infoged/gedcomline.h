#pragma once
#ifndef GEDCOMLINE_H
#define GEDCOMLINE_H
///////////////////////
#include "datanode.h"
/////////////////
namespace infoged
{
    class gedcomline : public datanode
    {
    public:
        gedcomline(int level = -1, const string &tag = string(), const string &value = string(), const string &id = string());
        gedcomline(const gedcomline &other);
        gedcomline &operator=(const gedcomline &other);
        virtual ~gedcomline();
    public:
        virtual nodetype getType(void) const override;
    };
} // namespace infoged

#endif // GEDCOMLINE_H
