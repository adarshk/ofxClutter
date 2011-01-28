#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(120);
	
	for(int i=0; i<8; i++) {
		ofxClutterRect* rect = new ofxClutterRect();
		rect->setPosition(128, 128);
		rect->setAnchor(128, 64);
		rect->setSize(256, 128);
		rect->setColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0, 255), ofRandom(0, 255));
		rect->setBorder(ofRandom(0,255), ofRandom(0,255), ofRandom(0, 255), ofRandom(0, 255), 2);
		rects.push_back( rect );
	}
	
	rotation=0;


	monalisaurus.loadImage("monalisaurus.jpg");
	monalisaurus.setPosition(100, 100);
	
	koala.loadImage("koala.jpg");
	koala.setPosition(100, 100);
	
	//http://docs.clutter-project.org/docs/clutter-cookbook/1.0/
	
	ClutterKnot knot[4];
	knot[0].x = 10;
	knot[0].y = 10;
	knot[1].x= ofGetWidth()-koala.getWidth();
	knot[1].y= 0;
	knot[2].x= ofGetWidth()-koala.getWidth();
	knot[2].y= ofGetHeight()-koala.getHeight();
	knot[3].x= 0;
	knot[4].y= ofGetHeight()-koala.getHeight();
	

	
	transitions = clutter_state_new ();
	
	/* start state, where bottom is opaque and top is transparent */
	clutter_state_set (transitions, NULL, "show-bottom",
					   koala.actor, "opacity", CLUTTER_LINEAR, 0,
					   monalisaurus.actor, "opacity", CLUTTER_LINEAR, 255,
					   NULL);
	
	/* end state, where top is opaque and bottom is transparent */
	clutter_state_set (transitions, NULL, "show-top",
					   koala.actor, "opacity", CLUTTER_EASE_IN_CUBIC, 255,
					   monalisaurus.actor, "opacity", CLUTTER_EASE_IN_CUBIC, 0,
					   NULL);
	
	/* set 1000ms duration for all transitions between states */
	clutter_state_set_duration (transitions, NULL, NULL, 1000);
	
	clutter_state_warp_to_state (transitions, "show-bottom");
	top = false;
	
	//ofimg.loadImage("koala.jpg");
}

//--------------------------------------------------------------
void testApp::update(){

	rotation += 0.3;
	
	for(int i=0; i<rects.size(); i++) {
		rects[i]->setZRotation( (i+1) * rotation );
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	// Why aren't you drawing, little guy?
	//ofimg.draw(200, 200);
	
	ofPushStyle();
		ofSetColor(255, 0, 0);
		ofSetLineWidth(3);
			
		// Et tu, ellipse?
		ofEllipse(500, 500, 200, 200);
	ofPopStyle();
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
	if(top)
		clutter_state_set_state(transitions, "show-bottom");
	else
		clutter_state_set_state(transitions, "show-top");
	
	top=!top;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

