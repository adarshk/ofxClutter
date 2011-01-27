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

/*
 "allocation-changed"                             : Run Last
 "button-press-event"                             : Run Last
 "button-release-event"                           : Run Last
 "captured-event"                                 : Run Last
 "destroy"                                        : No Hooks
 "enter-event"                                    : Run Last
 "event"                                          : Run Last
 "hide"                                           : Run First
 "key-focus-in"                                   : Run Last
 "key-focus-out"                                  : Run Last
 "key-press-event"                                : Run Last
 "key-release-event"                              : Run Last
 "leave-event"                                    : Run Last
 "motion-event"                                   : Run Last
 "paint"                                          : Run Last
 "parent-set"                                     : Run Last
 "pick"                                           : Run Last
 "queue-redraw"                                   : Run Last
 "queue-relayout"                                 : Run Last
 "realize"                                        : Run Last
 "scroll-event"                                   : Run Last
 "show"                                           : Run First
 "unrealize"                                      : Run Last
 */

// NOTE:  
// ClutterMM?  http://danielkitta.org/blog/2009/01/07/cluttermm-tutorial/

ofAppClutterWindow::ofAppClutterWindow(int argc, char *argv[]){
	clutter_init(&argc, &argv);
}



static gboolean
on_stage_button_press (ClutterStage *stage, ClutterEvent *event, gpointer data)
{
	gfloat x = 0;
	gfloat y = 0;
	guint32 button = clutter_event_get_button(event);
	clutter_event_get_coords(event, &x, &y);
	
	static ofMouseEventArgs mouseEventArgs;

	if(ofAppPtr){
		ofAppPtr->mouseX = x;
		ofAppPtr->mouseY = y;
	}
	
	if(ofAppPtr)
		ofAppPtr->mousePressed(x,y,button);
	
#ifdef OF_USING_POCO
	mouseEventArgs.x = x;
	mouseEventArgs.y = y;
	mouseEventArgs.button = button;
	ofNotifyEvent( ofEvents.mousePressed, mouseEventArgs );
#endif
	return TRUE; /* Stop further handling of this event. */
}

static gboolean on_stage_button_release(ClutterStage *stage, ClutterEvent *event, gpointer data)
{
	gfloat x = 0;
	gfloat y = 0;
	clutter_event_get_coords(event, &x, &y);
	guint32 button = clutter_event_get_button(event);
	
	static ofMouseEventArgs mouseEventArgs;
	
	if(ofAppPtr){
		ofAppPtr->mouseReleased(x,y,button);
		ofAppPtr->mouseReleased();
	}
	
#ifdef OF_USING_POCO
	mouseEventArgs.x = x;
	mouseEventArgs.y = y;
	mouseEventArgs.button = button;
	ofNotifyEvent( ofEvents.mouseReleased, mouseEventArgs );
#endif	
}


//------------------------------------------------------------
static gboolean on_stage_key_press(ClutterStage *stage, ClutterEvent *event, gpointer data) {
	static ofKeyEventArgs keyEventArgs;
	guint16 key = clutter_event_get_key_code(event);
	
	if(ofAppPtr)
		ofAppPtr->keyPressed(key);
	
#ifdef OF_USING_POCO
	keyEventArgs.key = key;
	ofNotifyEvent( ofEvents.keyPressed, keyEventArgs );
#endif
	
	if (key == OF_KEY_ESC){				// "escape"
		OF_EXIT_APP(0);
	}
}

//------------------------------------------------------------
static gboolean on_stage_key_release(ClutterStage *stage, ClutterEvent *event, gpointer data) {
	static ofKeyEventArgs keyEventArgs;
	guint16 key = clutter_event_get_key_code(event);
	
	if(ofAppPtr)
		ofAppPtr->keyReleased(key);
	
#ifdef OF_USING_POCO
	keyEventArgs.key = key;
	ofNotifyEvent( ofEvents.keyReleased, keyEventArgs );
#endif
}

void ofAppClutterWindow::setWindowShape(int w, int h) {
	clutter_actor_set_size(stage, w, h);
}


void ofAppClutterWindow::setupOpenGL(int w, int h, int screenMode) {
	ClutterColor stage_color = { 200, 200, 200, 255 };
	
	stage = clutter_stage_get_default();
	clutter_actor_set_size(stage, w, h);
	clutter_stage_set_color(CLUTTER_STAGE(stage), &stage_color);
	
	
	g_signal_connect(stage, "button-press-event",
					  G_CALLBACK(on_stage_button_press), NULL);
	g_signal_connect(stage, "button-release-event",
					 G_CALLBACK(on_stage_button_release), NULL);
	
	g_signal_connect(stage, "key-press-event",
					 G_CALLBACK(on_stage_key_press), NULL);
	g_signal_connect(stage, "key-release-event",
					 G_CALLBACK(on_stage_key_release), NULL);
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