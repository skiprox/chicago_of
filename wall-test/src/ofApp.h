#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"
#include "ofxSimpleSerial.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void drawBackground();
		void onNewMessage(string & message);
		void keyReleased(int key);
		void runAnimation(int animationNum);

		ofxSimpleSerial	mySerial;
		int baud = 57600;
		ofxPanel gui;
    	ofParameter<ofColor> colorOn;
    	ofParameter<ofColor> colorOff;
    	int serial1 = 0;
    	int serial2 = 0;

    	float width;
    	float height;

    	string message;

    	vector<int> serialInput;

    	std::array<int, 9> touchThreshold = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    	std::array<bool, 9> shouldRunAnimation = {false, false, false, false, false, false, false, false, false};
    	std::array<int, 9> animationCounter = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    	// bool shouldRunAnimation[9] = {false, false, false, false, false, false, false, false, false};
    	// int animationCounter[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		
};
