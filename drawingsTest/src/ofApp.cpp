#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	width = ofGetWidth();
	height = ofGetHeight();
	building.load("building.png");
	array<glm::vec2, 4> newPoints0 = {glm::vec2(50, height/1.2 - 50), glm::vec2(50, height/1.2 + 50), glm::vec2(width - 50, height/1.2 + 25), glm::vec2(width - 50, height/1.2 - 25)};
	pts.push_back(newPoints0);
	array<glm::vec2, 4> newPoints1 = {glm::vec2(width - 100, height/1.2 - 25), glm::vec2(width - 50, height/1.2 - 25), glm::vec2(width - 60, 50), glm::vec2(width - 90, 50)};
	pts.push_back(newPoints1);
	array<glm::vec2, 4> newPoints2 = {glm::vec2(width - 90, 50), glm::vec2(width - 90, 80), glm::vec2(120, 75), glm::vec2(120, 55)};
	pts.push_back(newPoints2);
	array<glm::vec2, 4> newPoints3 = {glm::vec2(120, 75), glm::vec2(140, 75), glm::vec2(136, 400), glm::vec2(124, 400)};
	pts.push_back(newPoints3);
	array<glm::vec2, 4> newPoints4 = {glm::vec2(136, 388), glm::vec2(136, 400), glm::vec2(420, 398), glm::vec2(420, 390)};
	pts.push_back(newPoints4);
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
	drawPointer(pts, true, incrementer);
	incrementer++;
}

//--------------------------------------------------------------
void ofApp::drawPointer(vector<std::array<glm::vec2, 4>> pts, bool shouldHaveArrow, int incrementer){
	path.clear();
	path.setFillColor(ofColor(180, 8, 16));
	path.setFilled(true);
	// Draw the first part of the line
	if (incrementer <= 100) {
		path.moveTo(pts[0][0]);
		path.lineTo(pts[0][1]);
		float easedIncrement = quadEaseOut(incrementer/100.0);
		path.lineTo(ofLerp(pts[0][1].x, pts[0][2].x, easedIncrement), ofLerp(pts[0][1].y, pts[0][2].y, easedIncrement));
		path.lineTo(ofLerp(pts[0][0].x, pts[0][3].x, easedIncrement), ofLerp(pts[0][0].y, pts[0][3].y, easedIncrement));
		path.close();
		path.draw();
	} else if (incrementer <= 200) {
		path.moveTo(pts[0][0]);
		path.lineTo(pts[0][1]);
		path.lineTo(pts[0][2]);
		path.lineTo(pts[0][3]);
		path.close();
		path.draw();
		path.moveTo(pts[1][0]);
		path.lineTo(pts[1][1]);
		float easedIncrement = quadEaseOut((incrementer - 100)/100.0);
		path.lineTo(ofLerp(pts[1][1].x, pts[1][2].x, easedIncrement), ofLerp(pts[1][1].y, pts[1][2].y, easedIncrement));
		path.lineTo(ofLerp(pts[1][0].x, pts[1][3].x, easedIncrement), ofLerp(pts[1][0].y, pts[1][3].y, easedIncrement));
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
		path.lineTo(pts[1][2]);
		path.lineTo(pts[1][3]);
		path.close();
		path.draw();
		path.moveTo(pts[2][0]);
		path.lineTo(pts[2][1]);
		float easedIncrement = quadEaseOut((incrementer - 200)/100.0);
		path.lineTo(ofLerp(pts[2][1].x, pts[2][2].x, easedIncrement), ofLerp(pts[2][1].y, pts[2][2].y, easedIncrement));
		path.lineTo(ofLerp(pts[2][0].x, pts[2][3].x, easedIncrement), ofLerp(pts[2][0].y, pts[2][3].y, easedIncrement));
		path.close();
		path.draw();
	} else if (incrementer <= 350) {
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
		path.moveTo(pts[2][0]);
		path.lineTo(pts[2][1]);
		path.lineTo(pts[2][2]);
		path.lineTo(pts[2][3]);
		path.close();
		path.draw();
		path.moveTo(pts[3][0]);
		path.lineTo(pts[3][1]);
		float easedIncrement = quadEaseOut((incrementer - 300)/50.0);
		path.lineTo(ofLerp(pts[3][1].x, pts[3][2].x, easedIncrement), ofLerp(pts[3][1].y, pts[3][2].y, easedIncrement));
		path.lineTo(ofLerp(pts[3][0].x, pts[3][3].x, easedIncrement), ofLerp(pts[3][0].y, pts[3][3].y, easedIncrement));
		path.close();
		path.draw();
	} else if (incrementer <= 375) {
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
		path.moveTo(pts[2][0]);
		path.lineTo(pts[2][1]);
		path.lineTo(pts[2][2]);
		path.lineTo(pts[2][3]);
		path.close();
		path.draw();
		path.moveTo(pts[3][0]);
		path.lineTo(pts[3][1]);
		path.lineTo(pts[3][2]);
		path.lineTo(pts[3][3]);
		path.close();
		path.draw();
		path.moveTo(pts[4][0]);
		path.lineTo(pts[4][1]);
		float easedIncrement = quadEaseOut((incrementer - 350)/25.0);
		path.lineTo(ofLerp(pts[4][1].x, pts[4][2].x, easedIncrement), ofLerp(pts[4][1].y, pts[4][2].y, easedIncrement));
		path.lineTo(ofLerp(pts[4][0].x, pts[4][3].x, easedIncrement), ofLerp(pts[4][0].y, pts[4][3].y, easedIncrement));
		path.close();
		path.draw();
	} else if (incrementer <= 425) {
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
		path.moveTo(pts[2][0]);
		path.lineTo(pts[2][1]);
		path.lineTo(pts[2][2]);
		path.lineTo(pts[2][3]);
		path.close();
		path.draw();
		path.moveTo(pts[3][0]);
		path.lineTo(pts[3][1]);
		path.lineTo(pts[3][2]);
		path.lineTo(pts[3][3]);
		path.close();
		path.draw();
		path.moveTo(pts[4][0]);
		path.lineTo(pts[4][1]);
		path.lineTo(pts[4][2]);
		path.lineTo(pts[4][3]);
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
		path.moveTo(pts[2][0]);
		path.lineTo(pts[2][1]);
		path.lineTo(pts[2][2]);
		path.lineTo(pts[2][3]);
		path.close();
		path.draw();
		path.moveTo(pts[3][0]);
		path.lineTo(pts[3][1]);
		path.lineTo(pts[3][2]);
		path.lineTo(pts[3][3]);
		path.close();
		path.draw();
		path.moveTo(pts[4][0]);
		path.lineTo(pts[4][1]);
		path.lineTo(pts[4][2]);
		path.lineTo(pts[4][3]);
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
