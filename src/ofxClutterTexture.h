/*
 *  ofxClutterTexture.h
 *  clutterExample
 *
 *  Created by Jeffrey Crouse on 1/28/11.
 *  Copyright 2011 Eyebeam. All rights reserved.
 *
 */

#pragma once
#include "ofxClutterActor.h"


class ofxClutterTexture : public ofxClutterActor {
public:
	ofxClutterTexture();
	
	bool loadImage(string path) {
		path = ofToDataPath(path, true);
		cout << "loading: " << path << endl;
		GError *error=NULL;
		bool success;
		success = clutter_texture_set_from_file(CLUTTER_TEXTURE(actor), path.c_str(), &error);
		if(!success) {
			ofLog(OF_LOG_ERROR, "Couldn't load image.");
			fprintf (stderr, "Unable to read file: %s\n", error->message);
			return false;
		}
		return true;
	}
};