/*
 *  ofxClutterActor.h
 *  clutterExample
 *
 *  Created by Jeffrey Crouse on 1/28/11.
 *  Copyright 2011 Eyebeam. All rights reserved.
 *
 */

#pragma once
#include "ofMain.h"
#include <clutter/clutter.h>

class ofxClutterActor {
public:
	
	void setPosition(int x, int y);
	void setAnchor(int x, int y);
	void setAnchorCenter();
	float getWidth();
	float getHeight();
	void setSize(int w, int h);
	void setZRotation(float angle);
	
//protected:
	ClutterActor *actor;
};