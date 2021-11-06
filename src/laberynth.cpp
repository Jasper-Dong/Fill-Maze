#include "laberynth.h"
#include "main.h"

// draw border/obstacles
void drawLaberynth(){
	glColor3f(0.37, 0.37, 0.37);

    // border
	for (vector<int>::size_type i = 0; i < border.size(); i = i + 4){
		glRectf(border.at(i) * squareSize, border.at(i + 1)*squareSize, border.at(i + 2)*squareSize, border.at(i + 3)*squareSize);
	}

    // obstacles
	for (vector<int>::size_type k = 0; k < obstacles.size(); k = k + 4){
		glRectf(obstacles.at(k) * squareSize, obstacles.at(k + 1)*squareSize, obstacles.at(k + 2)*squareSize, obstacles.at(k + 3)*squareSize);
	}
}

// fill color for maze
void fillMaze(){

    for (int i=0; i<colormap.size(); i++){
        for (int j=0; j<colormap.at(i).size(); j++){
            if (colormap.at(i).at(j) == 1) {         // if pass
                glColor3f(0.8, 0.8, 0.0);
                glRectf( i * squareSize, j * squareSize, (i + 1)*squareSize, (j + 1)*squareSize);
            } else if (colormap.at(i).at(j) == 0) {  // not pass
                glColor3f(0.75, 0.75, 0.75);
                glRectf( i * squareSize, j * squareSize, (i + 1)*squareSize, (j + 1)*squareSize);
            }
        }
    }
}