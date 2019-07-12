#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	width = ofGetWidth();
	height = ofGetHeight();
	inc = 0;
	incMax = 250;
	pathStart = glm::vec2(200, 100);
	pathEnd = glm::vec2(1100, 300);
	dashedLine = DashedLine(pathStart, pathEnd, ofColor(255, 40, 60), incMax);
}

//--------------------------------------------------------------
void ofApp::update(){
	inc++;
	dashedLine.update(inc);
}

//--------------------------------------------------------------
void ofApp::draw(){
	dashedLine.draw();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	inc = 0;
}
