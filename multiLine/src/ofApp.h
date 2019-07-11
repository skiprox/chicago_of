#pragma once

#include "ofMain.h"
#include "MultiLine.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);
		void mouseReleased(int x, int y, int button);

		MultiLine multiLine;

		int incrementer = 0;
		
};
