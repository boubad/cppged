
#include "tree.h"
#include "stringutils.h"
#include "gedconstants.h"
#include "entitiesutils.h"
#include "treeutils.h"
#include "createnode.h"
#include "treeutils.h"
//////////////////////
#include <cassert>
#include <filesystem>
///////////////////////
namespace infoged
{
  //////////////////////////
  template <typename T>
  static bool insertnode(entitymap<T> &omap, const node::nodePtr &node)
  {
    const T *record = dynamic_cast<const T *>(node.get());
    if (record != nullptr)
    {
      omap.add(*record);
      return true;
    }
    return false;
  } // insertnode<T>
  ///////////////////////////
  tree::tree()
  {
  }
  tree::tree(istream &in)
  {
    tree::read(in);
    initmaps();
  }
  tree::tree(const string &filename)
  {
    readFromFile(filename);
    initmaps();
  }
  tree::tree(const tree &other)
      : header_(other.header_), families_(other.families_),
        individuals_(other.individuals_), medias_(other.medias_),
        notes_(other.notes_), sources_(other.sources_),
        submitters_(other.submitters_), repositories_(other.repositories_),
        submissions_(other.submissions_), trailer_(other.trailer_),
        mediasDir_(other.mediasDir_)
  {
  }
  tree &tree::operator=(const tree &other)
  {
    if (this != &other)
    {
      header_ = other.header_;
      families_ = other.families_;
      individuals_ = other.individuals_;
      medias_ = other.medias_;
      notes_ = other.notes_;
      sources_ = other.sources_;
      submitters_ = other.submitters_;
      repositories_ = other.repositories_;
      submissions_ = other.submissions_;
      trailer_ = other.trailer_;
      mediasDir_ = other.mediasDir_;
    }
    return *this;
  }
  tree::~tree()
  {
  }
  void tree::initmaps(void)
  {
    families_.setPrefix(entitiesutils::GED_PREFIX_FAMILY);
    individuals_.setPrefix(entitiesutils::GED_PREFIX_INDIVIDUAL);
    medias_.setPrefix(entitiesutils::GED_PREFIX_MULTIMEDIA);
    notes_.setPrefix(entitiesutils::GED_PREFIX_NOTE);
    sources_.setPrefix(entitiesutils::GED_PREFIX_SOURCE);
    submitters_.setPrefix(entitiesutils::GED_PREFIX_SUBMITTER);
    repositories_.setPrefix(entitiesutils::GED_PREFIX_REPOSITORY);
    submissions_.setPrefix(entitiesutils::GED_PREFIX_SUBMISSION);
  }
  const string &tree::getMediasDir(void) const
  {
    return mediasDir_;
  }
  void tree::setMediasDir(const string &dir)
  {
    mediasDir_ = dir;
  }
  //
  header &tree::getHeader(void)
  {
    return header_;
  }
  const header &tree::getHeader(void) const
  {
    return header_;
  }
  entitymap<familyrecord> &tree::getFamilies(void)
  {
    return families_;
  }
  const entitymap<familyrecord> &tree::getFamilies(void) const
  {
    return families_;
  }
  entitymap<individualrecord> &tree::getIndividuals(void)
  {
    return individuals_;
  }
  const entitymap<individualrecord> &tree::getIndividuals(void) const
  {
    return individuals_;
  }
  entitymap<multimediarecord> &tree::getMultimedias(void)
  {
    return medias_;
  }
  const entitymap<multimediarecord> &tree::getMultimedias(void) const
  {
    return medias_;
  }
  entitymap<noterecord> &tree::getNotes(void)
  {
    return notes_;
  }
  const entitymap<noterecord> &tree::getNotes(void) const
  {
    return notes_;
  }
  entitymap<sourcerecord> &tree::getSources(void)
  {
    return sources_;
  }
  const entitymap<sourcerecord> &tree::getSources(void) const
  {
    return sources_;
  }
  entitymap<submitterrecord> &tree::getSubmitters(void)
  {
    return submitters_;
  }
  const entitymap<submitterrecord> &tree::getSubmitters(void) const
  {
    return submitters_;
  }
  entitymap<repositoryrecord> &tree::getRepositories(void)
  {
    return repositories_;
  }
  const entitymap<repositoryrecord> &tree::getRepositories(void) const
  {
    return repositories_;
  }
  entitymap<submissionrecord> &tree::getSubmissions(void)
  {
    return submissions_;
  }
  const entitymap<submissionrecord> &tree::getSubmissions(void) const
  {
    return submissions_;
  }
  trailer &tree::getTrailer(void)
  {
    return trailer_;
  }
  const trailer &tree::getTrailer(void) const
  {
    return trailer_;
  }
  //
  void tree::clear(void)
  {
    header_.clear();
    families_.clear();
    individuals_.clear();
    medias_.clear();
    notes_.clear();
    sources_.clear();
    submitters_.clear();
    repositories_.clear();
    submissions_.clear();
    trailer_.clear();
  } // clear
  void tree::check(void)
  {
    auto func = [](node *p)
    { p->check(); };
    mutate(func);
  }
  bool tree::isValid(void) const
  {
    if (!header_.isValid())
    {
      return false;
    }
    if (!trailer_.isValid())
    {
      return false;
    }
    return true;
  } // isValid
  ///////////////////////////
  bool tree::registerItem(node::nodePtr p)
  {
    node *pnode = p.get();
    assert(pnode != nullptr);
    assert(pnode->getLevel() == 0);
    string tag = pnode->getTag();
    if (tag == gedconstants::GED_HEAD)
    {
      header *pp = dynamic_cast<header *>(pnode);
      if (pp != nullptr)
      {
        header_ = *pp;
        return true;
      }
      return false;
    }
    else if (tag == gedconstants::GED_TRLR)
    {
      trailer *pp = dynamic_cast<trailer *>(pnode);
      if (pp != nullptr)
      {
        trailer_ = *pp;
        return true;
      }
      return false;
    }
    else if (tag == gedconstants::GED_SUBM)
    {
      return insertnode(submitters_, p);
    }
    else if (tag == gedconstants::GED_FAM)
    {
      return insertnode(families_, p);
    }
    else if (tag == gedconstants::GED_INDI)
    {
      return insertnode(individuals_, p);
    }
    else if (tag == gedconstants::GED_NOTE)
    {
      return insertnode(notes_, p);
    }
    else if (tag == gedconstants::GED_SOUR)
    {
      return insertnode(sources_, p);
    }
    else if (tag == gedconstants::GED_REPO)
    {
      return insertnode(repositories_, p);
    }
    else if (tag == gedconstants::GED_SUBM)
    {
      return insertnode(submissions_, p);
    }

    else if (tag == gedconstants::GED_OBJE)
    {
      return insertnode(medias_, p);
    }
    return false;
  }
  void tree::fromTokensArray(const tokensLine::tokensLinesArray &tokensArray)
  {
    auto it = tokensArray.begin();
    while (it != tokensArray.end())
    {
      const tokensLine::tokensLinesList &xtokens = *it++;
      node::nodePtr p = createnode::createNode(xtokens);
      if (p.get() != nullptr)
      {
        registerItem(p);
      }
    }
  } // fromTokensArray
  istream &tree::read(istream &in)
  {
    tokensLine::tokensLinesList tokens;
    tokensLine::parseStream(in, tokens);
    tokensLine::tokensLinesArray tokensArray;
    tokensLine::tokensLine::parseEntities(tokens, tokensArray);
    fromTokensArray(tokensArray);
    return in;
  } // read
  bool tree::readFromFile(const string &filename)
  {
    ifstream in(filename);
    if (!in)
    {
      return false;
    }
    tree::read(in);
    in.close();
    return true;
  } // readFromFile
  bool tree::writeToFile(const string &filename) const
  {
    ofstream out(filename);
    if (!out)
    {
      return false;
    }
    write(out);
    out.close();
    return true;
  }
  ostream &tree::print(ostream &os) const
  {
    return getSummary(os);
  }
  ostream &tree::getSummary(ostream &os) const
  {
    families_.getSummary(os);
    individuals_.getSummary(os);
    medias_.getSummary(os);
    notes_.getSummary(os);
    sources_.getSummary(os);
    submitters_.getSummary(os);
    repositories_.getSummary(os);
    submissions_.getSummary(os);
    return os;
  }
  familyrecord *tree::createfamilyrecord(const string &id)
  {
    node::nodePtr p = createnode::createNode(0, gedconstants::GED_FAM, string(), id);
    if (p.get() == nullptr)
    {
      return nullptr;
    }
    registerItem(p);
    return dynamic_cast<familyrecord *>(p.get());
  } // createfamilyrecord
  individualrecord *tree::createindividualrecord(const string &id)
  {
    node::nodePtr p = createnode::createNode(0, gedconstants::GED_INDI, string(), id);
    if (p.get() == nullptr)
    {
      return nullptr;
    }
    registerItem(p);
    return dynamic_cast<individualrecord *>(p.get());
  }
  multimediarecord *tree::createmultimediarecord(const string &id)
  {
    node::nodePtr p = createnode::createNode(0, gedconstants::GED_OBJE, string(), id);
    if (p.get() == nullptr)
    {
      return nullptr;
    }
    registerItem(p);
    return dynamic_cast<multimediarecord *>(p.get());
  }
  noterecord *tree::createnoterecord(const string &id)
  {
    node::nodePtr p = createnode::createNode(0, gedconstants::GED_NOTE, string(), id);
    if (p.get() == nullptr)
    {
      return nullptr;
    }
    registerItem(p);
    return dynamic_cast<noterecord *>(p.get());
  }
  sourcerecord *tree::createsourcerecord(const string &id)
  {
    node::nodePtr p = createnode::createNode(0, gedconstants::GED_SOUR, string(), id);
    if (p.get() == nullptr)
    {
      return nullptr;
    }
    registerItem(p);
    return dynamic_cast<sourcerecord *>(p.get());
  }
  repositoryrecord *tree::createrepositoryrecord(const string &id)
  {
    node::nodePtr p = createnode::createNode(0, gedconstants::GED_REPO, string(), id);
    if (p.get() == nullptr)
    {
      return nullptr;
    }
    registerItem(p);
    return dynamic_cast<repositoryrecord *>(p.get());
  }
  submissionrecord *tree::createsubmissionrecord(const string &id)
  {
    node::nodePtr p = createnode::createNode(0, gedconstants::GED_SUBM, string(), id);
    if (p.get() == nullptr)
    {
      return nullptr;
    }
    registerItem(p);
    return dynamic_cast<submissionrecord *>(p.get());
  }
  submitterrecord *tree::createsubmitterrecord(const string &id)
  {
    node::nodePtr p = createnode::createNode(0, gedconstants::GED_SUBN, string(), id);
    if (p.get() == nullptr)
    {
      return nullptr;
    }
    registerItem(p);
    return dynamic_cast<submitterrecord *>(p.get());
  }
  /////////////////////////////////////////////
  void tree::mutate(const node::mutateFunc &func)
  {
    header_.mutate(func);
    families_.mutate(func);
    individuals_.mutate(func);
    medias_.mutate(func);
    notes_.mutate(func);
    sources_.mutate(func);
    submitters_.mutate(func);
    repositories_.mutate(func);
    submissions_.mutate(func);
    trailer_.mutate(func);
  }
  void tree::visit(const node::visitorFunc &func) const
  {
    header_.visit(func);
    families_.visit(func);
    individuals_.visit(func);
    medias_.visit(func);
    notes_.visit(func);
    sources_.visit(func);
    submitters_.visit(func);
    repositories_.visit(func);
    submissions_.visit(func);
    trailer_.visit(func);
  }
  void tree::remove(const node::filterFunc &func)
  {
    header_.remove(func);
    families_.remove(func);
    individuals_.remove(func);
    medias_.remove(func);
    notes_.remove(func);
    sources_.remove(func);
    submitters_.remove(func);
    repositories_.remove(func);
    submissions_.remove(func);
    trailer_.remove(func);
  } // remove
  void tree:: removeReference(const string &ref)
  {
    string xref = stringutils::trim(ref);
    if (!stringutils::isPointer(xref))
    {
      return;
    }
    auto filterfunc = [&xref](const node *p) -> bool
    {
      return p->getValue() == xref;
    };
    remove(filterfunc);
  } // removeReference

  bool tree::hasReference(const string &ref) const
  {
    string xref = stringutils::trim(ref);
    if (!stringutils::isPointer(xref))
    {
      return false;
    }
    bool res = false;
    auto func = [&xref, &res](const node *p) -> bool
    {
      if (res)
      {
        return true;
      }
      if (p->getValue() == xref)
      {
        res = true;
        return true;
      }
      return false;
    };
    visit(func);
    return res;
  } // hasReference
  void tree::getAllIds(stringset &ids) const
  {
    ids.clear();
    auto func = [&ids](const node *p) -> bool
    {
      string id = p->getId();
      if (stringutils::isPointer(id))
      {
        ids.insert(id);
      }
      return false;
    };
    visit(func);
  } // getAllIds
  void tree::getAllReferences(stringset &refs) const
  {
    refs.clear();
    auto func = [&refs](const node *p) -> bool
    {
      string ref = p->getValue();
      if (stringutils::isPointer(ref))
      {
        refs.insert(ref);
      }
      return false;
    };
    visit(func);
  }
  void tree::removeNonCompliantTags(void)
  {
    treeutils::checkStatus(this);
    auto func = [](const node *p) -> bool
    {
      if (p->getStatus() != status::Normal)
      {
        return true;
      }
      return false;
    };
    remove(func);
  }
  void tree::removeNodesByTag(const string &tag)
  {
    string stag = stringutils::uppercase(stringutils::trim(tag));
    if (!stringutils::isTag(stag))
    {
      return;
    }
    auto func = [&stag](const node *p) -> bool
    {
      return p->getTag() == stag;
    };
    remove(func);
  }
  void tree::getInvalidReferences(stringset &refs) const
  {
    refs.clear();
    stringset ids, references;
    getAllReferences(references);
    getAllIds(ids);
    for (const string &ref : references)
    {
      if (ids.find(ref) == ids.end())
      {
        refs.insert(ref);
      }
    }
  } // getInvalidReferences
  void tree::removeInvalidReferences(void)
  {
    stringset refs;
    getInvalidReferences(refs);
    for (const auto &ref : refs)
    {
      removeReference(ref);
    }
  } // removeInvalidReferences
  void tree::getNotReferencedEntities(stringset &refs) const
  {
    refs.clear();
    stringset ids, references;
    getAllReferences(references);
    getAllIds(ids);
    for (const auto &id : ids)
    {
      if (references.find(id) == references.end())
      {
        refs.insert(id);
      }
    }
  } // getNotReferencedEntities

  void tree::removeNotReferencedMedias(void)
  {
    stringset ids, references;
    medias_.keys(ids);
    getAllReferences(references);
    for (const auto &id : ids)
    {
      if (references.find(id) == references.end())
      {
        medias_.remove(id);
      }
    }
  }
  void tree::removeNotReferencedNotes(void)
  {
    stringset ids, references;
    notes_.keys(ids);
    getAllReferences(references);
    for (string id : ids)
    {
      if (references.find(id) == references.end())
      {
        notes_.remove(id);
      }
    }
  }
  void tree::setMediaDir(const string &mediadir)
  {
    auto &col = medias_.getMap();
    for (auto &p : col)
    {
      p.second.setMediaDir(mediadir);
    }
    // tree::check();
  } // setMediaDir
  bool tree::getNotExistingFileObjects(stringset &ids,
                                       const string &mediadir) const
  {
    ids.clear();
    auto &col = medias_.getMap();
    for (auto &p : col)
    {
      const multimediarecord &m = p.second;
      if (!m.existsFile(mediadir))
      {
        ids.insert(m.getId());
      }
    }
    return ids.size() > 0;
  }
  void tree::checkMediaFiles(const string &mediadir)
  {
    if (!mediadir.empty())
    {
      setMediaDir(mediadir);
    }
    stringset ids;
    getNotExistingFileObjects(ids, mediadir);
    if (!ids.empty())
    {
      for (auto &id : ids)
      {
        const node *pnode = find(id);
        if (pnode != nullptr)
        {
          const multimediarecord *pmultimediarecord =
              dynamic_cast<const multimediarecord *>(pnode);
          if (pmultimediarecord != nullptr)
          {
            removeReference(id);
            medias_.remove(id);
          }
        }
      }
    }
  } // checkMediaFiles
  void tree::prepareExport(const string & /*mediadir*/)
  {
    // removeNodesByTag(gedconstants::GED_WTMARNM);
    removeNodesByTag(gedconstants::GED_CHAN);
    removeNonCompliantTags();
    checkNotes();
  }
  bool tree::getAllObjectsFileNames(stringset &filenames) const
  {
    filenames.clear();
    auto &col = medias_.getMap();
    for (auto &p : col)
    {
      const multimediarecord &m = p.second;
      string sfilepath = m.getMediaFileName();
      if (!sfilepath.empty())
      {
        std::filesystem::path p(sfilepath);
        string sfilename = p.filename().string();
        if (!sfilename.empty())
        {
          filenames.insert(sfilename);
        }
      }
    }
    return filenames.size() > 0;
  }
  const node *tree::find(const string &id) const
  {
    {
      const node *pRecord = families_.find(id);
      if (pRecord != nullptr)
      {
        return pRecord;
      }
    } // fmallies
    {
      const node *pRecord = individuals_.find(id);
      if (pRecord != nullptr)
      {
        return pRecord;
      }
    } // individuals
    {
      const node *pRecord = medias_.find(id);
      if (pRecord != nullptr)
      {
        return pRecord;
      }
    } // medias
    {
      const node *pRecord = notes_.find(id);
      if (pRecord != nullptr)
      {
        return pRecord;
      }
    } // notes
    {
      const node *pRecord = sources_.find(id);
      if (pRecord != nullptr)
      {
        return pRecord;
      }
    } // sources
    {
      const node *pRecord = submitters_.find(id);
      if (pRecord != nullptr)
      {
        return pRecord;
      }
    } // submitters
    {
      const node *pRecord = repositories_.find(id);
      if (pRecord != nullptr)
      {
        return pRecord;
      }
    } // repositories
    {
      const node *pRecord = submissions_.find(id);
      if (pRecord != nullptr)
      {
        return pRecord;
      }
    }
    return nullptr;
  } // find
  node *tree::remove(const string &id)
  {
    const node *pRecord = find(id);
    if (pRecord != nullptr)
    {
      removeReference(id);
      families_.remove(id);
      individuals_.remove(id);
      medias_.remove(id);
      notes_.remove(id);
      sources_.remove(id);
      submitters_.remove(id);
      repositories_.remove(id);
      submissions_.remove(id);
      return const_cast<node *>(pRecord);
    }
    return nullptr;
  } // find
  void tree::checkNotes(void)
  {
    stringset ids;
    notes_.keys(ids);
    stringset notestoremove;
    for (const auto &id : ids)
    {
      noterecord *pNote = notes_.find(id);
      string value = pNote->getSubmitterText();
      if (value.empty())
      {
        notestoremove.insert(id);
      }
      else if (!stringutils::isPointer(value) && value.length() > 220)
      {
        pNote->setSubmitterText(value);
      }
    } // id
    for (const auto &id : notestoremove)
    {
      removeReference(id);
      notes_.remove(id);
    } // id
    notes_.keys(ids);
    stringmap notesmap;
    notestoremove.clear();
    for (auto it = ids.begin(); it != ids.end(); ++it)
    {
      const noterecord *pNote1 = notes_.find(*it);
      string submitter_text1 = pNote1->getSubmitterText();
      auto jt = it;
      jt++;
      while (jt != ids.end())
      {
        const noterecord *pNote2 = notes_.find(*jt);
        if (pNote2->getSubmitterText() == submitter_text1)
        {
          notesmap[*jt] = *it;
          notestoremove.insert(*jt);
        }
        ++jt;
      } // jt
    } // it
    for (const string &id : notestoremove)
    {
      auto it = notesmap.find(id);
      if (it != notesmap.end())
      {
        const string &newref = it->second;
        replaceReference(id, newref);
      }
      notes_.remove(id);
    } // id
  } // checkNotes
  const stringvector &tree::getPrefixes(void) const
  {
    static stringvector ovector;
    if (!ovector.empty())
    {
      return ovector;
    }
    ovector.push_back(families_.getPrefix());
    ovector.push_back(individuals_.getPrefix());
    ovector.push_back(medias_.getPrefix());
    ovector.push_back(notes_.getPrefix());
    ovector.push_back(sources_.getPrefix());
    ovector.push_back(submitters_.getPrefix());
    ovector.push_back(repositories_.getPrefix());
    ovector.push_back(submissions_.getPrefix());
    return ovector;
  }
  void tree::replaceReference(const string &oldref, const string &newref)
  {
    string soldref = stringutils::trim(oldref);
    string snewref = stringutils::trim(newref);
    if (!stringutils::isPointer(soldref) || !stringutils::isPointer(snewref) || soldref == snewref)
    {
      return;
    }
    auto func = [&soldref, &snewref](node *p)
    {
      if (p->getValue() == soldref)
      {
        p->setValue(snewref);
      }
    }; // func
    mutate(func);
  } // replaceReference
  ostream &tree::write(ostream &os) const
  {
    header_.write(os);
    families_.write(os);
    individuals_.write(os);
    submitters_.write(os);
    sources_.write(os);
    repositories_.write(os);
    submissions_.write(os);
    medias_.write(os);
    notes_.write(os);
    trailer_.write(os);
    return os;
  }
  //////////////////////////////
} // namespace infoged