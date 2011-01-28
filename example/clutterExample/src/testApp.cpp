#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	for(int i=0; i<4; i++) {
		ofxClutterRect* rect = new ofxClutterRect();
		rect->setPosition(128, 128);
		rect->setAnchor(128, 64);
		rect->setSize(256, 128);
		rect->setColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0, 255), ofRandom(0, 255));
		rect->setBorder(ofRandom(0,255), ofRandom(0,255), ofRandom(0, 255), ofRandom(0, 255), 2);
		rects.push_back( rect );
	}
	
	rotation=0;
	
	//tex.loadImage("koala.jpg");
	//tex.setAnchorCenter();
	//tex.setPosition(400, 400);

	ofimg.loadImage("koala.jpg");
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

	// Why aren't you drawing, little guy?
	ofimg.draw(200, 200);
	
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
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

