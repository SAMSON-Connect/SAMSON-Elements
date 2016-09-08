#include "SEAtomShakerAppGUI.hpp"
#include "SEAtomShakerApp.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"
#include "SBRandom.hpp"

SEAtomShakerAppGUI::SEAtomShakerAppGUI( SEAtomShakerApp* t ) : SBGApp( t ) {

	ui.setupUi( this );

}

SEAtomShakerAppGUI::~SEAtomShakerAppGUI() {

}

SEAtomShakerApp* SEAtomShakerAppGUI::getApp() const { return static_cast<SEAtomShakerApp*>(SBGApp::getApp()); }

void SEAtomShakerAppGUI::loadSettings( SBGSettings *settings ) {

	if ( settings == NULL ) return;
	
	// SAMSON Element generator pro tip: complete this function so your app can save its GUI state from one session to the next

}

void SEAtomShakerAppGUI::saveSettings( SBGSettings *settings ) {

	if ( settings == NULL ) return;

	// SAMSON Element generator pro tip: complete this function so your app can save its GUI state from one session to the next

}

SBCContainerUUID SEAtomShakerAppGUI::getUUID() const { return SBCContainerUUID( "CEA242A3-2C62-BCC3-C3E8-1C78319FBCD5" );}

QPixmap SEAtomShakerAppGUI::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your app.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SEAtomShakerAppIcon.png"));

}

QString SEAtomShakerAppGUI::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your app inside SAMSON

	return "Atom shaker"; 

}

int SEAtomShakerAppGUI::getFormat() const { 
	
	// SAMSON Element generator pro tip: modify these default settings if you want more options (see the documentation of SBGWindow)
	
	return (SBGWindow::Savable | SBGWindow::Resizable);

}

void SEAtomShakerAppGUI::onShakeAtoms() {

	SBNodePredicate* nodePredicate = SAMSON::makeNodePredicate("n.t a");

	SBNodeIndexer nodeIndexer;
	SAMSON::getActiveDocument()->getNodes(nodeIndexer, *nodePredicate);

	SBRandom randomGenerator(SAMSON::getTime());

	SAMSON::beginHolding("Shake atoms");
	
	SB_FOR(SBNode* node, nodeIndexer) {

		SBAtom* atom = static_cast<SBAtom*>(node);
		SBPosition3 position = atom->getPosition();

		position.v[0] += SBQuantity::angstrom(randomGenerator.randDouble1() - 0.5);
		position.v[1] += SBQuantity::angstrom(randomGenerator.randDouble1() - 0.5);
		position.v[2] += SBQuantity::angstrom(randomGenerator.randDouble1() - 0.5);

		atom->setPosition(position);

	}
	
	SAMSON::endHolding();

	delete nodePredicate;

}

