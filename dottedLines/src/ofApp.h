#pragma once

#include "ofMain.h"
#include "DottedLine.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);
		void mouseReleased(int x, int y, int button);

		int incrementer = 0;
		int incMax = 250;

		vector<DottedLine> dottedLines;
		
};
