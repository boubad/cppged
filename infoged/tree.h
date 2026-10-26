#pragma once
///////////////////////
#ifndef GEDCOMTREE_H__
#define GEDCOMTREE_H__
/////////////////////////////////
#include "token.h"
#include "header.h"
#include "entitymap.h"
#include "multimediarecord.h"
#include "sourcerecord.h"
#include "individualrecord.h"
#include "noterecord.h"
#include "trailer.h"
#include "familyrecord.h"
#include "repositoryrecord.h"
#include "submitterrecord.h"
#include "submissionrecord.h"
//////////////////////////////
namespace infoged
{
    class tree
    {
        friend class treeutils;

    public:
        tree();
        tree(istream &in);
        tree(const string &filename);
        tree(const tree &other);
        tree &operator=(const tree &other);
        virtual ~tree();

    public:
        const string &getMediasDir(void) const;
        void setMediasDir(const string &dir);
        header &getHeader(void);
        const header &getHeader(void) const;
        entitymap<familyrecord> &getFamilies(void);
        const entitymap<familyrecord> &getFamilies(void) const;
        entitymap<individualrecord> &getIndividuals(void);
        const entitymap<individualrecord> &getIndividuals(void) const;
        entitymap<multimediarecord> &getMultimedias(void);
        const entitymap<multimediarecord> &getMultimedias(void) const;
        entitymap<noterecord> &getNotes(void);
        const entitymap<noterecord> &getNotes(void) const;
        entitymap<sourcerecord> &getSources(void);
        const entitymap<sourcerecord> &getSources(void) const;
        entitymap<submitterrecord> &getSubmitters(void);
        const entitymap<submitterrecord> &getSubmitters(void) const;
        entitymap<repositoryrecord> &getRepositories(void);
        const entitymap<repositoryrecord> &getRepositories(void) const;
        entitymap<submissionrecord> &getSubmissions(void);
        const entitymap<submissionrecord> &getSubmissions(void) const;
        trailer &getTrailer(void);
        const trailer &getTrailer(void) const;

    public:
        familyrecord *createfamilyrecord(const string &id = string());
        individualrecord *createindividualrecord(const string &id = string());
        multimediarecord *createmultimediarecord(const string &id = string());
        noterecord *createnoterecord(const string &id = string());
        sourcerecord *createsourcerecord(const string &id = string());
        submitterrecord *createsubmitterrecord(const string &id = string());
        repositoryrecord *createrepositoryrecord(const string &id = string());
        submissionrecord *createsubmissionrecord(const string &id = string());

    public:
        istream &read(istream &is);
        ostream &write(ostream &os) const;
        void check(void);
        void clear(void);
        bool isValid(void) const;

    public:
        void mutate(const node::mutateFunc &func);
        void visit(const node::visitorFunc &func) const;
        void remove(const node::filterFunc &func);
        //
        ostream &print(ostream &os) const;
        ostream &getSummary(ostream &os) const;
        bool readFromFile(const string &filename);
        bool writeToFile(const string &filename) const;
        //
        void removeReference(const string &ref);
        bool hasReference(const string &ref) const;
        void checkNotes(void);
        void getInvalidReferences(stringset &refs) const;
        void getNotReferencedEntities(stringset &ids) const;
        void removeInvalidReferences(void);
        void removeNotReferencedMedias(void);
        void removeNotReferencedNotes(void);
        void removeNonCompliantTags(void);
        const node *find(const string &id) const;
        node *remove(const string &id);
        void setMediaDir(const string &mediadir);
        bool getAllObjectsFileNames(stringset &filenames) const;
        bool getNotExistingFileObjects(stringset &ids, const string &mediadir = string()) const;
        void checkMediaFiles(const string &mediadir = string());
        void prepareExport(const string &mediadir = string());
        void replaceReference(const string &oldref, const string &newref);
        void removeNodesByTag(const string &tag);

    private:
        void initmaps(void);
        const stringvector &getPrefixes(void) const;
        void getAllIds(stringset &ids) const;
        void getAllReferences(stringset &refs) const;
        bool registerItem(node::nodePtr p);
        void fromTokensArray(const tokensLine::tokensLinesArray &tokensArray);

    private:
        header header_;
        entitymap<familyrecord> families_;
        entitymap<individualrecord> individuals_;
        entitymap<multimediarecord> medias_;
        entitymap<noterecord> notes_;
        entitymap<sourcerecord> sources_;
        entitymap<submitterrecord> submitters_;
        entitymap<repositoryrecord> repositories_;
        entitymap<submissionrecord> submissions_;
        trailer trailer_;
        string mediasDir_;
    };
} // namespace
///////////////////////////////////////
inline infoged::ostream &operator<<(infoged::ostream &os, const infoged::tree &tree)
{
    return tree.print(os);
}
inline infoged::istream &operator>>(infoged::istream &is, infoged::tree &tree)
{
    return tree.read(is);
}
////////////////////////////////////////
#endif // GEDCOMTREE_H__
