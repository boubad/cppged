#include "status.h"

namespace infoged {
	const string statusToString(status st)
	{
		switch (st)
		{
		case status::BadEntityDefinition:
			return "BadEntityDefinition";
		case status::BadLevelValue:
			return "BadLevelValue";
		case status::BadReferenceLocation:
			return "BadReferenceLocation";
		case status::ChangedData:
			return "ChangedData";
		case status::InconsistentData:
			return "InconsistentData";
		case status::IncorrectData:
			return "IncorrectData";
		case status::Inserted:
			return "Inserted";
		case status::InvalidId:
			return "InvalidId";
		case status::InvalidLevel:
			return "InvalidLevel";
		case status::InvalidTag:
			return "InvalidTag";
		case status::MissingChildren:
			return "MissingChildren";
		case status::MissingData:
			return "MissingData";
		case status::MissingFile:
			return "MissingFile";
		case status::MissingRecord:
			return "MissingRecord";
		case status::NntCompliantReference:
			return "NntCompliantReference";
		case status::NoValue:
			return "NoValue";
		case status::NonCompliant:
			return "NonCompliant";
		case status::Normal:
			return "Normal";
		case status::NotChanged:
			return "NotChanged";
		case status::NotCompliantId :
			return "NotCompliantId ";
		case status::NotCompliantLevel:
			return "NotCompliantLevel";
		case status::NotCompliantTag:
			return "NotCompliantTag";
		case status::NotReferenced:
			return "NotReferenced";
		case status::NotValid:
			return "NotValid";
		case status::Removed:
			return "Removed";
		case status::Transformed:
			return "Transformed";
		default:
			return "UnknownStatus";
		}
	}
} // namespace infoged