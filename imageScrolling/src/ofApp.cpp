#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetCircleResolution(100);
	width = ofGetWidth();
	height = ofGetHeight();
	cout << "WIDTH " << width << " HEIGHT " << height << endl;
	ofImage unabomberImg;
	// 16 pt font
	// unabomberImg.load("text-ft16.png");
	// unabomber = ImageScrolling(unabomberImg, glm::vec2(width/2.0, height/2.0), glm::vec2(785, 518));
	// 24 pt font
	// unabomberImg.load("text-ft24.png");
	// unabomber = ImageScrolling(unabomberImg, glm::vec2(width/2.0, height/2.0), glm::vec2(796, 1135));
	// 32 pt font
	// unabomberImg.load("text-ft32.png");
	// unabomber = ImageScrolling(unabomberImg, glm::vec2(width/2.0, height/2.0), glm::vec2(790, 2041));
	// 38 pt font
	unabomberImg.load("text-ft36-wide.png");
	unabomber = ImageScrolling(unabomberImg, glm::vec2(width/2.0, height/2.0), glm::vec2(1187, 1647));
	incrementer = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	incrementer++;
	unabomber.update(incrementer);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	// Draw up and down lines
	for (int i = 0; i < 2; i++) {
		ofDrawRectangle(width/3.0 * (i + 1) - 1, 0, 2, height);
		float divConst = 5.0;
		if (i == 0) {
			ofDrawRectangle(0, height/divConst, width, 2);
		} else {
			ofDrawRectangle(0, height - height/divConst, width, 2);
		}
	}
	unabomber.draw();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = 0;
}
