#include "main.h"
#include "control.h"
#include "gameresult.h"
#include "gameover.h"
#include "gamestart.h"
#include "init.h"
#include "object.h"
#include "laberynth.h"

using namespace std;

// reset all variables
bool replay = false;
bool over = true;
float squareSize = 100.0;
float xIncrement = 0;
float yIncrement = 0;
int direction = -1;

vector<int> border = { 0, 0, 7, 1, 6, 1, 7, 5, 5, 5, 7, 7, 0, 6, 5, 7, 0, 1, 1, 6};
vector<int> obstacles = {2, 2, 3, 3, 3, 2, 5, 4, 1, 4, 4, 5};
vector<vector<bool>> bitmap;
vector<vector<int>> colormap;
bool* keyStates = new bool[256];

// main function
int main(int argc, char** argv){
	//initialize window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    //display mode
	glutInitWindowSize(600, 600);       // window size
	glutInitWindowPosition(300, 100);            //window position
	glutCreateWindow("Fill Maze");

	// define control
	glutDisplayFunc(display);       // renew display
	glutReshapeFunc(reshape);       // reshape
	glutIdleFunc(display);          // loop drawing
	glutKeyboardFunc(keyPressed);   // keyboard function
	glutKeyboardUpFunc(keyUp);//

	// main loop
	init();
	glutMainLoop();
	return 0;
}
