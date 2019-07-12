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

		ofPath path;

		int inc, incMax;

		float width, height;

		glm::vec2 pathStart, pathEnd;

		DashedLine dashedLine;
		
};
