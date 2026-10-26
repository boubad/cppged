#pragma once
#ifndef STATUS_H__
#define STATUS_H__
////////////////////////
#include "mydefs.h"
////////////////////////
namespace infoged
{
	enum class status : int
	{
		BadEntityDefinition,
		BadLevelValue,
		BadReferenceLocation,
		ChangedData,
		InconsistentData,
		IncorrectData,
		Inserted,
		InvalidId,
		InvalidLevel,
		InvalidTag,
		MissingChildren,
		MissingData,
		MissingFile,
		MissingRecord,
		NntCompliantReference,
		NoValue,
		NonCompliant,
		Normal,
		NotChanged,
		NotCompliantId,
		NotCompliantLevel,
		NotCompliantTag,
		NotReferenced,
		NotValid,
		Removed,
		Transformed,
	};
	extern const string statusToString(status st);
} // namespace infoged
////////////////////////
#endif // STATUS_H__
