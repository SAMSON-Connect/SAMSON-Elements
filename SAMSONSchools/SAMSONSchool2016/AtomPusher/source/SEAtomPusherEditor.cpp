#include "SEAtomPusherEditor.hpp"
#include "SAMSON.hpp"


SEAtomPusherEditor::SEAtomPusherEditor() {

	// SAMSON Element generator pro tip: this default constructor is called when unserializing the node, so it should perform all default initializations.

	propertyWidget = new SEAtomPusherEditorGUI(this);
	propertyWidget->loadDefaultSettings();
	SAMSON::addWidget(propertyWidget);

	activeSphere = false;
	sphereRadius = SBQuantity::angstrom(2.0);
	spherePosition = SBPosition3();

	SAMSON::requestViewportUpdate();

}

SEAtomPusherEditor::~SEAtomPusherEditor() {

	// SAMSON Element generator pro tip: disconnect from signals you might have connected to.

	propertyWidget->saveDefaultSettings();
	delete propertyWidget;

}

SEAtomPusherEditorGUI* SEAtomPusherEditor::getPropertyWidget() const { return static_cast<SEAtomPusherEditorGUI*>(propertyWidget); }

SBCContainerUUID SEAtomPusherEditor::getUUID() const { return SBCContainerUUID("B2C92126-6231-98D6-C59F-49FCD78810DA"); }

QString SEAtomPusherEditor::getName() const { 

	// SAMSON Element generator pro tip: this name should not be changed

	return "SEAtomPusherEditor"; 

}

QString SEAtomPusherEditor::getText() const { 
	
	// SAMSON Element generator pro tip: modify this function to return a user-friendly string that will be displayed in menus

	return QObject::tr("SEAtomPusherEditor"); 

}

QPixmap SEAtomPusherEditor::getLogo() const {

	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your editor.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/Icons/SEAtomPusherEditorIcon.png"));

}

QKeySequence SEAtomPusherEditor::getShortcut() const { 
	
	// SAMSON Element generator pro tip: modify this function to associate a tentative shortcut to your editor

	return QKeySequence(""); 

}

QString SEAtomPusherEditor::getToolTip() const { 
	
	// SAMSON Element generator pro tip: modify this function to have your editor display a tool tip in the SAMSON GUI when the mouse hovers the editor's icon

	return QObject::tr("SAMSON Element generator pro tip: modify me"); 

}

void SEAtomPusherEditor::beginEditing() {

	// SAMSON Element generator pro tip: SAMSON calls this function when your editor becomes active. 
	// Implement this function if you need to prepare some data structures in order to be able to handle GUI or SAMSON events.

}

void SEAtomPusherEditor::endEditing() {

	// SAMSON Element generator pro tip: SAMSON calls this function immediately before your editor becomes inactive (for example when another editor becomes active). 
	// Implement this function if you need to clean some data structures.
	
}

void SEAtomPusherEditor::display() {

	// SAMSON Element generator pro tip: this function is called by SAMSON during the main rendering loop. 
	// Implement this function to display things in SAMSON, for example thanks to the utility functions provided by SAMSON (e.g. displaySpheres, displayTriangles, etc.)
	

		float position[3];
		float radius[1];
		float color[4];
		unsigned int flag[1];

		position[0] = spherePosition[0].getValue();
		position[1] = spherePosition[1].getValue();
		position[2] = spherePosition[2].getValue();

		radius[0] = sphereRadius.getValue();

		if (activeSphere){
			color[0] = 1.f;
			color[1] = 1.f;
			color[2] = 1.f;
			color[3] = 1.f;
		}
		else {
			color[0] = 0.f;
			color[1] = 1.f;
			color[2] = 0.f;
			color[3] = 1.f;

		}

		flag[0] = 0;

		SAMSON::displaySpheres(1, position, radius, color, flag);
	
}

void SEAtomPusherEditor::displayForShadow() {

	// SAMSON Element generator pro tip: this function is called by SAMSON during the main rendering loop in order to compute shadows. 
	// Implement this function if your editor displays things in viewports, so that your editor can cast shadows
	// to other objects in SAMSON, for example thanks to the utility
	// functions provided by SAMSON (e.g. displaySpheres, displayTriangles, etc.)

}

void SEAtomPusherEditor::displayInterface() {

	// SAMSON Element generator pro tip: this function is called by SAMSON during the main rendering loop in order to display the editor 2D interface in viewports. 
	// Implement this function if your editor displays a 2D user interface. For example, a rectangle selection editor would display a 2D rectangle in the active viewport. 
	// You may use utility functions provided by SAMSON (e.g. displayLinesOrtho and displayTrianglesOrtho).

}

void SEAtomPusherEditor::mousePressEvent(QMouseEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

	if (event->button() == Qt::MouseButton::LeftButton){
		activeSphere = true;
		SAMSON::requestViewportUpdate();
	}

}

void SEAtomPusherEditor::mouseReleaseEvent(QMouseEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

	if (event->button() == Qt::MouseButton::LeftButton){
		activeSphere = false;
		SAMSON::requestViewportUpdate();
	}
}

void SEAtomPusherEditor::mouseMoveEvent(QMouseEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

	SBPosition3 nodePosition;
	SBNode* pickedNode = SAMSON::getNode(event->pos(), nodePosition);

	if (pickedNode == NULL){

		spherePosition = SAMSON::getWorldPositionFromViewportPosition(event->pos());
	}
	else {

		spherePosition = SAMSON::getWorldPositionFromViewportPosition(event->pos(),
			nodePosition);
	}
	
	SAMSON::requestViewportUpdate();

	if (activeSphere){
		SBNodeIndexer nodeIndexer;
		SAMSON::getActiveDocument()->getNodes(nodeIndexer, SBNode::IsType(SBNode::Atom));

		SB_FOR(SBNode * node, nodeIndexer){
			SBAtom* atom = (SBAtom *)node;
			SBPosition3 atomPosition = atom->getPosition();
			SBPosition3 vectorFromSphereCenter = atomPosition - spherePosition;
			if (vectorFromSphereCenter.norm() < sphereRadius){
				vectorFromSphereCenter = vectorFromSphereCenter * (sphereRadius / vectorFromSphereCenter.norm());
				atom->setPosition(spherePosition + vectorFromSphereCenter);
			}
		}
	}

}

void SEAtomPusherEditor::mouseDoubleClickEvent(QMouseEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

}

void SEAtomPusherEditor::wheelEvent(QWheelEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

	int angle = event->delta();
	sphereRadius = sphereRadius * pow(1.002, angle);
	SAMSON::requestViewportUpdate();

}

void SEAtomPusherEditor::keyPressEvent(QKeyEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

}

void SEAtomPusherEditor::keyReleaseEvent(QKeyEvent* event) {

	// SAMSON Element generator pro tip: SAMSON redirects Qt events to the active editor. 
	// Implement this function to handle this event with your editor.

}

void SEAtomPusherEditor::onBaseEvent(SBBaseEvent* baseEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle base events

}

void SEAtomPusherEditor::onDocumentEvent(SBDocumentEvent* documentEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle document events 

}

void SEAtomPusherEditor::onDynamicalEvent(SBDynamicalEvent* dynamicalEvent) {

	// SAMSON Element generator pro tip: implement this function if you need to handle dynamical events 

}

void SEAtomPusherEditor::onStructuralEvent(SBStructuralEvent* documentEvent) {
	
	// SAMSON Element generator pro tip: implement this function if you need to handle structural events

}
