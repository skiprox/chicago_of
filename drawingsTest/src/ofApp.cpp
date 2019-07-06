#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	width = ofGetWidth();
	height = ofGetHeight();
	// WHAT IS A MORE EFFECTIVE WAY OF DOING THIS???
	// pts.push_back(glm::vec4(50, height/2 - 50, 50, height/2 + 50));
	array<glm::vec2, 4> newPoints1 = {glm::vec2(50, height/2 - 50), glm::vec2(50, height/2 + 50), glm::vec2(width - 50, height/2 + 25), glm::vec2(width - 50, height/2 - 25)};
	pts.push_back(newPoints1);
	array<glm::vec2, 4> newPoints2 = {glm::vec2(width - 100, height/2 - 25), glm::vec2(width - 50, height/2 - 25), glm::vec2(width - 60, 50), glm::vec2(width - 90, 50)};
	pts.push_back(newPoints2);
	pts1.push_back(glm::vec2(50, height/2 - 50));
	pts2.push_back(glm::vec2(50, height/2 + 50));
	pts1.push_back(glm::vec2(width - 50, height/2 + 25));
	pts2.push_back(glm::vec2(width - 50, height/2 - 25));
	pts1.push_back(glm::vec2(width - 100, height/2 - 25));
	pts2.push_back(glm::vec2(width - 50, height/2 - 25));
	pts1.push_back(glm::vec2(width - 60, 50));
	pts2.push_back(glm::vec2(width - 90, 50));
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
	// 4) whether to include an arrow at the end
	// 5) incrementer
	// Draw the pointer
	drawPointer(pts1, pts2, false, incrementer);
	incrementer++;
}

//--------------------------------------------------------------
void ofApp::drawPointer(vector<glm::vec2> pts1, vector<glm::vec2> pts2, bool shouldHaveArrow, int incrementer){
	path.clear();
	path.setFillColor(ofColor(255, 40, 60));
	path.setFilled(true);
	// Draw the first part of the line
	if (incrementer <= 200) {
		path.moveTo(pts[0][0]);
		path.lineTo(pts[0][1]);
		float easedIncrement = quadEaseOut(incrementer/200.0);
		path.lineTo(ofLerp(pts[0][1].x, pts[0][2].x, easedIncrement), ofLerp(pts[0][1].y, pts[0][2].y, easedIncrement));
		path.lineTo(ofLerp(pts[0][0].x, pts[0][3].x, easedIncrement), ofLerp(pts[0][0].y, pts[0][3].y, easedIncrement));
		path.close();
		path.draw();
	} else if (incrementer <= 300) {
		path.moveTo(pts[0][0]);
		path.lineTo(pts[0][1]);
		path.lineTo(pts[0][2]);
		path.lineTo(pts[0][3]);
		path.close();
		path.draw();
		path.moveTo(pts[1][0]);
		path.lineTo(pts[1][1]);
		float easedIncrement = quadEaseOut((incrementer - 200)/100.0);
		path.lineTo(ofLerp(pts[1][1].x, pts[1][2].x, easedIncrement), ofLerp(pts[1][1].y, pts[1][2].y, easedIncrement));
		path.lineTo(ofLerp(pts[1][0].x, pts[1][3].x, easedIncrement), ofLerp(pts[1][0].y, pts[1][3].y, easedIncrement));
		path.close();
		path.draw();
	} else {
		path.moveTo(pts[0][0]);
		path.lineTo(pts[0][1]);
		path.lineTo(pts[0][2]);
		path.lineTo(pts[0][3]);
		path.close();
		path.draw();
		path.moveTo(pts[1][0]);
		path.lineTo(pts[1][1]);
		path.lineTo(pts[1][2]);
		path.lineTo(pts[1][3]);
		path.close();
		path.draw();
		if (shouldHaveArrow) {
			path.moveTo(width - 120, 50);
			path.lineTo(width - 75, 20);
			path.lineTo(width - 30, 50);
			path.close();
			path.draw();
		}
	}
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
}

//--------------------------------------------------------------
float ofApp::quadEaseOut(float t) {
	return -1.0 *(t)*(t-2);
}
