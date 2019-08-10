#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	myPlayer.load("movies/water-small.mov");
	overlay.load("images/overlay.png");
	myPlayer.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	myPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	// ofPushMatrix();
	// ofScale(2.0, 2.0);
	myPlayer.draw(0, 0, ofGetWidth(), ofGetHeight());
	// ofPopMatrix();
	overlay.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
