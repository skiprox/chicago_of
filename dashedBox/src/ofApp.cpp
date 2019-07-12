#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetCircleResolution(100);
	width = ofGetWidth();
	height = ofGetHeight();
	dashedBox = DashedBox(glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0), 200.0, 200.0, ofColor(240, 40, 20),250);
}

//--------------------------------------------------------------
void ofApp::update(){
	dashedBox.update(incrementer);
	incrementer++;
}

//--------------------------------------------------------------
void ofApp::draw(){
	dashedBox.draw();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = 0;
}
