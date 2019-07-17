#pragma once

#include "ofMain.h"
#include "LineArrow.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mouseReleased(int x, int y, int button);
		
		int incrementer = 0;
		int incMax = 250;

		vector<LineArrow> lineArrows;
};
