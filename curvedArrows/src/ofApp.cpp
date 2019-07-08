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
	path.quadBezierTo(glm::vec2(100, 100), glm::vec2(400, 400), glm::vec2(800, 100));
	path.draw();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
