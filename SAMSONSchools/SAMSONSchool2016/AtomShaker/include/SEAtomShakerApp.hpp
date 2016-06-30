#pragma once 

#include "SBDApp.hpp"
#include "SEAtomShakerAppGUI.hpp"


/// This class implements the functionality of the app

// SAMSON Element generator pro tip: add non-GUI functionality in this class. The GUI functionality should go in the SEAtomShakerAppGUI class

class SEAtomShakerApp : public SBDApp {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	SEAtomShakerApp();																													///< Constructs an app
	virtual ~SEAtomShakerApp();																											///< Destructs the app

	//@}

	/// \name GUI
	//@{

	SEAtomShakerAppGUI*											getGUI() const;															///< Returns a pointer to the GUI of the app

	//@}

};


SB_REGISTER_TARGET_TYPE(SEAtomShakerApp, "SEAtomShakerApp", "A8F570CC-848D-F1C9-63A9-EBC4F0020C16");
SB_DECLARE_BASE_TYPE(SEAtomShakerApp, SBDApp);
