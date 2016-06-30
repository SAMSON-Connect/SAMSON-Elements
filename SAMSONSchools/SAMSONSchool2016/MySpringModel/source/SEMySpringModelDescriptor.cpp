/// \headerfile SEMySpringModelInteractionModelDescriptor.hpp "SEMySpringModelInteractionModelDescriptor.hpp"
#include "SEMySpringModelInteractionModelDescriptor.hpp"

/// \headerfile SEMySpringModelInteractionModelPropertiesDescriptor.hpp "SEMySpringModelInteractionModelPropertiesDescriptor.hpp"
#include "SEMySpringModelInteractionModelPropertiesDescriptor.hpp"



// Describe the SAMSON Element

// SAMSON Element generator pro tip: modify the information below if necessary
// (for example when a new class is added, when the version number changes, to describe categories more precisely, etc.)

SB_ELEMENT_DESCRIPTION("A Force field where all the atoms connected by bonds interact with a spring like behavior");
SB_ELEMENT_DOCUMENTATION("Resource/Documentation/doc.html");
SB_ELEMENT_VERSION("0.5.0");

SB_ELEMENT_CLASSES_BEGIN;

	SB_ELEMENT_CLASS(SEMySpringModelInteractionModel);
	SB_ELEMENT_CLASS(SEMySpringModelInteractionModelProperties);

SB_ELEMENT_CLASSES_END;

SB_ELEMENT_CATEGORIES_BEGIN;

	SB_ELEMENT_CATEGORY(SBClass::Category::General);

SB_ELEMENT_CATEGORIES_END;
