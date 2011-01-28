/*
 *  ofxClutterRect.h
 *  clutterExample
 *
 *  Created by Jeffrey Crouse on 1/28/11.
 *  Copyright 2011 Eyebeam. All rights reserved.
 *
 */

#pragma once
#include "ofxClutterActor.h"




class ofxClutterRect : public ofxClutterActor {
public:
	
	ofxClutterRect();
	
	ofxClutterRect(int r, int g, int b, int a) {
		ClutterColor col = {r, g, b, a };
		actor = clutter_rectangle_new_with_color(&col);
	}
	
	~ofxClutterRect() {
		// I think there is a clutter-specific way to get rid of actor
	}
	
	void setColor(int r, int g, int b, int a) {
		ClutterColor col = {r, g, b, a };
		clutter_rectangle_set_color(CLUTTER_RECTANGLE(actor), &col);
	}
	
	void setColor(string color) {
		/*
		 ClutterColor red = { 255, 0, 0, 128 };
		 ClutterColor green = { 0, 255, 0, 128 };
		 ClutterColor blue = { 0, 0, 255, 128 };
		 ClutterColor yellow = { 255, 255, 0, 128 };
		 ClutterColor cyan = { 0, 255, 255, 128 };
		 ClutterColor purple = { 255, 0, 255, 128 };	
		 */
	}
	
	void setBorder(int r, int g, int b, int a, int w) {
		ClutterColor col = {r, g, b, a};
		clutter_rectangle_set_border_color(CLUTTER_RECTANGLE(actor), &col);
		clutter_rectangle_set_border_width(CLUTTER_RECTANGLE(actor), w);
	}
	
};