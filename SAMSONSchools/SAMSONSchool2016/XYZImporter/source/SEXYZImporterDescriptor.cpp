/// \headerfile SEXYZImporterMainDescriptor.hpp "SEXYZImporterMainDescriptor.hpp"
#include "SEXYZImporterMainDescriptor.hpp"



// Describe the SAMSON Element

// SAMSON Element generator pro tip: modify the information below if necessary
// (for example when a new class is added, when the version number changes, to describe categories more precisely, etc.)

SB_ELEMENT_DESCRIPTION("This SAMSON Element contains an importer able to parse xyz files.");
SB_ELEMENT_DOCUMENTATION("Resource/Documentation/doc.html");
SB_ELEMENT_VERSION("0.5.0");

SB_ELEMENT_CLASSES_BEGIN;

	SB_ELEMENT_CLASS(SEXYZImporterMain);

SB_ELEMENT_CLASSES_END;

SB_ELEMENT_CATEGORIES_BEGIN;

	SB_ELEMENT_CATEGORY(SBClass::Category::General);

SB_ELEMENT_CATEGORIES_END;
