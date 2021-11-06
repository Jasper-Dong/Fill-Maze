#include "object.h"
#include "GL/gl.h"
#include "main.h"

// draw object
void drawObject(float positionX, float positionY){
	int x, y;

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);

    // radius
	for (int k = 0; k < 80; k++){
		x = (float)k / 2.0 * cos(30 * M_PI / 180.0) + (positionX*squareSize);
		y = (float)k / 2.0 * sin(30 * M_PI / 180.0) + (positionY*squareSize);
        // a whole circle
		for (int i = 0; i < 361; i++){
			glVertex2f(x, y);
			x = (float)k / 2.0 * cos(i * M_PI / 180.0) + (positionX*squareSize);
			y = (float)k / 2.0 * sin(i * M_PI / 180.0) + (positionY*squareSize);
			glVertex2f(x, y);
		}
	}
	glEnd();
}