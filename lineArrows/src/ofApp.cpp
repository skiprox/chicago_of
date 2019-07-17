#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetCircleResolution(100);
	vector<std::array<glm::vec2, 2>> pts;
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(0, 0), glm::vec2(400, 400)}});
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(400, 400), glm::vec2(800, 100)}});
	lineArrows.push_back(LineArrow(pts, 1.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(0, 800), glm::vec2(100, 400)}});
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(98, 398), glm::vec2(800, 600)}});
	lineArrows.push_back(LineArrow(pts, 5.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(800, 300), glm::vec2(200, 100)}});
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(202, 102), glm::vec2(100, 600)}});
	lineArrows.push_back(LineArrow(pts, 10.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(800, 800), glm::vec2(200, 240)}});
	lineArrows.push_back(LineArrow(pts, 10.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(200, 800), glm::vec2(198, 300)}});
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
