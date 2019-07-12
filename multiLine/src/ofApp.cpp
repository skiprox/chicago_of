#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	float width = ofGetWidth();
	float height = ofGetHeight();
	newPoints1 = {{
		glm::vec2(width - 200, 40),
		glm::vec2(width - 220, 40),
		glm::vec2(width - 215, height - 20),
		glm::vec2(width - 205, height - 20)
	}};
	_pts.push_back(newPoints1);
	newPoints2 = {{
		glm::vec2(width - 205, height - 30),
		glm::vec2(width - 205, height - 20),
		glm::vec2(200, height - 22),
		glm::vec2(200, height - 28)
	}};
	_pts.push_back(newPoints2);
	newPoints3 = {{
		glm::vec2(208, height - 28),
		glm::vec2(200, height - 28),
		glm::vec2(202, 240),
		glm::vec2(206, 240)
	}};
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
