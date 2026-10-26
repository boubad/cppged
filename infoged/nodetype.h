#pragma once
#ifndef NODETYPE_H__
#define NODETYPE_H__
/////////////////////
namespace infoged
{
  //////////////////////
  enum class nodetype
  {
    Address,
    Association,
    Base,
    ChangeDate,
    ChildToFamilyLink,
    Data,
    Entity,
    Family,
    Generic,
    Guard,
    Header,
    Individual,
    LdsSpouseSealing,
    MultiRecord,
    Multimedia,
    MultimediaLink,
    Note,
    NoteStructure,
    PersonalName,
    Place,
    Proxy,
    Repository,
    RepositoryCitation,
    Single,
    Source,
    SourceCitation,
    SourceRepositoryCitation,
    SpouseToFamilyLink,
    Submission,
    Submitter,
    Trailer
  }; // nodetype
  ///////////////////////
} // namespace infoged
/////////////////////////
#endif // NODETYPE_H__