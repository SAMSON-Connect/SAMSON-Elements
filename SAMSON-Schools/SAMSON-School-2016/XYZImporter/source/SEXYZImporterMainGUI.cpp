#include "SEXYZImporterMainGUI.hpp"
#include "SEXYZImporterMain.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"
#include <QShortcut>

SEXYZImporterMainGUI::SEXYZImporterMainGUI( SEXYZImporterMain* t ) : SBGFileImporter( t ) {

	ui.setupUi( this );
	
	connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(accept()));
	connect(ui.pushButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));

	QShortcut *shortcutButtonYes1 = new QShortcut(Qt::Key_Enter, this);
	connect(shortcutButtonYes1, SIGNAL(activated()), ui.pushButtonOK, SLOT(click()));

	QShortcut *shortcutButtonYes2 = new QShortcut(Qt::Key_Return, this);
	connect(shortcutButtonYes2, SIGNAL(activated()), ui.pushButtonOK, SLOT(click()));

	QShortcut *shortcutButtonNo = new QShortcut(Qt::Key_Escape, this);
	connect(shortcutButtonNo, SIGNAL(activated()), ui.pushButtonCancel, SLOT(click()));

}

SEXYZImporterMainGUI::~SEXYZImporterMainGUI() {

}

SEXYZImporterMain* SEXYZImporterMainGUI::getImporter() const { return static_cast<SEXYZImporterMain*>(importer); }

void SEXYZImporterMainGUI::loadSettings( SBGSettings *settings ) {

	if ( settings == NULL ) return;
	
	// SAMSON Element generator pro tip: complete this function so your importer can save its GUI state from one session to the next

	ui.checkBox->setChecked(settings->loadBoolValue("createCovalentBonds", false));

}

void SEXYZImporterMainGUI::saveSettings( SBGSettings *settings ) {

	if ( settings == NULL ) return;

	// SAMSON Element generator pro tip: complete this function so your importer can save its GUI state from one session to the next

	settings->saveValue("createCovalentBonds", ui.checkBox->isChecked());

}

SBCContainerUUID SEXYZImporterMainGUI::getUUID() const { return SBCContainerUUID( "FC063231-FCB7-E7CE-35FD-E5F819C37133" );}

QPixmap SEXYZImporterMainGUI::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your importer.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SEXYZImporterMainIcon.png"));

}

QString SEXYZImporterMainGUI::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your importer inside SAMSON

	return "SEXYZImporterMain"; 

}

int SEXYZImporterMainGUI::getFormat() const { 
	
	// SAMSON Element generator pro tip: modify these default settings if you want more options (see the documentation of SBGWindow)
	
	return (SBGWindow::Lockable);

}
