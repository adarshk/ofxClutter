/*
 *  ofAppClutterWindow.cpp
 *  openFrameworksLib
 *
 *  Created by Jeffrey Crouse on 1/26/11.
 *  Copyright 2011 Eyebeam. All rights reserved.
 *
 */

#include "ofAppClutterWindow.h"
#include "ofBaseApp.h"
#include "ofMain.h"

ClutterActor* stage;
ofBaseApp*	ofAppPtr;

ofAppClutterWindow::ofAppClutterWindow(int argc, char *argv[]){
	clutter_init(&argc, &argv);
}

void ofAppClutterWindow::setupOpenGL(int w, int h, int screenMode) {
	ClutterColor stage_color = { 200, 200, 200, 255 };
	
	stage = clutter_stage_get_default();
	clutter_actor_set_size(stage, w, h);
	clutter_stage_set_color(CLUTTER_STAGE(stage), &stage_color);

}

void ofAppClutterWindow::initializeWindow() {
	clutter_actor_show(stage);
}

void ofAppClutterWindow::runAppViaInfiniteLoop(ofBaseApp * appPtr) {
	
	ofAppPtr = appPtr;
	
	if(ofAppPtr){
		ofAppPtr->setup();
		ofAppPtr->update();
	}
	
	clutter_main();
}