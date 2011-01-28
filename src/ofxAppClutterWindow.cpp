/*
 *  ofxAppClutterWindow.cpp
 *  openFrameworksLib
 *
 *  Created by Jeffrey Crouse on 1/26/11.
 *  Copyright 2011 Eyebeam. All rights reserved.
 *
 */

#include "ofxAppClutterWindow.h"
#include "ofBaseApp.h"
#include "ofMain.h"

ClutterActor* stage;
ClutterTimeline* timeline;
ofBaseApp*	ofAppPtr;


//------------------------------------------------------------
ofxAppClutterWindow::ofxAppClutterWindow(int argc, char *argv[]){
	// I want to keep the args in here because there are some useful command line
	// options built into Clutter
	// http://docs.clutter-project.org/docs/clutter/1.4/running-clutter.html
	//int argc = 1;
	//char *argv = (char*)"openframeworks";
	//char **vptr = &argv;
	
	clutter_init(&argc, &argv);
}


//------------------------------------------------------------
void on_timeline_new_frame(ClutterTimeline *timeline, gint frame_num, gpointer data) {


}

//------------------------------------------------------------
static gboolean on_stage_mouse_move(ClutterStage *stage, ClutterEvent *event, gpointer data) {
	gfloat x = 0;
	gfloat y = 0;
	clutter_event_get_coords(event, &x, &y);
	
	if(ofAppPtr){
		ofAppPtr->mouseX = x;
		ofAppPtr->mouseY = y;
		ofAppPtr->mouseMoved(x, y);
	}
	
#ifdef OF_USING_POCO
	static ofMouseEventArgs mouseEventArgs;
	mouseEventArgs.x = x;
	mouseEventArgs.y = y;
	ofNotifyEvent( ofEvents.mouseMoved, mouseEventArgs );
#endif
	
	return TRUE;
}


//------------------------------------------------------------
static gboolean on_stage_button(ClutterStage *stage, ClutterEvent *event, gpointer data)
{
	gfloat x = 0;
	gfloat y = 0;
	clutter_event_get_coords(event, &x, &y);
	guint32 button = clutter_event_get_button(event);
	
	if(ofAppPtr){
		ofAppPtr->mouseX = x;
		ofAppPtr->mouseY = y;
		if(event->type == CLUTTER_BUTTON_PRESS)
			ofAppPtr->mousePressed(x,y,button);
		
		if(event->type == CLUTTER_BUTTON_RELEASE) 
			ofAppPtr->mouseReleased(x,y,button);
	}
	
#ifdef OF_USING_POCO
	static ofMouseEventArgs mouseEventArgs;
	mouseEventArgs.x = x;
	mouseEventArgs.y = y;
	mouseEventArgs.button = button;
	
	if(event->type == CLUTTER_BUTTON_PRESS)
		ofNotifyEvent( ofEvents.mousePressed, mouseEventArgs );
	
	if(event->type == CLUTTER_BUTTON_RELEASE)
		ofNotifyEvent( ofEvents.mouseReleased, mouseEventArgs );
#endif	
	
	return TRUE; /* Stop further handling of this event. */
}


//------------------------------------------------------------
// cleaner to have 1 keyboard callback and then check event->type
static gboolean on_stage_key(ClutterStage *stage, ClutterEvent *event, gpointer data) {
	
	guint the_symbol = clutter_event_get_key_symbol(event);
	guint16 key_code = clutter_event_get_key_code(event);
	guint32 the_unicode = clutter_event_get_key_unicode(event);
	
	if(ofAppPtr)
	{
		static ofKeyEventArgs keyEventArgs;
		keyEventArgs.key = the_unicode;
		
		if(event->type ==  CLUTTER_KEY_PRESS) {
			ofAppPtr->keyPressed(the_unicode);
#ifdef OF_USING_POCO
			ofNotifyEvent( ofEvents.keyPressed, keyEventArgs );
#endif
		}
		
		if(event->type == CLUTTER_KEY_RELEASE) {
			ofAppPtr->keyReleased(the_unicode);
#ifdef OF_USING_POCO
			ofNotifyEvent( ofEvents.keyReleased, keyEventArgs );
#endif
			if (the_unicode == OF_KEY_ESC){				// "escape"
				OF_EXIT_APP(0);
			}
		}
		
	}
	return TRUE; /* Stop further handling of this event. */
}


//------------------------------------------------------------
void ofxAppClutterWindow::setFrameRate(float targetRate) {
	clutter_set_default_frame_rate(targetRate);
}

//------------------------------------------------------------
float ofxAppClutterWindow::getFrameRate() {
	return clutter_get_default_frame_rate();
}

//------------------------------------------------------------
void ofxAppClutterWindow::setWindowShape(int w, int h) {
	clutter_actor_set_size(stage, w, h);
}


//------------------------------------------------------------
void ofxAppClutterWindow::setWindowTitle(string title){
	clutter_stage_set_title(CLUTTER_STAGE(stage), title.c_str());
}


//------------------------------------------------------------
void ofxAppClutterWindow::hideCursor() {
	clutter_stage_show_cursor(CLUTTER_STAGE(stage));
}


//------------------------------------------------------------
void ofxAppClutterWindow::showCursor() {
	clutter_stage_show_cursor(CLUTTER_STAGE(stage));
}

//------------------------------------------------------------
void ofxAppClutterWindow::setFullscreen(bool fullscreen){
	clutter_stage_set_fullscreen(CLUTTER_STAGE(stage), fullscreen);
}

//------------------------------------------------------------
void ofxAppClutterWindow::toggleFullscreen(){
	gboolean fullscreen = clutter_stage_get_fullscreen(CLUTTER_STAGE(stage));
	clutter_stage_set_fullscreen(CLUTTER_STAGE(stage), !fullscreen);
}


//------------------------------------------------------------
int ofxAppClutterWindow::getWindowMode() {
	gboolean fullscreen = clutter_stage_get_fullscreen(CLUTTER_STAGE(stage));
	return (fullscreen) ? OF_FULLSCREEN : OF_WINDOW;
}


//------------------------------------------------------------
// Sorry this is really messy.  I don't really know what I am doing here.
gboolean on_repaint(gpointer p1){
	
	ofDisableSmoothing();
	ofEnableAlphaBlending();
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	
	
	if(ofAppPtr){
		ofAppPtr->update();
		ofAppPtr->draw();
		
#ifdef OF_USING_POCO
		static ofEventArgs voidEventArgs;
		ofNotifyEvent( ofEvents.update, voidEventArgs);
		ofNotifyEvent( ofEvents.draw, voidEventArgs);
#endif
	}	
	
	
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
    return 1;
}

//------------------------------------------------------------
void ofxAppClutterWindow::setupOpenGL(int w, int h, int screenMode) {
	ClutterColor stage_color = { 200, 200, 200, 255 };
	
	stage = clutter_stage_get_default();
	clutter_actor_set_size(stage, w, h);
	clutter_stage_set_color(CLUTTER_STAGE(stage), &stage_color);
	
	
	g_signal_connect(stage, "button-press-event", G_CALLBACK(on_stage_button), NULL);
	g_signal_connect(stage, "button-release-event", G_CALLBACK(on_stage_button), NULL);
	
	g_signal_connect(stage, "key-press-event", G_CALLBACK(on_stage_key), NULL);
	g_signal_connect(stage, "key-release-event",  G_CALLBACK(on_stage_key), NULL);
	
	g_signal_connect(stage, "motion-event", G_CALLBACK(on_stage_mouse_move), NULL);
	

    clutter_threads_add_repaint_func(&on_repaint, NULL, NULL); //target call
}




//------------------------------------------------------------
void ofxAppClutterWindow::initializeWindow() {
	clutter_actor_show(stage);
}


//------------------------------------------------------------
void ofxAppClutterWindow::runAppViaInfiniteLoop(ofBaseApp * appPtr) {
	
	ofAppPtr = appPtr;
	
	if(ofAppPtr){
		ofAppPtr->setup();
		ofAppPtr->update();
	}	
	
	// You have to have something running or else the repaint function won't be called.
	timeline = clutter_timeline_new( 1000 / getFrameRate() );
	//g_signal_connect(timeline, "new-frame", G_CALLBACK(on_timeline_new_frame), NULL);
	clutter_timeline_set_loop(timeline, TRUE); 
	clutter_timeline_start(timeline);

	clutter_main();
}