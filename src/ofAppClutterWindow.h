/*
 *  ofAppClutterWindow.h
 *  openFrameworksLib
 *
 *  Created by Jeffrey Crouse on 1/26/11.
 *  Copyright 2011 Eyebeam. All rights reserved.
 *
 */
#pragma once

#include "ofConstants.h"
#include "ofAppBaseWindow.h"
#include <clutter/clutter.h>


class ofPoint;
class ofBaseApp;

extern ClutterActor *stage;


class ofAppClutterWindow : public ofAppBaseWindow {
	public:
	
	ofAppClutterWindow(int argc, char *argv[]);
	~ofAppClutterWindow(){};
	
	void setupOpenGL(int w, int h, int screenMode);
	void initializeWindow();
	void runAppViaInfiniteLoop(ofBaseApp * appPtr);
		
	void hideCursor() {}
	void showCursor() {}
	
	void	setWindowPosition(int x, int y) {}
	void	setWindowShape(int w, int h);
	
	int		getFrameNum() { return 0; }
	float	getFrameRate() {return 0; }
	virtual double  getLastFrameTime(){ return 0.0; }
	
	ofPoint	getWindowPosition() {return ofPoint(); }
	ofPoint	getWindowSize(){return ofPoint(); }
	ofPoint	getScreenSize(){return ofPoint(); }
	
	void	setFrameRate(float targetRate){}
	void	setWindowTitle(string title){}
	
	int		getWindowMode() {return 0;}
	
	void	setFullscreen(bool fullscreen){}
	void	toggleFullscreen(){}
	
	void	enableSetupScreen(){}
	void	disableSetupScreen(){}
private:
	
	
};
