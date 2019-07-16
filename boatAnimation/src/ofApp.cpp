#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	boat.load("boat.png");
	float width = ofGetWidth();
	float height = ofGetHeight();
	boatAnimations.push_back(BoatAnimation(boat, glm::vec2(width/2.0, height/2.0 + 200), glm::vec2(500, 140)));
	boatAnimations.push_back(BoatAnimation(boat, glm::vec2(200, 200), glm::vec2(250, 70)));
	boatAnimations.push_back(BoatAnimation(boat, glm::vec2(width - 200, 400), glm::vec2(250, 70)));
	for (int i = 0; i < 6; i++) {
		waveAnimations.push_back(WaveAnimation(glm::vec2(0, (height/5.0) * i), glm::vec2(ofRandom(220.0, 250.0), ofRandom(30.0, 60.0))));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	if (fabs(universalCounter - TWO_PI) < 0.0001) {
		universalCounter = 0.0f;
	} else {
		universalCounter = (universalCounter + PI/100.0);
	}
	for (int j = 0; j < waveAnimations.size(); j++) {
		waveAnimations[j].update(universalCounter);
	}
	for (int i = 0; i < boatAnimations.size(); i++) {
		boatAnimations[i].update(universalCounter);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int j = 0; j < waveAnimations.size(); j++) {
		waveAnimations[j].draw();
	}
	for (int i = 0; i < boatAnimations.size(); i++) {
		boatAnimations[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
