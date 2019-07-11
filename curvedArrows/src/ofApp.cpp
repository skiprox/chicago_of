#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	width = ofGetWidth();
	height = ofGetHeight();
	curvedArrow = CurvedArrow(glm::vec2(100, 100), glm::vec2(width/2.0, (height/3.0)*2), glm::vec2((width/3.0)*2.0, (height/3.0)*2.0), red, incMax);
}

//--------------------------------------------------------------
void ofApp::update(){
	curvedArrow.update(incrementer);
	if (incrementer < incMax) {
		incrementer++;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	curvedArrow.draw();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = 0;
}
