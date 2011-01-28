/*
 *  ofxClutterTexture.cpp
 *  clutterExample
 *
 *  Created by Jeffrey Crouse on 1/28/11.
 *  Copyright 2011 Eyebeam. All rights reserved.
 *
 */

#include "ofxClutterTexture.h"

// We need access to the stage
extern "C" {
#include "ofxAppClutterWindow.h"
};


//------------------------------------------------------------
ofxClutterTexture::ofxClutterTexture() {
	actor = clutter_texture_new();
	clutter_container_add_actor(CLUTTER_CONTAINER(stage), actor);
	clutter_actor_show(actor);
}
