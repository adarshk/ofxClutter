#include "ofMain.h"
#include "testApp.h"
#include "ofAppClutterWindow.h"



//========================================================================
int main(int argc, char *argv[]){
	
	ofAppClutterWindow* window;
	window = new ofAppClutterWindow(argc, argv);
	ofSetupOpenGL(window, 1024,768, OF_WINDOW);			// <-------- setup the GL context
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp() );
	
}
