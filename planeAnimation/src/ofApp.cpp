#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	plane.load("plane.png");
	planeAnimation = PlaneAnimation(plane);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (fabs(universalCounter - TWO_PI) < 0.0001) {
		universalCounter = 0.0f;
	} else {
		universalCounter = (universalCounter + PI/100.0);
	}
	planeAnimation.update(universalCounter);
}

//--------------------------------------------------------------
void ofApp::draw(){
	planeAnimation.draw();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
