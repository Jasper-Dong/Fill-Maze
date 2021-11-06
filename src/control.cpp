#include "control.h"
#include "main.h"
#include "object.h"
#include "init.h"

// setting key functions
void keyPressed(unsigned char key, int x, int y){
	keyStates[key] = true;
}

void keyUp(unsigned char key, int x, int y){
	keyStates[key] = false;
}

// reset all elements
void resetGame(){
	over = false;
	xIncrement = 1;
	yIncrement = 1;
	for (int i = 0; i < 256; i++){
		keyStates[i] = false;
	}
}

// control object moving
void keyOperations(){
	// change moving direction by pressing keys
    // default value: -1
	if (keyStates['a']){
        if (direction == -1)
            direction = 0 ;
	}
	if (keyStates['d']){
        if (direction == -1)
            direction = 1;
	}
	if (keyStates['w']){
        if (direction == -1)
            direction = 2;
	}
	if (keyStates['s']){
        if (direction == -1)
            direction = 3;
	}
    // space key
	if (keyStates[' ']){
		if (!replay && over){
			resetGame();
            initColorMap();
			replay = true;
		}
		else if (replay && over){
			replay = false;
            over = true;
		}
	}
    // escape key
    if (keyStates[27]) {
        if (replay && over) {
            exit(0);
        }
    }
}

// move object
void moveObject() {
    // get current locations
    float x = (0.5 + xIncrement) * squareSize;
    float y = (0.5 + yIncrement) * squareSize;

    // change object coordinates until border
    if (direction == 0){
        x -= 2;
        int x1Quadrant = (int)((x - 50.0 *cos(360 * M_PI / 180.0)) / squareSize);
        if (!bitmap.at(x1Quadrant).at((int) y / squareSize)){
            xIncrement -= 5 / squareSize;
        } else {
            direction = -1;
        }
    }
    if (direction == 1){
        x += 2;
        int x2Quadrant = (int)((x + 50.0 *cos(360 * M_PI / 180.0)) / squareSize);
        if (!bitmap.at(x2Quadrant).at((int)y / squareSize)){
            xIncrement += 5 / squareSize;
        } else {
            direction = -1;
        }
    }
    if (direction == 2){
        y -= 2;
        int y1Quadrant = (int)((y - 50.0 *cos(360 * M_PI / 180.0)) / squareSize);
        if (!bitmap.at((int)x / squareSize).at(y1Quadrant)){
            yIncrement -= 5 / squareSize;
        } else {
            direction = -1;
        }
    }
    if (direction == 3){
        y += 2;
        int y2Quadrant = (int)((y + 50.0 *cos(360 * M_PI / 180.0)) / squareSize);
        if (!bitmap.at((int) x / squareSize).at(y2Quadrant)){
            yIncrement += 5 / squareSize;
        } else {
            direction = -1;
        }
    }
}

// save the maze that object moved
void saveMaze(){
    // get current locations
    int index_x = (int) (0.5 + xIncrement);
    int index_y = (int) (0.5 + yIncrement);
    // mark color map
    if (direction >= 0){
        if (!colormap.at(index_x).at(index_y)){
            //glColor3f(1, 0.2, 0.4);
            colormap.at(index_x).at(index_y) = 1;
        }
    }
}