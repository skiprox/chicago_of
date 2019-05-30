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
		
};
