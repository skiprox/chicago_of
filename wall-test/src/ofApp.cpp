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
	// Run through the `shouldRunAnimation` array, and run any of the animations that we should
	for (int i = 0; i < shouldRunAnimation.size(); i++) {
		if (shouldRunAnimation[i]) {
			animationCounter[i]++;
			if (animationCounter[i] < 500) {
				runAnimation(i + 1);
			} else {
				shouldRunAnimation[i] = false;
				animationCounter[i] = 0;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	// Keys 1 through 9 are 49 through 57
	// so use this to determine the index of the animation we should run
	if (key >= 49 && key <= 57) {
		int keyIndex = key - 49;
		shouldRunAnimation[keyIndex] = true;
	}
}

//--------------------------------------------------------------
void ofApp::runAnimation(int animationNum){
	ofSetColor(colorOn.get());
	switch(animationNum) {
		case 1:
			ofDrawRectangle(0, 0, width/3.0, height/3.0);
			break;
		case 2:
			ofDrawRectangle(width/3.0, 0, width/3.0, height/3.0);
			break;
		case 3:
			ofDrawRectangle(width/3.0 * 2, 0, width/3.0, height/3.0);
			break;
		case 4:
			ofDrawRectangle(0, height/3.0, width/3.0, height/3.0);
			break;
		case 5:
			ofDrawRectangle(width/3.0, height/3.0, width/3.0, height/3.0);
			break;
		case 6:
			ofDrawRectangle(width/3.0 * 2, height/3.0, width/3.0, height/3.0);
			break;
		case 7:
			ofDrawRectangle(0, height/3.0 * 2, width/3.0, height/3.0);
			break;
		case 8:
			ofDrawRectangle(width/3.0, height/3.0 * 2, width/3.0, height/3.0);
			break;
		case 9:
			ofDrawRectangle(width/3.0 * 2, height/3.0 * 2, width/3.0, height/3.0);
			break;
		default:
			cout << "WHAT FUCKING KEY IS THIS?? " << animationNum << endl;
			break;
	}
}
