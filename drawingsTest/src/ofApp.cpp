#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	width = ofGetWidth();
	height = ofGetHeight();

	// Create a bunch of random points?
	for (int i = 0; i < 100; i++) {
		float x = ofRandom(width);
		float y = ofRandom(height);
		ofVec2f point = ofVec2f(x, y);
		pts.push_back(point);
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	output.setColor(0x0088EE);
	output.noFill();
	ofSetLineWidth(30);
	output.beginShape();
	int rescaleRes = 6;
	for (int i = 0; i < pts.size(); i++) {
		//we need to draw the first and last point
		//twice for a catmull curve
		if (i == 0 || i == pts.size() - 1) {
			output.curveVertex(pts[i].x, pts[i].y);
		}
		if (i % rescaleRes == 0) output.curveVertex(pts[i].x, pts[i].y);
	}
	output.endShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	// Update all the points
	for (int i = 0; i < 100; i++) {
		pts.erase(pts.begin(), pts.begin() + 1);
		float x = ofRandom(width);
		float y = ofRandom(height);
		ofVec2f point = ofVec2f(x, y);
		pts.push_back(point);
	}
}
