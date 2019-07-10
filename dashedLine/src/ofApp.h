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

		int inc, incMax;

		float width, height;

		glm::vec2 pathStart, pathEnd;
		
};
