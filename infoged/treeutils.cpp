
#include "treeutils.h"
#include "tree.h"
#include "stringconstants.h"
#include "stringutils.h"
#include "gedconstants.h"
///////////////////////////////
#include <cassert>
#include <filesystem>
/////////////////////////////////
namespace infoged
{
    void treeutils::checkStatus(tree *pTree)
    {
        assert(pTree != nullptr);
        bool hasMediaDir(false);
        string mediasdir = stringutils::trim(pTree->getMediasDir());
        if (!mediasdir.empty())
        {
            hasMediaDir = std::filesystem::exists(mediasdir);
        }
        stringset ids, references, individs, familyids, notesids, multimediaids,
            sourcerecordids, submitterrecordids,
            repositoryrecordids, submissionrecordids;
        pTree->getAllReferences(references);
        pTree->getAllIds(ids);
        pTree->getIndividuals().keys(individs);
        pTree->getFamilies().keys(familyids);
        pTree->getNotes().keys(notesids);
        pTree->getMultimedias().keys(multimediaids);
        pTree->getSources().keys(sourcerecordids);
        pTree->getSubmitters().keys(submitterrecordids);
        pTree->getRepositories().keys(repositoryrecordids);
        pTree->getSubmissions().keys(submissionrecordids);
        auto mutatefunc = [&pTree, &hasMediaDir, &mediasdir, &references, &ids,
                           &individs, &familyids, &notesids, &multimediaids, &sourcerecordids,
                           &submitterrecordids, &repositoryrecordids, &submissionrecordids](node *pNode)
        {
            pNode->check();
            if (pNode->getStatus() != status::Normal)
            {
                return;
            }
            const int level = pNode->getLevel();
            const string &tag = pNode->getTag();
            string value = pNode->getValue();
            const string &id = pNode->getId();
            string xref = stringutils::isPointer(value) ? value : string();
            if (level == 0)
            {
                if (!id.empty() && stringutils::isPointer(id))
                {
                    if (references.find(id) == references.end())
                    {
                        pNode->setStatus(status::NotReferenced);
                        return;
                    }

                } // id
                return;
            }
            else if (xref.empty())
            {
                return;
            }
            if (tag == gedconstants::GED_CHIL ||
                tag == gedconstants::GED_HUSB ||
                tag == gedconstants::GED_WIFE ||
                tag == gedconstants::GED_ALIA ||
                tag == gedconstants::GED_ASSO)
            {
                if (individs.find(xref) == individs.end())
                {
                    pNode->setStatus(status::MissingRecord);
                    return;
                }
            }

            else if (tag == gedconstants::GED_FAMC ||
                     tag == gedconstants::GED_FAMS)
            {
                if (familyids.find(xref) == familyids.end())
                {
                    pNode->setStatus(status::MissingRecord);
                    return;
                }
            }
            else if (tag == gedconstants::GED_NOTE)
            {
                if (notesids.find(xref) == notesids.end())
                {
                    pNode->setStatus(status::MissingRecord);
                    return;
                }
            }
            else if (tag == gedconstants::GED_OBJE)
            {
                if (multimediaids.find(xref) == multimediaids.end())
                {
                    pNode->setStatus(status::MissingRecord);
                    return;
                }
            }
            else if (tag == gedconstants::GED_SOUR)
            {
                if (sourcerecordids.find(xref) == sourcerecordids.end())
                {
                    pNode->setStatus(status::MissingRecord);
                    return;
                }
            }
            else if (tag == gedconstants::GED_SUBM)
            {
                if (submitterrecordids.find(xref) == submitterrecordids.end())
                {
                    pNode->setStatus(status::MissingRecord);
                    return;
                }
            }
            else if (tag == gedconstants::GED_REPO)
            {
                if (repositoryrecordids.find(xref) == repositoryrecordids.end())
                {
                    pNode->setStatus(status::MissingRecord);
                    return;
                }
            }
        };
        //
        pTree->mutate(mutatefunc);
    } // checkStatus
} // namespace infoged