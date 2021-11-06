#include "gameresult.h"
#include "main.h"

// display result
void resultsDisplay(){
    string message = "*************************************";
    string::iterator it = message.begin();
    glRasterPos2f(80, 100);
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
    message = "CONGRATULATIONS! ";
    glColor3f(0.16, 0.14, 0.12);
    glRasterPos2f(180, 200);
    it = message.begin();
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
    message = "*************************************";
    glRasterPos2f(80, 300);
    it = message.begin();
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
    message = "# To restart the game: press the Space key.";
    glRasterPos2f(120, 400);
    it = message.begin();
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
    message = "# To exit the game: press the Escape key.";
    glRasterPos2f(120, 500);
    it = message.begin();
    while (it!=message.end())
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
}
