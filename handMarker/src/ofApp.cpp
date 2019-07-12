#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetCircleResolution(100);
	handMarker = HandMarker(glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0), ofColor(240, 40, 20));
}

//--------------------------------------------------------------
void ofApp::update(){
	if (fabs(universalCounter - TWO_PI) < 0.0001) {
		universalCounter = 0.0f;
	} else {
		universalCounter = (universalCounter + PI/100.0);
	}
	handMarker.update(universalCounter);
}

//--------------------------------------------------------------
void ofApp::draw(){
	handMarker.draw();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
