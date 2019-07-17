#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetCircleResolution(100);
	float width = ofGetWidth();
	float height = ofGetHeight();
	vector<std::array<glm::vec2, 2>> pts;
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(0, 0), glm::vec2(width/2.0, height/2.0)}});
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(width/2.0, height/2.0), glm::vec2(width/1.2, 100)}});
	lineArrows.push_back(LineArrow(pts, 1.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(0, height/1.1), glm::vec2(100, height/2)}});
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(98, height/2 - 2), glm::vec2(width/1.1, height/1.6)}});
	lineArrows.push_back(LineArrow(pts, 1.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(width/1.1, height/4), glm::vec2(200, 100)}});
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(202, 102), glm::vec2(100, height/1.6)}});
	lineArrows.push_back(LineArrow(pts, 4.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(width, height), glm::vec2(200, 240)}});
	lineArrows.push_back(LineArrow(pts, 4.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(200, height/1.1), glm::vec2(198, height/3)}});
	lineArrows.push_back(LineArrow(pts, 10.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(width, 200), glm::vec2(100, height/1.4)}});
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(98, height/1.4 + 2), glm::vec2(width/1.3, height/1.1)}});
	lineArrows.push_back(LineArrow(pts, 10.0, ofColor(240, 40, 20), 250, true));
}

//--------------------------------------------------------------
void ofApp::update(){
	incrementer++;
	for (int i = 0; i < lineArrows.size(); i++) {
		lineArrows[i].update(incrementer);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < lineArrows.size(); i++) {
		lineArrows[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = 0;
}
