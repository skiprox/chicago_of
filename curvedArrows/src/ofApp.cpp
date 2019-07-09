#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	width = ofGetWidth();
	height = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	path.clear();
	path.setStrokeColor(ofColor(255, 40, 60));
	path.setFilled(false);
	path.setStrokeWidth(10);
	path.moveTo(100, 100);
	float lerpEndY = incrementer < incMax/2.0 ? ofLerp(100, 400/2.0, (float)incrementer/(incMax/2.0)) : ofLerp(400/2.0, 100, ((float)incrementer - incMax/2.0)/(incMax/2.0));
	path.quadBezierTo(glm::vec2(100, 100), glm::vec2(ofLerp(100, 400, (float)incrementer/incMax), ofLerp(100, 400, (float)incrementer/incMax)), glm::vec2(ofLerp(100, 800, (float)incrementer/incMax), lerpEndY));
	path.draw();
	if (incrementer < incMax) {
		incrementer++;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = 0;
}
