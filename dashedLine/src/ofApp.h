#pragma once

#include "ofMain.h"
#include "DashedLine.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);
		void mouseReleased(int x, int y, int button);

		int incrementer = 0;
		int incMax = 250;

		vector<DashedLine> dashedLines;
		
};
