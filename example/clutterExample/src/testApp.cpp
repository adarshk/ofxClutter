#include "testApp.h"

extern "C" {
#include "ofAppClutterWindow.h"
};


ClutterActor *rect1 = NULL;
ClutterActor *rect2 = NULL;
ClutterActor *rect3 = NULL;
ClutterActor *rect4 = NULL;
ClutterActor *rect5 = NULL;
ClutterActor *rect6 = NULL;

gdouble rotation = 0;

ClutterActor *create_rect(ClutterColor col) {
	ClutterActor *rect = clutter_rectangle_new_with_color(&col);
	clutter_actor_set_size(rect, 256, 128);
	clutter_actor_set_position(rect, 128, 128);
	clutter_actor_set_anchor_point(rect, 128, 64);
	clutter_container_add_actor(CLUTTER_CONTAINER(stage), rect);
	clutter_actor_show(rect);
	
	return rect;
}


void on_timeline_new_frame(ClutterTimeline *timeline, gint frame_num, gpointer data) {
	rotation += 0.3;
	
	clutter_actor_set_rotation(rect1, CLUTTER_Z_AXIS, rotation * 5, 0, 0, 0);
	clutter_actor_set_rotation(rect2, CLUTTER_Z_AXIS, rotation * 4, 0, 0, 0);
	clutter_actor_set_rotation(rect3, CLUTTER_Z_AXIS, rotation * 3, 0, 0, 0);
	clutter_actor_set_rotation(rect4, CLUTTER_Z_AXIS, rotation * 2, 0, 0, 0);
	clutter_actor_set_rotation(rect5, CLUTTER_Z_AXIS, rotation, 0, 0, 0);
	clutter_actor_set_rotation(rect6, CLUTTER_Z_AXIS, rotation * 0.5, 0, 0, 0);
}

//--------------------------------------------------------------
void testApp::setup(){
	

	ClutterColor red = { 255, 0, 0, 128 };
	ClutterColor green = { 0, 255, 0, 128 };
	ClutterColor blue = { 0, 0, 255, 128 };
	ClutterColor yellow = { 255, 255, 0, 128 };
	ClutterColor cyan = { 0, 255, 255, 128 };
	ClutterColor purple = { 255, 0, 255, 128 };
	
	rect1 = create_rect(red);
	rect2 = create_rect(green);
	rect3 = create_rect(blue);
	rect4 = create_rect(yellow);
	rect5 = create_rect(cyan);
	rect6 = create_rect(purple);
	
	
	ClutterTimeline *timeline = clutter_timeline_new(60);
	g_signal_connect(timeline, "new-frame", G_CALLBACK(on_timeline_new_frame), NULL);
	clutter_timeline_set_loop(timeline, TRUE); 
	clutter_timeline_start(timeline);
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

