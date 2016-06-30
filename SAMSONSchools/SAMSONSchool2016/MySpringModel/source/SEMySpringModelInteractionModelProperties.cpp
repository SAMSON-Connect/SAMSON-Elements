#include "SEMySpringModelInteractionModelProperties.hpp"
#include "SEMySpringModelInteractionModel.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"

SEMySpringModelInteractionModelProperties::SEMySpringModelInteractionModelProperties() {

	interactionModel = 0;
	ui.setupUi( this );
	observer = new Observer(this);

}

SEMySpringModelInteractionModelProperties::~SEMySpringModelInteractionModelProperties() {

	if (!interactionModel.isValid()) return;

	interactionModel->disconnectBaseSignalFromSlot(observer(), SB_SLOT(&SEMySpringModelInteractionModelProperties::Observer::onBaseEvent));
	interactionModel->disconnectInteractionSignalFromSlot(observer(), SB_SLOT(&SEMySpringModelInteractionModelProperties::Observer::onInteractionEvent));

}

void SEMySpringModelInteractionModelProperties::loadSettings( SBGSettings *settings ) {

	if ( settings == 0 ) return;
	
	// SAMSON Element generator pro tip: complete this function so this property window can save its GUI state from one session to the next

}

void SEMySpringModelInteractionModelProperties::saveSettings( SBGSettings *settings ) {

	if ( settings == 0 ) return;

	// SAMSON Element generator pro tip: complete this function so this property window can save its GUI state from one session to the next

}

SBCContainerUUID SEMySpringModelInteractionModelProperties::getUUID() const { return SBCContainerUUID( "DF9DB147-ABA6-E1C1-3189-A173048D3A9F" );}

QPixmap SEMySpringModelInteractionModelProperties::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your interaction model.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/Icons/SEMySpringModelInteractionModelPropertiesIcon.png"));

}

QString SEMySpringModelInteractionModelProperties::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your interaction model inside SAMSON

	return "My SpringModel"; 

}

int SEMySpringModelInteractionModelProperties::getFormat() const { 
	
	// SAMSON Element generator pro tip: modify these default settings if you want more options (see the documentation of SBGWindow)
	
	return (SBGWindow::Lockable);

}

bool SEMySpringModelInteractionModelProperties::setup() {

	SBNodeIndexer nodeIndexer;
	SB_FOR(SBNode* node, *SAMSON::getActiveDocument()->getSelectedNodes()) node->getNodes(nodeIndexer, SBNode::GetClass() == std::string("SEMySpringModelInteractionModel") && SBNode::GetElement() == std::string("SEMySpringModel") && SBNode::GetElementUUID() == SBUUID(SB_ELEMENT_UUID));

	if (nodeIndexer.size() == 1) {

		interactionModel = static_cast<SEMySpringModelInteractionModel*>((nodeIndexer)[0]);
		interactionModel->connectBaseSignalToSlot(observer(), SB_SLOT(&SEMySpringModelInteractionModelProperties::Observer::onBaseEvent));
		interactionModel->connectInteractionSignalToSlot(observer(), SB_SLOT(&SEMySpringModelInteractionModelProperties::Observer::onInteractionEvent));

		updateEnergies();

		return true;

	}

	return false;

}

bool SEMySpringModelInteractionModelProperties::setup(SBNode* node) {

	if (node->getProxy()->getName() != "SEMySpringModelInteractionModel") return false;
	if (node->getProxy()->getElement() != "SEMySpringModel") return false;
	if (node->getProxy()->getElementUUID() != SBUUID(SB_ELEMENT_UUID)) return false;

	interactionModel = static_cast<SEMySpringModelInteractionModel*>(node);
	interactionModel->connectBaseSignalToSlot(observer(), SB_SLOT(&SEMySpringModelInteractionModelProperties::Observer::onBaseEvent));
	interactionModel->connectInteractionSignalToSlot(observer(), SB_SLOT(&SEMySpringModelInteractionModelProperties::Observer::onInteractionEvent));

	updateEnergies();

	return true;

}

void SEMySpringModelInteractionModelProperties::updateEnergies() {

	ui.labelTotalEnergy->setText(QString(tr("Total energy: ")) + QString::fromStdString(SBQuantity::eV(interactionModel->getEnergy()).toStdString()));

}

SEMySpringModelInteractionModelProperties::Observer::Observer(SEMySpringModelInteractionModelProperties* properties) { this->properties = properties; }
SEMySpringModelInteractionModelProperties::Observer::~Observer() {}

void SEMySpringModelInteractionModelProperties::Observer::onBaseEvent(SBBaseEvent* baseEvent) {

	if (baseEvent->getType() == SBBaseEvent::NodeEraseBegin) properties->hide();

}

void SEMySpringModelInteractionModelProperties::Observer::onInteractionEvent(SBInteractionEvent* interactionEvent) {

	if (interactionEvent->getType() == SBInteractionEvent::InteractionModelChanged) properties->updateEnergies();

}
