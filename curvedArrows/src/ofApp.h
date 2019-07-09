#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);
		void mouseReleased(int x, int y, int button);

		ofPath path;

		float width, height;

		int incrementer = 0;
		float incMax = 250.0;
		
};
