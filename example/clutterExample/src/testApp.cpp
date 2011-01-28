#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	
	for(int i=0; i<10; i++) {
		ofxClutterRect* rect = new ofxClutterRect();
		rect->setPosition(128, 128);
		rect->setAnchor(128, 64);
		rect->setSize(256, 128);
		rect->setColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0, 255), ofRandom(0, 255));
		rects.push_back( rect );
	}
	
	rotation=0;
	
	
	tex.loadImage("koala.jpg");
	
	tex.setAnchorCenter();
	tex.setPosition(400, 400);
	
	/*
	ClutterActor *label = clutter_text_new_full("Sans 60", "Some Text", &purple);
	clutter_actor_set_size(label, 500, 500);
	clutter_actor_set_position(label, 20, 500);
	clutter_container_add_actor(CLUTTER_CONTAINER(stage), label);
	clutter_actor_show(label);
	*/
	
	//img.loadImage("koala.jpg");
}

//--------------------------------------------------------------
void testApp::update(){

	rotation += 0.3;
	
	for(int i=0; i<rects.size(); i++) {
		rects[i]->setZRotation( i * rotation );
	}
	
	tex.setZRotation(rotation * 0.5);

}

//--------------------------------------------------------------
void testApp::draw(){

	//img.draw(200, 200);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	cout << "keyPressed: " << (char)key << endl;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	cout << "keyReleased: " << (char)key << endl;
	switch(key) {
		case 'f':
			ofToggleFullscreen();
			break;
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	cout << "mousePressed: x=" << x << " y=" << y << endl;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	cout << "mousePressed: x=" << x << " y=" << y << endl;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

