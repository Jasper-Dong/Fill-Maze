#include "init.h"
#include "main.h"

void initColorMap();

// initialize game
void init(void){
	// clear screen
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

    // reset keys
	for (int i = 0; i < 256; i++){
		keyStates[i] = false;
	}

	// set bitmap: true=not pass; false=pass
	bitmap.push_back({true, true, true, true, true, true, true});
    bitmap.push_back({true, false, false, false, true, false, true});
    bitmap.push_back({true, false, true, false, true, false, true});
    bitmap.push_back({true, false, true, true, true, false, true});
    bitmap.push_back({true, false, true, true, false, false, true});
    bitmap.push_back({true, false, false, false, false, true, true});
    bitmap.push_back({true, true, true, true, true, true, true});
}

// initialize map
void initColorMap() {
    vector<vector<int>> temp;
    // set colormap: -1=border/obstacles; 0=not passed; 1=passed
    temp.push_back({-1, -1, -1, -1, -1, -1, -1});
    temp.push_back({-1, 0, 0, 0, -1, 0, -1});
    temp.push_back({-1, 0, -1, 0, -1, 0, -1});
    temp.push_back({-1, 0, -1, -1, -1, 0, -1});
    temp.push_back({-1, 0, -1, -1, 0, 0, -1});
    temp.push_back({-1, 0, 0, 0, 0, -1, -1});
    temp.push_back({-1, -1, -1, -1, -1, -1, -1});

    colormap = temp;
}