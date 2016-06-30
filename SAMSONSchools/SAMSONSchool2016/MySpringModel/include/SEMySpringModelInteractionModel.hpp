#pragma once 

#include "SBMInteractionModelParticleSystem.hpp"

#include "SBBaseEvent.hpp"
#include "SBDocumentEvent.hpp"
#include "SBStructuralEvent.hpp"
#include "SBAtom.hpp"


/// This class implements an interaction model

class SEMySpringModelInteractionModel : public SBMInteractionModelParticleSystem {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	SEMySpringModelInteractionModel();																													///< Builds an interaction model					
	SEMySpringModelInteractionModel(SBParticleSystem* particleSystem);																					///< Builds an interaction model 
	virtual ~SEMySpringModelInteractionModel();																											///< Destructs the interaction model

	//@}

	/// \name Serialization
	//@{

	virtual void												serialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer) const;		///< Serializes the node
	virtual void												unserialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer);			///< Unserializes the node

	//@}

	/// \name Topology
	//@{

	virtual	void												eraseImplementation();																///< Erases the interaction model

	//@}

	/// \name Interactions									
	//@{

	virtual void												initializeInteractions();												///< Initializes the interaction model
	virtual void												updateInteractions();													///< Updates the interaction model

	//@}

	/// \name Rendering
	//@{

	virtual void												display();																///< Displays the interaction model
	virtual void												displayForShadow();														///< Displays the interaction model for shadow purposes
	virtual void												displayForSelection();													///< Displays the interaction model for selection purposes

	virtual void												expandBounds(SBIAPosition3& bounds) const;								///< Expands the bounds to make sure the interaction model fits inside them

	virtual void												collectAmbientOcclusion(const SBPosition3& boxOrigin, const SBPosition3& boxSize, unsigned int nCellsX, unsigned int nCellsY, unsigned int nCellsZ, float* ambientOcclusionData);		///< To collect ambient occlusion data

	//@}

	/// \name Events
	//@{

	virtual void												onBaseEvent(SBBaseEvent* baseEvent);									///< Handles base events
	virtual void												onDynamicalEvent(SBDynamicalEvent* dynamicalEvent);						///< Handles dynamical events
	virtual void												onDocumentEvent(SBDocumentEvent* documentEvent);						///< Handles document events
	virtual void												onStructuralEvent(SBStructuralEvent* documentEvent);					///< Handles structural events

	//@}

	SBPointerIndex<SBStructuralParticle> const*					particleIndex;
	SBVector<SBQuantity::length>*								springLengthVector;
	SBVector<SBAtom*>*											springAtomIVector;
	SBVector<SBAtom*>*											springAtomJVector;

};


SB_REGISTER_TARGET_TYPE(SEMySpringModelInteractionModel, "SEMySpringModelInteractionModel", "FEF82B79-9B24-0836-E7AD-9BA7C2D0280E");
SB_DECLARE_BASE_TYPE(SEMySpringModelInteractionModel, SBMInteractionModelParticleSystem);
