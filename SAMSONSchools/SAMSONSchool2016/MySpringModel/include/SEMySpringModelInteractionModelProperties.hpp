#pragma once


#include "SBGDataGraphNodeProperties.hpp" 
#include "ui_SEMySpringModelInteractionModelProperties.h"
#include "SBPointer.hpp"
#include "SEMySpringModelInteractionModel.hpp"


/// This class implements the GUI of the interaction model

// SAMSON Element generator pro tip: add GUI functionality in this class. The non-GUI functionality should go in the SEMySpringModelInteractionModel class

class SEMySpringModelInteractionModelProperties : public SBGDataGraphNodeProperties {

	SB_CLASS
	Q_OBJECT

public:

	/// \name Constructors and destructors
	//@{

	SEMySpringModelInteractionModelProperties();																								///< Constructs a widget to show the properties of the interaction model
	virtual ~SEMySpringModelInteractionModelProperties();																						///< Destructs the widget

	//@}

	/// \name Identity
	//@{

	virtual SBCContainerUUID									getUUID() const;														///< Returns the widget UUID
	virtual QString												getName() const;														///< Returns the widget name (used as a title for the embedding window)
	virtual QPixmap												getLogo() const;														///< Returns the widget logo
	int															getFormat() const;														///< Returns the widget format

	//@}

	///\name Settings
	//@{

	void														loadSettings(SBGSettings* settings);									///< Load GUI settings
	void														saveSettings(SBGSettings* settings);									///< Save GUI settings

	//@}

	///\name Setup
	//@{

	virtual bool												setup();																///< Initializes the properties widget
	virtual bool												setup(SBNode* node);													///< Initializes the properties widget

	//@}

	class Observer : public SBCReferenceTarget {

		Observer(SEMySpringModelInteractionModelProperties* properties);
		virtual ~Observer();

		friend class SEMySpringModelInteractionModelProperties;

		void														onBaseEvent(SBBaseEvent* baseEvent);									///< Base event management
		void														onInteractionEvent(SBInteractionEvent* interactionEvent);				///< Interaction event management

		SEMySpringModelInteractionModelProperties* properties;

	};

private:

	friend class SEMySpringModelInteractionModel;
	Ui::SEMySpringModelInteractionModelPropertiesClass							ui;
	SBPointer<SEMySpringModelInteractionModel>									interactionModel;

	void														updateEnergies();
	SBPointer<Observer>											observer;

};

SB_REGISTER_TYPE(SEMySpringModelInteractionModelProperties, "SEMySpringModelInteractionModelProperties", "5A5CBF79-1061-EE59-13D8-643E1827C71D");
