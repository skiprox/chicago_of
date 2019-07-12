#pragma once

#include "ofMain.h"
#include "DashedBox.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);
		void mouseReleased(int x, int y, int button);

		DashedBox dashedBox;

		int incrementer;

		float width, height;
		
};
