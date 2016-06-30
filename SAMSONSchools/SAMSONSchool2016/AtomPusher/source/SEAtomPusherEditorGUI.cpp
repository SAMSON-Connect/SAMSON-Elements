#include "SEAtomPusherEditorGUI.hpp"
#include "SEAtomPusherEditor.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"

SEAtomPusherEditorGUI::SEAtomPusherEditorGUI(SEAtomPusherEditor* editor) {

	ui.setupUi( this );
	this->editor = editor;

}

SEAtomPusherEditorGUI::~SEAtomPusherEditorGUI() {

}

SEAtomPusherEditor* SEAtomPusherEditorGUI::getEditor() const { return editor; }

void SEAtomPusherEditorGUI::loadSettings( SBGSettings *settings ) {

	if ( settings == NULL ) return;
	
	// SAMSON Element generator pro tip: complete this function so your editor can save its GUI state from one session to the next

}

void SEAtomPusherEditorGUI::saveSettings( SBGSettings *settings ) {

	if ( settings == NULL ) return;

	// SAMSON Element generator pro tip: complete this function so your editor can save its GUI state from one session to the next

}

SBCContainerUUID SEAtomPusherEditorGUI::getUUID() const { return SBCContainerUUID( "2032D1AD-5A27-E991-5A27-248BBDD0F742" );}

QPixmap SEAtomPusherEditorGUI::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your editor.

	return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/Resource/icons/SEAtomPusherEditorIcon.png"));

}

QString SEAtomPusherEditorGUI::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your editor inside SAMSON

	return "SEAtomPusherEditor"; 

}

int SEAtomPusherEditorGUI::getFormat() const { 
	
	// SAMSON Element generator pro tip: modify these default settings if you want more options (see the documentation of SBGWindow)
	
	return (SBGWindow::Lockable);

}
