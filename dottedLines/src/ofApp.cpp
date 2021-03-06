#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	float width = ofGetWidth();
	float height = ofGetHeight();
	incrementer = 0;
	vector<std::array<glm::vec2, 2>> pts;
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(0, 0), glm::vec2(width/2.1, height/2.2)}});
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(width/2.1, height/2.2), glm::vec2(width/1.3, 100)}});
	dottedLines.push_back(DottedLine(pts, 3.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(0, height/1.1), glm::vec2(100, height/2)}});
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(98, height/2 - 2), glm::vec2(width/1.1, height/1.3)}});
	dottedLines.push_back(DottedLine(pts, 6.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
}

//--------------------------------------------------------------
void ofApp::update(){
	incrementer++;
	for (int i = 0; i < dottedLines.size(); i++) {
		dottedLines[i].update(incrementer);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < dottedLines.size(); i++) {
		dottedLines[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = 0;
}
