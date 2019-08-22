#pragma once

#include "ofMain.h"
#include "ImageScrolling.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mouseReleased(int x, int y, int button);

		ImageScrolling unabomber;

		int incrementer;
		
};
