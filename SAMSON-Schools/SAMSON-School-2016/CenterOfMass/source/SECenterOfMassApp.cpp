#include "SECenterOfMassApp.hpp"
#include "SECenterOfMassAppGUI.hpp"
#include "SAMSON.hpp"


SECenterOfMassApp::SECenterOfMassApp() {

	setGUI(new SECenterOfMassAppGUI(this));
	getGUI()->loadDefaultSettings();

	positionArray = 0;

}

SECenterOfMassApp::~SECenterOfMassApp() {

	getGUI()->saveDefaultSettings();
	delete getGUI();

}

SECenterOfMassAppGUI* SECenterOfMassApp::getGUI() const { return static_cast<SECenterOfMassAppGUI*>(SBDApp::getGUI()); }

void SECenterOfMassApp::computeCenterOfMass() {

	// get selected nodes

	SBPointerIndex<SBNode> const* selectedNodes =
		SAMSON::getActiveDocument()->getSelectedNodes();

	// find atoms

	SBNodeIndexer temporaryIndexer;
	SB_FOR(SBNode* node, *selectedNodes)
		node->getNodes(temporaryIndexer, SBNode::IsType(SBNode::Atom));

	// disconnect from atoms

	if (positionArray) delete[] positionArray;

	SB_FOR(SBAtom* atom, atomIndexer)
		atom->disconnectStructuralSignalFromSlot(this,
		SB_SLOT(&SECenterOfMassApp::onStructuralEvent));

	// store pointers to atoms

	atomIndexer.clear();
	SB_FOR(SBNode* node, temporaryIndexer) atomIndexer.addReferenceTarget(node);

	// connect to atoms

	positionArray = new SBPosition3[atomIndexer.size()];
	SB_FOR(SBAtom* atom, atomIndexer)
		positionArray[atomIndexer.getIndex(atom)] = atom->getPosition();

	//for (unsigned int i = 0; i < atomIndexer.size(); i++)
	//	positionArray[i] = atomIndexer[i]->getPosition();

	SB_FOR(SBAtom* atom, atomIndexer)
		atom->connectStructuralSignalToSlot(this,
		SB_SLOT(&SECenterOfMassApp::onStructuralEvent));

	// compute the center of mass

	if (!atomIndexer.size()) return;

	centerOfMass.setZero();

	SB_FOR(SBAtom* atom, atomIndexer)
		centerOfMass += atom->getPosition();

	centerOfMass /= (double)atomIndexer.size();
	
	// display the center of mass

	getGUI()->updateCenterOfMass(centerOfMass);

}

void SECenterOfMassApp::onStructuralEvent(SBStructuralEvent* event) {

	if (event->getType() == SBStructuralEvent::ParticlePositionChanged) {

		SBAtom* atom = static_cast<SBAtom*>(event->getSender());

		// get the index of the atom in the atom indexer

		unsigned int atomIndex = atomIndexer.getIndex(atom);

		// subtract the old position

		centerOfMass -= (positionArray[atomIndex] / atomIndexer.size());

		// add the new position

		centerOfMass += (atom->getPosition() / atomIndexer.size());

		// store the new position

		positionArray[atomIndex] = atom->getPosition();

		// display the center of mass

		getGUI()->updateCenterOfMass(centerOfMass);

	}

}
