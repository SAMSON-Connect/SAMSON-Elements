#pragma once 

#include "SBDApp.hpp"
#include "SECenterOfMassAppGUI.hpp"
#include "SBAtom.hpp"


/// This class implements the functionality of the app

// SAMSON Element generator pro tip: add non-GUI functionality in this class. The GUI functionality should go in the SECenterOfMassAppGUI class

class SECenterOfMassApp : public SBDApp {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	SECenterOfMassApp();																													///< Constructs an app
	virtual ~SECenterOfMassApp();																											///< Destructs the app

	//@}

	/// \name GUI
	//@{

	SECenterOfMassAppGUI*											getGUI() const;															///< Returns a pointer to the GUI of the app

	//@}

	void computeCenterOfMass();

	SBPointerIndex<SBAtom> atomIndexer;

	void onStructuralEvent(SBStructuralEvent* event);

	SBPosition3 centerOfMass;
	SBPosition3* positionArray;

};


SB_REGISTER_TARGET_TYPE(SECenterOfMassApp, "SECenterOfMassApp", "3575CAD7-02E8-AAF9-60EB-FE1CAE5CCC1D");
SB_DECLARE_BASE_TYPE(SECenterOfMassApp, SBDApp);
