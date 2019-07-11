#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	float width = ofGetWidth();
	float height = ofGetHeight();
	vector<std::array<glm::vec2, 4>> _pts;
	array<glm::vec2, 4> newPoints1 = {glm::vec2(50, height/2 - 50), glm::vec2(50, height/2 + 50), glm::vec2(width - 50, height/2 + 25), glm::vec2(width - 50, height/2 - 25)};
	_pts.push_back(newPoints1);
	array<glm::vec2, 4> newPoints2 = {glm::vec2(width - 100, height/2 - 25), glm::vec2(width - 50, height/2 - 25), glm::vec2(width - 60, 50), glm::vec2(width - 90, 50)};
	_pts.push_back(newPoints2);
	array<glm::vec2, 4> newPoints3 = {glm::vec2(width - 90, 50), glm::vec2(width - 90, 70), glm::vec2(200, 65), glm::vec2(200, 55)};
	_pts.push_back(newPoints3);
	multiLine = MultiLine(_pts, ofColor(240, 60, 40), 250);
}

//--------------------------------------------------------------
void ofApp::update(){
	incrementer++;
	multiLine.update(incrementer);
}

//--------------------------------------------------------------
void ofApp::draw(){
	multiLine.draw();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = 0;
}
