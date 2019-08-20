#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	ofImage building;
	building.load("building-left.png");
	imgAnimation = ImageAnimation(building, glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0), glm::vec2(450, 418), incMax);
}

//--------------------------------------------------------------
void ofApp::update(){
	incrementer++;
	imgAnimation.update(incrementer);
}

//--------------------------------------------------------------
void ofApp::draw(){
	imgAnimation.draw();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	incrementer = 0;
}
