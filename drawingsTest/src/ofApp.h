#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
#include "ofxVectorGraphics.h"

#ifndef PI
#define PI  3.14159265
#endif

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);

		float width;
		float height;

		ofxVectorGraphics output;

		vector <ofVec2f> pts;
		
};
