#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	width = ofGetWidth();
	height = ofGetHeight();
	// Create a bunch of random points?
	for (int i = 0; i < 5; i++) {
		pts.push_back(glm::vec2(ofRandom(width), ofRandom(height)));
	}
	// Create the point to chase
	pointToChase = glm::vec2(ofRandom(width), ofRandom(height));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// Abstract this so that we can give just:
	// 1) a start position
	// 2) any number of future positions
	// 3) an initial line width
	path.clear();
	path.setFillColor(ofColor(255, 40, 60));
	path.setFilled(true);
	if (incrementer <= 200) {
		path.moveTo(0 + 50, height/2 - 50);
		path.lineTo(0 + 50, height/2 + 50);
		float easedIncrement = quadEaseOut(incrementer/200.0);
		float lerpedX = ofLerp(50, width - 50, easedIncrement);
		float lerpedY = ofLerp(50, 25, easedIncrement);
		path.lineTo(lerpedX, height/2 + lerpedY);
		path.lineTo(lerpedX, height/2 - lerpedY);
	} else if (incrementer <= 300) {
		path.moveTo(0 + 50, height/2 - 50);
		path.lineTo(0 + 50, height/2 + 50);
		path.lineTo(width - 50, height/2 + 25);
		path.lineTo(width - 50, height/2 - 25);
		path.close();
		path.draw();
		path.moveTo(width - 100, height/2 -25);
		path.lineTo(width - 50, height/2 - 25);
		float easedIncrement = quadEaseOut((incrementer - 200)/100.0);
		float lerpedX = ofLerp(0, 10, easedIncrement);
		float lerpedY = ofLerp(height/2 - 25, 50, easedIncrement);
		path.lineTo(width - (50 + lerpedX), lerpedY);
		path.lineTo(width - (100 - lerpedX), lerpedY);
	} else {
		path.moveTo(0 + 50, height/2 - 50);
		path.lineTo(0 + 50, height/2 + 50);
		path.lineTo(width - 50, height/2 + 25);
		path.lineTo(width - 50, height/2 - 25);
		path.close();
		path.draw();
		path.moveTo(width - 100, height/2 -25);
		path.lineTo(width - 50, height/2 - 25);
		path.lineTo(width - 60, 50);
		path.lineTo(width - 90, 50);
		path.close();
		path.draw();
		path.moveTo(width - 120, 50);
		path.lineTo(width - 75, 20);
		path.lineTo(width - 30, 50);
		path.close();
		path.draw();
	}
	path.close();
	path.draw();
	incrementer++;
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
	incrementer = 0;
	// Update all the points
	// for (int i = 0; i < 100; i++) {
	// 	pts.erase(pts.begin(), pts.begin() + 1);
	// 	float x = ofRandom(width);
	// 	float y = ofRandom(height);
	// 	ofVec2f point = ofVec2f(x, y);
	// 	pts.push_back(point);
	// }
}

//--------------------------------------------------------------
float ofApp::quadEaseOut(float t) {
	return -1.0 *(t)*(t-2);

}
