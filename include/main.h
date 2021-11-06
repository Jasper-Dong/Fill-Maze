#ifndef _MAIN_H_
#define _MAIN_H_
#include <vector>
#include <GL/glut.h>
#include <iostream>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <deque>
#include <stdlib.h>
using namespace std;

extern bool replay;         // check if replay game
extern bool over;           // check if game is over
extern float squareSize;    // one single square size
extern float xIncrement;    // X-coordinate
extern float yIncrement;    // Y-coordinate
extern int direction;       // object direction

extern vector<int> border;      // coordinate of border
extern vector<int> obstacles;   // coordinate of obstacles
extern vector<vector<bool>> bitmap;     // 2d vector: moving area
extern vector<vector<int>> colormap;     // 2d vector: filling maze
extern bool* keyStates;                 // keyboard states
#endif