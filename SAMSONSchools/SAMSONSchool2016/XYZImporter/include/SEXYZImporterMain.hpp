#pragma once 

#include "SBIFileImporter.hpp"
#include "SEXYZImporterMainGUI.hpp"


/// This class implements the functionality of the importer

// SAMSON Element generator pro tip: add non-GUI functionality in this class. The GUI functionality should go in the SEXYZImporterMainGUI class

class SEXYZImporterMain : public SBIFileImporter {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	SEXYZImporterMain();																													///< Constructs an importer
	virtual ~SEXYZImporterMain();																											///< Destructs the importer

	//@}

	/// \name Properties
	//@{

	virtual std::string											getFilter() const;														///< Returns the filter of the importer
	virtual std::string											getName() const;														///< Returns the name of the importer

	//@}

	/// \name Parsing
	//@{

	virtual bool												importFromFile(std::string &fileName, SBList<std::string>* parameters = 0, SBDDocumentLayer* preferredLayer = 0);			///< Imports data into SAMSON from a file

	//@}

};


SB_REGISTER_TARGET_TYPE(SEXYZImporterMain, "SEXYZImporterMain", "8191C653-4E90-235F-E93F-A320EBEC707E");
SB_DECLARE_BASE_TYPE(SEXYZImporterMain, SBIFileImporter);
