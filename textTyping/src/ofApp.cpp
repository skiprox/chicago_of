#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	float width = ofGetWidth();
	float height = ofGetHeight();
	textTyping = TextTyping("A spectre is haunting Europe - the spectre of communism.\nAll the powers of old Europe have entered into a holy\nalliance to exorcise this spectre: Pope and Tsar,\nMetternich and Guizot, French Radicals and German police-spies.", glm::vec2(width/2.0, height/2.0), ofColor(20), 28, 850);
	backgroundTyping = TextTyping("A spectre is haunting Europe - the spectre of communism.\nAll the powers of old Europe have entered into a holy\nalliance to exorcise this spectre: Pope and Tsar,\nMetternich and Guizot, French Radicals and German police-spies.", glm::vec2(width/2.0 + 2, height/2.0 + 1), ofColor(240, 40, 20), 28, 850);
	incrementer = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	incrementer++;
	backgroundTyping.update(incrementer);
	textTyping.update(incrementer);
}

//--------------------------------------------------------------
void ofApp::draw(){
	// backgroundTyping.draw();
	textTyping.draw();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = 0;
}
