#pragma once 

#include "SBMVisualModel.hpp"

#include "SBBaseEvent.hpp"
#include "SBDocumentEvent.hpp"
#include "SBStructuralEvent.hpp"
#include "SBAtom.hpp"


/// This class implements a visual model

class SEVanDerWaalsVisualModel : public SBMVisualModel {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	SEVanDerWaalsVisualModel();																													///< Builds a visual model					
	SEVanDerWaalsVisualModel(const SBNodeIndexer& nodeIndexer);																			///< Builds a visual model 
	SEVanDerWaalsVisualModel(std::vector<SBDDataGraphNode*>& nodeVector);																			///< Builds a visual model 
	virtual ~SEVanDerWaalsVisualModel();																											///< Destructs the visual model

	//@}

	/// \name Serialization
	//@{

	virtual void												serialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer) const;		///< Serializes the node
	virtual void												unserialize(SBCSerializer* serializer, const SBNodeIndexer& nodeIndexer);			///< Unserializes the node

	//@}

	virtual void												getNodes(SBNodeIndexer& nodeIndexer, const SBNodePredicate& selectionPredicate = SBDDataGraphNode::All(), const SBNodePredicate& visitPredicate = SBDDataGraphNode::All());																						///< Returns some nodes

	/// \name Topology
	//@{

	virtual	void												eraseImplementation();																///< Erases the visual model

	//@}

	/// \name Rendering
	//@{

	virtual void												display();																///< Displays the visual model
	virtual void												displayForShadow();														///< Displays the visual model for shadow purposes
	virtual void												displayForSelection();													///< Displays the visual model for selection purposes

	virtual void												expandBounds(SBIAPosition3& bounds) const;								///< Expands the bounds to make sure the visual model fits inside them

	virtual void												collectAmbientOcclusion(const SBPosition3& boxOrigin, const SBPosition3& boxSize, unsigned int nCellsX, unsigned int nCellsY, unsigned int nCellsZ, float* ambientOcclusionData);		///< To collect ambient occlusion data

	//@}

	/// \name Events
	//@{

	virtual void												onBaseEvent(SBBaseEvent* baseEvent);									///< Handles base events
	virtual void												onDocumentEvent(SBDocumentEvent* documentEvent);						///< Handles document events
	virtual void												onStructuralEvent(SBStructuralEvent* documentEvent);					///< Handles structural events

	//@}

	SBPointerIndex<SBAtom>										atomIndexer;

};


SB_REGISTER_TARGET_TYPE(SEVanDerWaalsVisualModel, "SEVanDerWaalsVisualModel", "95BD2101-FBB6-AFF2-9257-B226430F05AF");
SB_DECLARE_BASE_TYPE(SEVanDerWaalsVisualModel, SBMVisualModel);
