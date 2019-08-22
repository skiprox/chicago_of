#pragma once

#include "ofMain.h"
#include "TextScrolling.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mouseReleased(int x, int y, int button);

		TextScrolling unabomber;

		int incrementer;
		
};
