#include "gamestart.h"
#include "object.h"
#include "laberynth.h"
#include "main.h"
#include "gameover.h"
#include "gameresult.h"
#include "control.h"

void moveObject();

// display window and elements
void display(){
    keyOperations();
    gameOver();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);       //clear color buffer
	if (replay){
		if (!over){
			drawLaberynth();
            moveObject();
            saveMaze();
            fillMaze();
            drawObject(0.5 + xIncrement, 0.5 + yIncrement);
		}
		else {
			resultsDisplay();
		}
	}
	else {
		welcomeScreen();
	}
	glutSwapBuffers();
}

// reshape
void reshape(int w, int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glOrtho(0, 700, 700, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// welcome page
void welcomeScreen(){
    glClearColor(0.75, 0.75, 0.75, 1.0);
    string message = "*************************************";
    string::iterator it = message.begin();
    glRasterPos2f(80, 100);
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
    message = "The Fill Maze Game";
    glColor3f(0.16, 0.14, 0.12);
    glRasterPos2f(220, 200);
    it = message.begin();
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
    message = "*************************************";
    glRasterPos2f(80, 300);
    it = message.begin();
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
    message = "# To control the object moving:";
    glRasterPos2f(100, 350);
    it = message.begin();
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
    message = "A: Left;    D: Right;    W: Up;    S: Down.";
    glRasterPos2f(150, 400);
    it = message.begin();
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
    message = "# To start or restart the game:";
    glRasterPos2f(100, 450);
    it = message.begin();
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
    message = "Press the Space key.";
    glRasterPos2f(150, 500);
    it = message.begin();
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
    message = "By Jasper";
    glRasterPos2f(480, 600);
    it = message.begin();
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
}
