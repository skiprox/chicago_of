#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	width = ofGetWidth();
	height = ofGetHeight();
	inc = 0;
	incMax = 250;
	pathStart = glm::vec2(800, 100);
	pathEnd = glm::vec2(100, 300);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	path.clear();
	path.setStrokeColor(ofColor(255, 40, 60));
	path.setFilled(false);
	path.setStrokeWidth(10);
	float distX = pathStart.x - pathEnd.x;
	float distY = pathStart.y - pathEnd.y;
	float segmentLenX = (distX/((float)incMax/10.0))/2.0;
	float segmentLenY = (distY/((float)incMax/10.0))/2.0;
	for (int i = 0; i < inc/10; i++) {
		float posX = ofLerp(pathStart.x, pathEnd.x, (float)i/((float)incMax/10.0));
		float posY = ofLerp(pathStart.y, pathEnd.y, (float)i/((float)incMax/10.0));
		path.moveTo(posX, posY);
		//path.moveTo(pathStart.x + (10 * i), pathStart.y + (10 * i));
		path.lineTo(posX + segmentLenX, posY + segmentLenY);
	}
	path.draw();
	if (inc < incMax) {
		inc++;
	}
	// path.clear();
	// path.setStrokeColor(ofColor(255, 40, 60));
	// path.setFilled(false);
	// path.setStrokeWidth(10);
	// path.moveTo(pathStart.x, pathStart.y);
	// path.lineTo(pathStart.x + 5, pathStart.y + 5);
	// path.moveTo(pathStart.x + 10, pathStart.y + 10);
	// path.lineTo(pathStart.x + 15, pathStart.y + 15);
	// path.moveTo(pathStart.x + 20, pathStart.y + 20);
	// path.lineTo(pathStart.x + 25, pathStart.y + 25);
	// path.moveTo(pathStart.x + 30, pathStart.y + 30);
	// path.lineTo(pathStart.x + 35, pathStart.y + 35);
	// path.moveTo(pathStart.x + 40, pathStart.y + 40);
	// path.lineTo(pathStart.x + 45, pathStart.y + 45);
	// path.draw();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	inc = 0;
}
