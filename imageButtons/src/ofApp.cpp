#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	ofImage image;
	image.load("plane.png");
	imageButton = ImageButton(image, glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0), glm::vec2(500, 158));
}

//--------------------------------------------------------------
void ofApp::update(){
	if (fabs(universalCounter - TWO_PI) < 0.0001) {
		universalCounter = 0.0f;
	} else {
		universalCounter = (universalCounter + PI/100.0);
	}
	imageButton.update(universalCounter);
}

//--------------------------------------------------------------
void ofApp::draw(){
	imageButton.draw();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
