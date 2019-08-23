#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofImage building;
	building.load("building.png");
	float width = ofGetWidth();
	float height = ofGetHeight();
	imgMovement = ImageMovement(building, glm::vec2(225, 210), glm::vec2(width/2.0, height - 105), glm::vec2(width/2.0, 105), 250);
}

//--------------------------------------------------------------
void ofApp::update(){
	incrementer++;
	imgMovement.update(incrementer);
}

//--------------------------------------------------------------
void ofApp::draw(){
	imgMovement.draw();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	incrementer = 0;
}
