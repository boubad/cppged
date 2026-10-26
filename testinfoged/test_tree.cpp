///////////////////////
#include <doctest/doctest.h>
///////////////////////
#include <tree.h>
#include <treeutils.h>
////////////////////////
#include "nodefixture.h"
#include <createnode.h>
////////////////////////
#include <filesystem>
//////////////////////
using namespace infoged;
using namespace infoged::test;
///////////////////////
TEST_SUITE_BEGIN("otree tests suite");
///////////////////////
TEST_CASE("Default constructor")
{
    tree otree;
    //
    CHECK(otree.getHeader().isValid() == false);
    CHECK(otree.getFamilies().size() == 0);
    CHECK(otree.getIndividuals().size() == 0);
    CHECK(otree.getMultimedias().size() == 0);
    CHECK(otree.getNotes().size() == 0);
    CHECK(otree.getSources().size() == 0);
    CHECK(otree.getSubmitters().size() == 0);
    CHECK(otree.getRepositories().size() == 0);
    CHECK(otree.getSubmissions().size() == 0);
    CHECK(otree.getTrailer().isValid() == true);
    //
    tree otree2(otree);
    CHECK(otree2.getHeader().isValid() == false);
    CHECK(otree2.getFamilies().size() == 0);
    CHECK(otree2.getIndividuals().size() == 0);
    CHECK(otree2.getMultimedias().size() == 0);
    CHECK(otree2.getNotes().size() == 0);
    CHECK(otree2.getSources().size() == 0);
    CHECK(otree2.getSubmitters().size() == 0);
    CHECK(otree2.getRepositories().size() == 0);
    CHECK(otree2.getSubmissions().size() == 0);
    CHECK(otree2.getTrailer().isValid() == true);
    //
    tree otree3;
    otree3 = otree;
    CHECK(otree3.getHeader().isValid() == false);
    CHECK(otree3.getFamilies().size() == 0);
    CHECK(otree3.getIndividuals().size() == 0);
    CHECK(otree3.getMultimedias().size() == 0);
    CHECK(otree3.getNotes().size() == 0);
    CHECK(otree3.getSources().size() == 0);
    CHECK(otree3.getSubmitters().size() == 0);
    CHECK(otree3.getRepositories().size() == 0);
    CHECK(otree3.getSubmissions().size() == 0);
    CHECK(otree3.getTrailer().isValid() == true);
} // TEST_CASE
TEST_CASE("Constructor from filepath")
{
    const nodefixture &fixture = nodefixture::getInstance();
    string filepath = fixture.get_test_ged_filename();
    tree otree(filepath);
    CHECK(otree.getFamilies().size() > 0);
    CHECK(otree.getIndividuals().size() > 0);
    CHECK(otree.getMultimedias().size() > 0);
    CHECK(otree.getNotes().size() > 0);
    CHECK(otree.getSources().size() > 0);
    CHECK(otree.getSubmitters().size() > 0);
    CHECK(otree.getRepositories().size() == 0);
    CHECK(otree.getSubmissions().size() == 0);
    CHECK(otree.getTrailer().isValid() == true);
} // TEST_CASE
TEST_CASE("Objects filenames" * doctest::skip(true))
{
    const nodefixture &fixture = nodefixture::getInstance();
    //
    string mediadir = fixture.get_genea_media_dir();
    std::error_code ec;
    if (!std::filesystem::exists(mediadir, ec))
    {
        std::filesystem::create_directory(mediadir);
    }
    CHECK(std::filesystem::is_directory(mediadir, ec));
    stringset allfilesnames;
    for (const auto &f : std::filesystem::directory_iterator(mediadir))
    {
        if (f.is_regular_file())
        {
            string filename = f.path().filename().string();
            allfilesnames.insert(filename);
        }
    } // for
    //
    string filepath = fixture.get_test_ged_filename();
    tree otree(filepath);
    //
    stringset filenames;
    otree.getAllObjectsFileNames(filenames);
    CHECK(filenames.size() > 0);
    //
    stringset removefiles;
    for (auto &f : allfilesnames)
    {
        if (filenames.find(f) == filenames.end())
        {
            removefiles.insert(f);
        }
    }
    for (auto &f : removefiles)
    {
        std::filesystem::remove(mediadir + "/" + f);
    }
    //
} // TEST_CASE
TEST_CASE("Remove bad objects")
{
    const nodefixture &fixture = nodefixture::getInstance();
    string filepath = fixture.get_test_ged_filename();
    tree otree(filepath);
    //
    string mediadir = fixture.get_genea_media_dir();
    stringset ids;
    otree.getNotExistingFileObjects(ids, mediadir);
    if (!ids.empty())
    {
        for (auto &id : ids)
        {
            const node *pNode = otree.find(id);
            if (pNode != nullptr)
            {
                const multinode *pmultinode = dynamic_cast<const multinode *>(pNode);
                if (pmultinode != nullptr)
                {
                    otree.removeReference(id);
                    otree.getMultimedias().remove(id);
                }
            }
        }
        ids.clear();
        otree.getNotExistingFileObjects(ids, mediadir);
        CHECK(ids.empty());
    } // ids
} // TEST_CASE
TEST_CASE("Remove invalid references")
{
    const nodefixture &fixture = nodefixture::getInstance();
    string filepath = fixture.get_test_ged_filename();
    tree otree(filepath);
#if 0
    string mediadir = fixture.get_genea_media_dir();
    //
    std::cout << "... ==> ORIGINAL" << std::endl;
    otree.getSummary(std::cout);
    //
    otree.prepareExport(mediadir);
    //
    std::cout << std::endl
              << "... ==> CHECKING" << std::endl
              << std::endl;
    otree.getSummary(std::cout);
    std::cout << std::endl;
#endif
    string outfilepath = fixture.get_test_temp_ged_filename();
    bool b = otree.writeToFile(outfilepath);
    REQUIRE(b);
    //
} // TEST_CASE
TEST_CASE("show data")
{
    const nodefixture &fixture = nodefixture::getInstance();
    string filepath = fixture.get_test_ged_filename();
    tree otree(filepath);
    //
    std::map<status, stringvector> statusmap;
    auto visitFunc = [&statusmap](const node *pNode)
    {
        status s = pNode->getStatus();
        if (s != status::Normal)
        {
            string line = pNode->getLineString();
            if (!line.empty())
            {
                auto it = statusmap.find(s);
                if (it == statusmap.end())
                {
                    stringvector lines;
                    lines.push_back(line);
                    statusmap.insert(std::make_pair(s, lines));
                }
                else
                {
                    it->second.push_back(line);
                }
            }
        }
    };
    //
    treeutils::checkStatus(&otree);
    otree.visit(visitFunc);
    //
    for (auto &s : statusmap)
    {
        // string sstatus = statusToString(s.first);
        size_t n = s.second.size();
        CHECK(n > 0);
        // std::cout << "Status: " << sstatus << " (" << n << ")" << std::endl;
    }
} // TEST_CASE
TEST_CASE("show  tags")
{

    const nodefixture &fixture = nodefixture::getInstance();
    string filepath = fixture.get_test_ged_filename();
    tree otree(filepath);
    //
    std::map<string, size_t> tagsmap;
    auto visitFunc = [&tagsmap](const node *pNode)
    {
        const string &tag = pNode->getTag();
        auto it = tagsmap.find(tag);
        if (it == tagsmap.end())
        {
            tagsmap.insert(std::make_pair(tag, 1));
        }
        else
        {
            it->second++;
        }
    };
    //
    otree.visit(visitFunc);
    //
    for (auto &s : tagsmap)
    {
        size_t n = s.second;
        CHECK(n > 0);
        std::cout << "Tag: " << s.first << " (" << n << ")" << std::endl;
    }
} // TEST_CASE
//////////////////////////////
TEST_SUITE_END();