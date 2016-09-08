/// \headerfile SBProxy.hpp "SBProxy.hpp"
#include "SBProxy.hpp"

/// \headerfile SEMySpringModelInteractionModelProperties.hpp "SEMySpringModelInteractionModelProperties.hpp"
#include "SEMySpringModelInteractionModelProperties.hpp"


// Class descriptor

// SAMSON Element generator pro tip: complete this descriptor to expose this class to SAMSON and other SAMSON Elements

SB_CLASS_BEGIN(SEMySpringModelInteractionModelProperties);

	SB_CLASS_TYPE(SBCClass::Properties);
	SB_CLASS_DESCRIPTION("My Spring Model");

	SB_FACTORY_BEGIN;

		SB_CONSTRUCTOR_0(SEMySpringModelInteractionModelProperties);

	SB_FACTORY_END;

	SB_INTERFACE_BEGIN;

	SB_INTERFACE_END;

SB_CLASS_END(SEMySpringModelInteractionModelProperties);

