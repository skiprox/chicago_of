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

		vector<std::array<glm::vec2, 4>> _pts;
		array<glm::vec2, 4> newPoints1, newPoints2, newPoints3, newPoints4;
		
};
