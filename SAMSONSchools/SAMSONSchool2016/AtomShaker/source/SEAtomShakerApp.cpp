#include "SEAtomShakerApp.hpp"
#include "SEAtomShakerAppGUI.hpp"

SEAtomShakerApp::SEAtomShakerApp() {

	setGUI(new SEAtomShakerAppGUI(this));
	getGUI()->loadDefaultSettings();

}

SEAtomShakerApp::~SEAtomShakerApp() {

	getGUI()->saveDefaultSettings();
	delete getGUI();

}

SEAtomShakerAppGUI* SEAtomShakerApp::getGUI() const { return static_cast<SEAtomShakerAppGUI*>(SBDApp::getGUI()); }
