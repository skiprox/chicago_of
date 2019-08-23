#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetCircleResolution(100);
	float width = ofGetWidth();
	float height = ofGetHeight();
	incrementer = 0;
	// vector<std::array<glm::vec2, 2>> pts;
	// pts.push_back(array<glm::vec2, 2> {{glm::vec2(0, 0), glm::vec2(width/2.1, height/2.2)}});
	// pts.push_back(array<glm::vec2, 2> {{glm::vec2(width/2.1, height/2.2), glm::vec2(width/1.3, 100)}});
	// dashedLines.push_back(DashedLine(pts, 1.0, ofColor(240, 40, 20), 250, true));
	// pts.clear();
	// pts.push_back(array<glm::vec2, 2> {{glm::vec2(0, height/1.1), glm::vec2(100, height/2)}});
	// pts.push_back(array<glm::vec2, 2> {{glm::vec2(98, height/2 - 2), glm::vec2(width/1.1, height/1.3)}});
	// dashedLines.push_back(DashedLine(pts, 4.0, ofColor(240, 40, 20), 250, true));
	// pts.clear();
	// pts.push_back(array<glm::vec2, 2> {{glm::vec2(width/1.1, height/3), glm::vec2(200, 100)}});
	// pts.push_back(array<glm::vec2, 2> {{glm::vec2(202, 102), glm::vec2(100, height/1.6)}});
	// dashedLines.push_back(DashedLine(pts, 10.0, ofColor(240, 40, 20), 250, true));
	vector<std::array<glm::vec2, 2>> pts;
	pts.push_back(array<glm::vec2, 2> {{glm::vec2(width/2.0, height), glm::vec2(width/2.0, 0)}});
	dashedLines.push_back(DashedLine(pts, 5.0, ofColor(240, 40, 20), 250, false));

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
