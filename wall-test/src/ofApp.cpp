#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetCircleResolution(100);
	gui.setup();
	gui.add(colorOn.set("Color On", ofColor(101, 114, 235), ofColor(0, 0, 0), ofColor(255, 255, 255)));
	gui.add(colorOff.set("Color Off", ofColor(203, 255, 181), ofColor(0, 0, 0), ofColor(255, 255, 255)));
	width = ofGetWidth();
	height = ofGetHeight();
	mySerial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = mySerial.getDeviceList();
	mySerial.setup(0, baud); //open the first device
	mySerial.startContinuousRead();
	ofAddListener(mySerial.NEW_MESSAGE,this,&ofApp::onNewMessage);
	message = "";
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::onNewMessage(string & message)
{
	vector<string> input = ofSplitString(message, ",");
	serialInput.clear();
	for (int i = 0; i < input.size() - 1; i++) {
		serialInput.push_back(ofToInt(input[i]));
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	drawBackground();
}

//--------------------------------------------------------------
void ofApp::drawBackground(){
	ofBackground(0);
	ofSetColor(255);
	// Draw up and down lines
	ofDrawRectangle(width/3 - 5, 0, 10, height);
	ofDrawRectangle(width/3 * 2 - 5, 0, 10, height);
	// Draw left to right lines
	ofDrawRectangle(0, height/3 - 5, width, 10);
	ofDrawRectangle(0, height/3 * 2 - 5, width, 10);
	// Set the color in case we have none
	ofSetColor(ofColor(255, 80, 80));
	// Draw the circles
	for (int i = 0; i < serialInput.size(); i++) {
		if (serialInput[i] == 0) {
			ofSetColor(colorOff.get());
		} else {
			ofSetColor(colorOn.get());
		}
		ofDrawRectangle(i * width/3.0, 0, width/3.0, height/3.0);
		// Need to draw rectangles based on `i`
		// ofDrawRectangle(0, 0, width/3.0, height/3.0);
	}
	// ofDrawRectangle(0, 0, width/3.0, height/3.0);
	// ofDrawRectangle(width/3.0, 0, width/3.0, height/3.0);
}
