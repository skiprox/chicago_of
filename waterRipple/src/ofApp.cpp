#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	agua.setup(ofGetWidth(), ofGetHeight());
	cout << ofGetWidth() << " " << ofGetHeight() << endl;
	//overlay.load("images/overlay.png");
}

//--------------------------------------------------------------
void ofApp::update(){
	agua.update();
	ofSetWindowTitle( ofToString(ofGetFrameRate()) + " FPS" );
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	float ranX = ofRandom(ofGetWidth());
	float ranY = ofRandom(ofGetHeight());
	agua.disturb(ranX, ranY, 10, 128);
	agua.draw(true);
	//overlay.draw(0, 0);
	// ofSetColor(220, 40, 20);
	// ofFill();
	//ofDrawRectangle(400, 400, 200, 200);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	agua.disturb(x,y,10,128);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_1)
		agua.disturb(x,y,10,128);
	else
		agua.disturb(x,y,50,500);

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
