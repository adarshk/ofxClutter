/*
 *  ofClutterText.cpp
 *  clutterExample
 *
 *  Created by Jeffrey Crouse on 1/28/11.
 *  Copyright 2011 Eyebeam. All rights reserved.
 *
 */

#include "ofxClutterText.h"

// We need access to the stage
extern "C" {
#include "ofxAppClutterWindow.h"
};


//------------------------------------------------------------
ofxClutterText::ofxClutterText() {
	 actor = clutter_text_new();
	 clutter_container_add_actor(CLUTTER_CONTAINER(stage), actor);
	 clutter_actor_show(actor);
}