/*
 *  ofxClutterActor.cpp
 *  clutterExample
 *
 *  Created by Jeffrey Crouse on 1/28/11.
 *  Copyright 2011 Eyebeam. All rights reserved.
 *
 */

#include "ofxClutterActor.h"

// We need access to the stage
extern "C" {
#include "ofxAppClutterWindow.h"
};



void ofxClutterActor::setPosition(int x, int y) {
	clutter_actor_set_position(actor, x, y);
}

void ofxClutterActor::setAnchor(int x, int y) {
	clutter_actor_set_anchor_point(actor, x, y);
}

void ofxClutterActor::setAnchorCenter() {
	setAnchor(getWidth()/2.0, getHeight()/2.0);
}

float ofxClutterActor::getWidth() {
	gfloat width=0;
	gfloat height=0;
	clutter_actor_get_size(actor, &width, &height);
	return width;
}

float ofxClutterActor::getHeight() {
	gfloat width, height;
	clutter_actor_get_size(actor, &width, &height);
	return height;
}

void ofxClutterActor::setSize(int w, int h) {
	clutter_actor_set_size(actor, w, h);
}

void ofxClutterActor::setZRotation(float angle) {
	clutter_actor_set_rotation(actor, CLUTTER_Z_AXIS, angle, 0, 0, 0);
}
