#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	incrementer = 0;
	vector<std::array<glm::vec2, 2>> pts;
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(0, 0), glm::vec2(400, 400)}});
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(400, 400), glm::vec2(800, 100)}});
	dashedLines.push_back(DashedLine(pts, 1.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(0, 800), glm::vec2(100, 400)}});
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(98, 398), glm::vec2(800, 600)}});
	dashedLines.push_back(DashedLine(pts, 5.0, ofColor(240, 40, 20), 250, true));
	pts.clear();
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(800, 300), glm::vec2(200, 100)}});
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(202, 102), glm::vec2(100, 600)}});
	dashedLines.push_back(DashedLine(pts, 10.0, ofColor(240, 40, 20), 250, true));
}

//--------------------------------------------------------------
void ofApp::update(){
	incrementer++;
	for (int i = 0; i < dashedLines.size(); i++) {
		dashedLines[i].update(incrementer);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < dashedLines.size(); i++) {
		dashedLines[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = 0;
}
