#include "SEXYZImporterMain.hpp"
#include "SEXYZImporterMainGUI.hpp"

#include <fstream>
#include "SAMSON.hpp"
#include "SBStructuralModel.hpp"
#include "SBAtom.hpp"
#include "SBIFileReader.hpp"

SEXYZImporterMain::SEXYZImporterMain() {

	propertyDialog = new SEXYZImporterMainGUI(this);
	propertyDialog->loadDefaultSettings();

}

SEXYZImporterMain::~SEXYZImporterMain() {

	propertyDialog->saveDefaultSettings();
	delete propertyDialog;

}

std::string SEXYZImporterMain::getFilter() const { 
	
	// SAMSON Element generator pro tip: modify this function to return the filter of the importer

	return std::string("XYZ importer - SAMSON School 2016 (*.xyz)");

}

std::string SEXYZImporterMain::getName() const { 
	
	// SAMSON Element generator pro tip: modify this function to return a user-friendly name for the importer

	return std::string("XYZ importer - SAMSON School 2016");

}

bool SEXYZImporterMain::importFromFile(std::string &fileName, SBList<std::string>* parameters, SBDDocumentLayer* preferredLayer) {

	// get file lines

	std::vector<std::string> fileLineVector;
	SBIFileReader::getFileLines(fileName, fileLineVector);

	// read the number of atoms from the first line

	unsigned int numberOfAtoms = 0;
	std::stringstream numberOfAtomsParser(fileLineVector[0]);
	numberOfAtomsParser >> numberOfAtoms;

	// create a new model

	std::string name = fileLineVector[1];
	SBMStructuralModel* structuralModel = new SBMStructuralModel();
	structuralModel->setName(name);

	// read atoms
	int currentSerialNumber = 0;

	for (unsigned int i = 2; i<fileLineVector.size(); i++) {

		// parse the current line

		double x, y, z;
		std::string atomType;

		std::stringstream atomParser(fileLineVector[i]);

		atomParser >> atomType >> x >> y >> z;

		// add a new atom to the model

		SBElement::Type element = SAMSON::getElementTypeBySymbol(atomType);
		if (element != SBElement::Unknown) {

			SBAtom* newAtom = new SBAtom(element, SBQuantity::angstrom(x), SBQuantity::angstrom(y), SBQuantity::angstrom(z));
			newAtom->setSerialNumber(currentSerialNumber++);
			structuralModel->getStructuralRoot()->addChild(newAtom);

		}

	}

	if (static_cast<SEXYZImporterMainGUI*>(propertyDialog)->ui.checkBox->isChecked())
		structuralModel->createCovalentBonds();

	SAMSON::beginHolding("Add model");
	structuralModel->create();
	preferredLayer->addChild(structuralModel);
	SAMSON::endHolding();

	return true;

}

