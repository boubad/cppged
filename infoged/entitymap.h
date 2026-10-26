#pragma once
#ifndef ENTITYMAPX_H__
#define ENTITYMAPX_H__
/////////////////////////////
#include "entitynode.h"
#include "entitiesutils.h"
///////////////////////////
#include <iostream>
#include <iomanip>
#include <cassert>
/////////////////////////////////
namespace infoged
{
  class tree;
  ///////////////////////////////////
  template <typename T>
  class entitymap
  {
  private:
    size_t nmax_;
    string prefix_;
    std::map<std::string, T> map_;

  public:
    entitymap(const string &prefix = string()) : nmax_(0), prefix_(prefix)
    {
      static_assert(std::is_base_of<entitynode, T>::value,
                    "T must be derived from nentityode");
    }
    entitymap(const entitymap<T> &other)
        : nmax_(other.nmax_), prefix_(other.prefix_), map_(other.map_) {}
    entitymap<T> &operator=(const entitymap<T> &other)
    {
      if (this != &other)
      {
        nmax_ = other.nmax_;
        prefix_ = other.prefix_;
        map_ = other.map_;
      }
      return *this;
    }
    virtual ~entitymap() {}
    //
    const std::map<std::string, T> &getMap(void) const { return map_; }
    std::map<std::string, T> &getMap(void) { return map_; }

  public:
    void clear(void)
    {
      nmax_ = 0;
      map_.clear();
    }
    ostream &write(ostream &os) const
    {
      for (const auto &p : map_)
      {
        p.second.write(os);
        // os << std::endl;
      }
      return os;
    }

  public:
    void mutate(const std::function<void(node *)> &func)
    {
      for (auto &p : map_)
      {
        p.second.mutate(func);
      }
    }
    void visit(const std::function<void(const node *)> &func) const
    {
      for (const auto &p : map_)
      {
        p.second.visit(func);
      }
    }

    void remove(const std::function<bool(const node *)> &func)
    {
      for (auto &p : map_)
      {
        p.second.remove(func);
      }
    } // remove

    string getPrefix(void) const { return prefix_; }
    void setPrefix(const string &prefix) { prefix_ = prefix; }
    size_t size(void) const { return map_.size(); }
    bool empty(void) const { return map_.empty(); }
    ostream &getSummary(ostream &os) const
    {
      string sprefix;
      if (!prefix_.empty())
      {
        const stringmap &xmap = entitiesutils::getEntityNamesMap();
        auto it = xmap.find(prefix_);
        if (it != xmap.end())
        {
          sprefix = it->second;
        }
      }
      os << sprefix << entitiesutils::SPACE << map_.size() << std::endl;
      return os;
    }

    string add(const T &value, size_t minLength = 5)
    {
      assert(minLength > 0);
      T newValue(value);
      string id = value.getId();
      while (!id.empty() && map_.find(id) != map_.end())
      {
        id = nextId(minLength);
        newValue.setId(id);
      }
      map_[id] = newValue;
      return id;
    }

    bool update(const T &value)
    {
      string id = value.getId();
      auto it = map_.find(id);
      if (it != map_.end())
      {
        it->second = value;
        return true;
      }
      return false;
    }
    const T *find(const string &id) const
    {
      auto it = map_.find(id);
      if (it != map_.end())
      {
        return &it->second;
      }
      return nullptr;
    }
    T *find(const string &id)
    {
      auto it = map_.find(id);
      if (it != map_.end())
      {
        return &it->second;
      }
      return nullptr;
    }
    bool remove(const string &id)
    {
      auto it = map_.find(id);
      if (it != map_.end())
      {
        map_.erase(it);
        return true;
      }
      return false;
    } // remove
    void keys(stringset &keys) const
    {
      for (auto &p : map_)
      {
        keys.insert(p.first);
      }
    }

  public:
    string nextId(size_t minLength = 5)
    {
      assert(minLength > 0);
      if (prefix_.empty())
      {
        prefix_ = entitiesutils::GED_PREFIX_DEFAULT;
      }
      size_t n = nmax_;
      if (n < map_.size())
      {
        n = map_.size();
      }
      string id;
      do
      {
        n++;
        stringstream os;
        os << n << std::setw(minLength) << std::setfill('0');
        string id = os.str();
        id = entitiesutils::AROBAS + prefix_ + id + entitiesutils::AROBAS;
        if (map_.find(id) == map_.end())
        {
          nmax_ = n;
          break;
        }
      } while (true);
      return id;
    } // nextId

  }; // classentitymap
} // namespace infoged
#endif // ENTITYMAP_H__