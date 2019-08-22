#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetCircleResolution(100);
	float width = ofGetWidth();
	float height = ofGetHeight();
	ofImage unabomberImg;
	// 16 pt font
	// unabomberImg.load("text-ft16.png");
	// unabomber = ImageScrolling(unabomberImg, glm::vec2(width/2.0, height/2.0), glm::vec2(785, 518));
	// 24 pt font
	// unabomberImg.load("text-ft24.png");
	// unabomber = ImageScrolling(unabomberImg, glm::vec2(width/2.0, height/2.0), glm::vec2(796, 1135));
	// 32 pt font
	unabomberImg.load("text-ft32.png");
	unabomber = ImageScrolling(unabomberImg, glm::vec2(width/2.0, height/2.0), glm::vec2(790, 2041));
	// 38 pt font
	// unabomberImg.load("text-ft36.png");
	// unabomber = ImageScrolling(unabomberImg, glm::vec2(width/2.0, height/2.0), glm::vec2(792, 2457));
	incrementer = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	incrementer++;
	unabomber.update(incrementer);
}

//--------------------------------------------------------------
void ofApp::draw(){
	unabomber.draw();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = 0;
}
