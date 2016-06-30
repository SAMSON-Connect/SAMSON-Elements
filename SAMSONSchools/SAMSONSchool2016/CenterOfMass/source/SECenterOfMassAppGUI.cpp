#include "SECenterOfMassAppGUI.hpp"
#include "SECenterOfMassApp.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"

SECenterOfMassAppGUI::SECenterOfMassAppGUI( SECenterOfMassApp* t ) : SBGApp( t ) {

	ui.setupUi( this );

}

SECenterOfMassAppGUI::~SECenterOfMassAppGUI() {

}

SECenterOfMassApp* SECenterOfMassAppGUI::getApp() const { return static_cast<SECenterOfMassApp*>(SBGApp::getApp()); }

void SECenterOfMassAppGUI::loadSettings( SBGSettings *settings ) {

	if ( settings == NULL ) return;
	
	// SAMSON Element generator pro tip: complete this function so your app can save its GUI state from one session to the next

}

void SECenterOfMassAppGUI::saveSettings( SBGSettings *settings ) {

	if ( settings == NULL ) return;

	// SAMSON Element generator pro tip: complete this function so your app can save its GUI state from one session to the next

}

SBCContainerUUID SECenterOfMassAppGUI::getUUID() const { return SBCContainerUUID( "12645D70-68EF-0982-68F3-A3769D42D952" );}

QPixmap SECenterOfMassAppGUI::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your app.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SECenterOfMassAppIcon.png"));

}

QString SECenterOfMassAppGUI::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your app inside SAMSON

	return "Center of mass"; 

}

int SECenterOfMassAppGUI::getFormat() const { 
	
	// SAMSON Element generator pro tip: modify these default settings if you want more options (see the documentation of SBGWindow)
	
	return SBGWindow::Lockable;

}

void SECenterOfMassAppGUI::onComputeCenterOfMass() {

	getApp()->computeCenterOfMass();

}

void SECenterOfMassAppGUI::updateCenterOfMass(const SBPosition3& centerOfMass) {

	// convert to angstrom 
	// (else it will be in SBQuantity::length, which is picometers)

	SBQuantity::angstrom x = centerOfMass.v[0];
	SBQuantity::angstrom y = centerOfMass.v[1];
	SBQuantity::angstrom z = centerOfMass.v[2];

	// setup the label

	ui.label->setText(
		QString::fromStdString(x.toStdString()) + ", " +
		QString::fromStdString(y.toStdString()) + ", " +
		QString::fromStdString(z.toStdString())
		);

}