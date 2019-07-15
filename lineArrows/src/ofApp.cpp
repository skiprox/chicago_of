#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetCircleResolution(100);
	vector<std::array<glm::vec2, 2>> pts;
	array<glm::vec2, 2> newPoints1 = {{glm::vec2(0, 0), glm::vec2(400, 400)}};
	pts.push_back(newPoints1);
	array<glm::vec2, 2> newPoints2 = {{glm::vec2(398, 398), glm::vec2(800, 100)}};
	pts.push_back(newPoints2);
	lineArrow = LineArrow(pts, 10.0, ofColor(240, 40, 20), 250);
}

//--------------------------------------------------------------
void ofApp::update(){
	incrementer++;
	lineArrow.update(incrementer);
}

//--------------------------------------------------------------
void ofApp::draw(){
	lineArrow.draw();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = 0;
}
