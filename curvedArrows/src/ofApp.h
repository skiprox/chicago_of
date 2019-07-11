#pragma once

#include "ofMain.h"
#include "CurvedArrow.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);
		void mouseReleased(int x, int y, int button);

		float width, height;

		ofColor red = ofColor(240, 40, 20);

		int incrementer = 0;
		float incMax = 250.0;

		CurvedArrow curvedArrow;
		
};
