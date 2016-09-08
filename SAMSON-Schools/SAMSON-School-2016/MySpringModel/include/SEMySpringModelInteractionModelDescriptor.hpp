/// \headerfile SBProxy.hpp "SBProxy.hpp"
#include "SBProxy.hpp"

/// \headerfile SEMySpringModelInteractionModel.hpp "SEMySpringModelInteractionModel.hpp"
#include "SEMySpringModelInteractionModel.hpp"


// Class descriptor

// SAMSON Element generator pro tip: complete this descriptor to expose this class to SAMSON and other SAMSON Elements

SB_CLASS_BEGIN(SEMySpringModelInteractionModel);

	SB_CLASS_TYPE(SBCClass::InteractionModelParticleSystem);
	SB_CLASS_DESCRIPTION("My Spring Model");

	SB_FACTORY_BEGIN;

		SB_CONSTRUCTOR_0(SEMySpringModelInteractionModel);
		SB_CONSTRUCTOR_1(SEMySpringModelInteractionModel, SBParticleSystem*);

	SB_FACTORY_END;

	SB_INTERFACE_BEGIN;

	SB_INTERFACE_END;

SB_CLASS_END(SEMySpringModelInteractionModel);

