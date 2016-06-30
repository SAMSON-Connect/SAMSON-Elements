#pragma once


#include "SBGFileImporter.hpp" 
#include "ui_SEXYZImporterMainGUI.h"

class SEXYZImporterMain;

/// This class implements the GUI of the importer

// SAMSON Element generator pro tip: add GUI functionality in this class. The non-GUI functionality should go in the SEXYZImporterMain class

class SEXYZImporterMainGUI : public SBGFileImporter {

	Q_OBJECT

public:

	friend class SEXYZImporterMain;

	/// \name Constructors and destructors
	//@{

	SEXYZImporterMainGUI(SEXYZImporterMain* t);																			///< Constructs a GUI for the importer
	~SEXYZImporterMainGUI();																												///< Destructs the GUI of the importer

	//@}

	/// \name Importer
	//@{

	SEXYZImporterMain*												getImporter() const;													///< Returns a pointer to the importer

	//@}

	/// \name Identity
	//@{

	virtual SBCContainerUUID									getUUID() const;														///< Returns the widget UUID
	virtual QString												getName() const;														///< Returns the widget name (used as a title for the embedding window)
	virtual QPixmap												getLogo() const;														///< Returns the widget logo
	int															getFormat() const;														///< Returns the widget format

	//@}

	///\name Settings
	//@{

	void														loadSettings(SBGSettings* settings);										///< Load GUI settings
	void														saveSettings(SBGSettings* settings);										///< Save GUI settings

	//@}

	Ui::SEXYZImporterMainGUIClass									ui;

};

