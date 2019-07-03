#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	width = ofGetWidth();
	height = ofGetHeight();
	building.load("building.png");
	// 0
	pts1.push_back(glm::vec2(50, height/1.2 - 50));
	pts2.push_back(glm::vec2(50, height/1.2 + 50));
	// 1
	pts1.push_back(glm::vec2(width - 50, height/1.2 + 25));
	pts2.push_back(glm::vec2(width - 50, height/1.2 - 25));
	// 2
	pts1.push_back(glm::vec2(width - 100, height/1.2 - 25));
	pts2.push_back(glm::vec2(width - 50, height/1.2 - 25));
	// 3
	pts1.push_back(glm::vec2(width - 60, 50));
	pts2.push_back(glm::vec2(width - 90, 50));
	// 4
	pts1.push_back(glm::vec2(width - 90, 50));
	pts2.push_back(glm::vec2(width - 90, 80));
	// 5
	pts1.push_back(glm::vec2(120, 75));
	pts2.push_back(glm::vec2(120, 55));
	// 6
	pts1.push_back(glm::vec2(120, 75));
	pts2.push_back(glm::vec2(140, 75));
	// 7
	pts1.push_back(glm::vec2(136, 400));
	pts2.push_back(glm::vec2(124, 400));
	// 8
	pts1.push_back(glm::vec2(136, 388));
	pts2.push_back(glm::vec2(136, 400));
	// 9
	pts1.push_back(glm::vec2(420, 398));
	pts2.push_back(glm::vec2(420, 390));
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
	drawPointer(pts1, pts2, true, incrementer);
	incrementer++;
}

//--------------------------------------------------------------
void ofApp::drawPointer(vector<glm::vec2> pts1, vector<glm::vec2> pts2, bool shouldHaveArrow, int incrementer){
	path.clear();
	path.setFillColor(ofColor(180, 8, 16));
	path.setFilled(true);
	// Draw the first part of the line
	if (incrementer <= 100) {
		path.moveTo(pts1[0]);
		path.lineTo(pts2[0]);
		float easedIncrement = quadEaseOut(incrementer/100.0);
		path.lineTo(ofLerp(pts2[0].x, pts1[1].x, easedIncrement), ofLerp(pts2[0].y, pts1[1].y, easedIncrement));
		path.lineTo(ofLerp(pts1[0].x, pts2[1].x, easedIncrement), ofLerp(pts1[0].y, pts2[1].y, easedIncrement));
		path.close();
		path.draw();
	} else if (incrementer <= 200) {
		path.moveTo(pts1[0]);
		path.lineTo(pts2[0]);
		path.lineTo(pts1[1]);
		path.lineTo(pts2[1]);
		path.close();
		path.draw();
		path.moveTo(pts1[2]);
		path.lineTo(pts2[2]);
		float easedIncrement = quadEaseOut((incrementer - 100)/100.0);
		path.lineTo(ofLerp(pts2[2].x, pts1[3].x, easedIncrement), ofLerp(pts2[2].y, pts1[3].y, easedIncrement));
		path.lineTo(ofLerp(pts1[2].x, pts2[3].x, easedIncrement), ofLerp(pts1[2].y, pts2[3].y, easedIncrement));
		path.close();
		path.draw();
	} else if (incrementer <= 300) {
		path.moveTo(pts1[0]);
		path.lineTo(pts2[0]);
		path.lineTo(pts1[1]);
		path.lineTo(pts2[1]);
		path.close();
		path.draw();
		path.moveTo(pts1[2]);
		path.lineTo(pts2[2]);
		path.lineTo(pts1[3]);
		path.lineTo(pts2[3]);
		path.close();
		path.draw();
		path.moveTo(pts1[4]);
		path.lineTo(pts2[4]);
		float easedIncrement = quadEaseOut((incrementer - 200)/100.0);
		path.lineTo(ofLerp(pts2[4].x, pts1[5].x, easedIncrement), ofLerp(pts2[4].y, pts1[5].y, easedIncrement));
		path.lineTo(ofLerp(pts1[4].x, pts2[5].x, easedIncrement), ofLerp(pts1[4].y, pts2[5].y, easedIncrement));
		path.close();
		path.draw();
	} else if (incrementer <= 350) {
		path.moveTo(pts1[0]);
		path.lineTo(pts2[0]);
		path.lineTo(pts1[1]);
		path.lineTo(pts2[1]);
		path.close();
		path.draw();
		path.moveTo(pts1[2]);
		path.lineTo(pts2[2]);
		path.lineTo(pts1[3]);
		path.lineTo(pts2[3]);
		path.close();
		path.draw();
		path.moveTo(pts1[4]);
		path.lineTo(pts2[4]);
		path.lineTo(pts1[5]);
		path.lineTo(pts2[5]);
		path.close();
		path.draw();
		path.moveTo(pts1[6]);
		path.lineTo(pts2[6]);
		float easedIncrement = quadEaseOut((incrementer - 300)/50.0);
		path.lineTo(ofLerp(pts2[6].x, pts1[7].x, easedIncrement), ofLerp(pts2[6].y, pts1[7].y, easedIncrement));
		path.lineTo(ofLerp(pts1[6].x, pts2[7].x, easedIncrement), ofLerp(pts1[6].y, pts2[7].y, easedIncrement));
		path.close();
		path.draw();
	} else if (incrementer <= 375) {
		path.moveTo(pts1[0]);
		path.lineTo(pts2[0]);
		path.lineTo(pts1[1]);
		path.lineTo(pts2[1]);
		path.close();
		path.draw();
		path.moveTo(pts1[2]);
		path.lineTo(pts2[2]);
		path.lineTo(pts1[3]);
		path.lineTo(pts2[3]);
		path.close();
		path.draw();
		path.moveTo(pts1[4]);
		path.lineTo(pts2[4]);
		path.lineTo(pts1[5]);
		path.lineTo(pts2[5]);
		path.close();
		path.draw();
		path.moveTo(pts1[6]);
		path.lineTo(pts2[6]);
		path.lineTo(pts1[7]);
		path.lineTo(pts2[7]);
		path.close();
		path.draw();
		path.moveTo(pts1[8]);
		path.lineTo(pts2[8]);
		float easedIncrement = quadEaseOut((incrementer - 350)/25.0);
		path.lineTo(ofLerp(pts2[8].x, pts1[9].x, easedIncrement), ofLerp(pts2[8].y, pts1[9].y, easedIncrement));
		path.lineTo(ofLerp(pts1[8].x, pts2[9].x, easedIncrement), ofLerp(pts1[8].y, pts2[9].y, easedIncrement));
		path.close();
		path.draw();
	} else if (incrementer <= 425) {
		path.moveTo(pts1[0]);
		path.lineTo(pts2[0]);
		path.lineTo(pts1[1]);
		path.lineTo(pts2[1]);
		path.close();
		path.draw();
		path.moveTo(pts1[2]);
		path.lineTo(pts2[2]);
		path.lineTo(pts1[3]);
		path.lineTo(pts2[3]);
		path.close();
		path.draw();
		path.moveTo(pts1[4]);
		path.lineTo(pts2[4]);
		path.lineTo(pts1[5]);
		path.lineTo(pts2[5]);
		path.close();
		path.draw();
		path.moveTo(pts1[6]);
		path.lineTo(pts2[6]);
		path.lineTo(pts1[7]);
		path.lineTo(pts2[7]);
		path.close();
		path.draw();
		path.moveTo(pts1[8]);
		path.lineTo(pts2[8]);
		path.lineTo(pts1[9]);
		path.lineTo(pts2[9]);
		path.close();
		path.draw();
		if (shouldHaveArrow) {
			path.moveTo(420, 382);
			path.lineTo(436, 394);
			path.lineTo(420, 406);
			path.close();
			path.draw();
		}
		ofPushMatrix();
		ofTranslate(550, 400);
		float easedValue = bounceEaseOut(ofClamp((incrementer - 375)/50.0, 0.0, 1.0));
		ofScale(easedValue, easedValue);
		// ofRotate(45 * easedValue);
		building.draw(-110, -184);
		ofPopMatrix();
	} else {
		path.moveTo(pts1[0]);
		path.lineTo(pts2[0]);
		path.lineTo(pts1[1]);
		path.lineTo(pts2[1]);
		path.close();
		path.draw();
		path.moveTo(pts1[2]);
		path.lineTo(pts2[2]);
		path.lineTo(pts1[3]);
		path.lineTo(pts2[3]);
		path.close();
		path.draw();
		path.moveTo(pts1[4]);
		path.lineTo(pts2[4]);
		path.lineTo(pts1[5]);
		path.lineTo(pts2[5]);
		path.close();
		path.draw();
		path.moveTo(pts1[6]);
		path.lineTo(pts2[6]);
		path.lineTo(pts1[7]);
		path.lineTo(pts2[7]);
		path.close();
		path.draw();
		path.moveTo(pts1[8]);
		path.lineTo(pts2[8]);
		path.lineTo(pts1[9]);
		path.lineTo(pts2[9]);
		path.close();
		path.draw();
		if (shouldHaveArrow) {
			path.moveTo(420, 382);
			path.lineTo(436, 394);
			path.lineTo(420, 406);
			path.close();
			path.draw();
		}
		ofPushMatrix();
		ofTranslate(550, 400);
		building.draw(-110, -184);
		ofPopMatrix();
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

//--------------------------------------------------------------
float ofApp::bounceEaseOut(float t) {
	if (t < (1/2.75f)) {
		return (7.5625f*t*t);
	} else if (t < (2/2.75f)) {
		float postFix = t-=(1.5f/2.75f);
		return (7.5625f*(postFix)*t + .75f);
	} else if (t < (2.5/2.75)) {
			float postFix = t-=(2.25f/2.75f);
		return (7.5625f*(postFix)*t + .9375f);
	} else {
		float postFix = t-=(2.625f/2.75f);
		return (7.5625f*(postFix)*t + .984375f);
	}
}
