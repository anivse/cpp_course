#include <GL/glut.h>
#include <deque>
#include "point.h"
#pragma once

Point p;

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    p.Draw();
    glEnd();
    glFlush();
}

void Movement(int key, int x, int y)
{
    p.Movement(key);
}

void TimeFunc(int value) 
{
    p.FadingTrail();
    glutPostRedisplay();  
    glutTimerFunc(70, TimeFunc, 1);  
}

void Initialize() 
{
    glClearColor(0.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) 
{
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(" ");
    Initialize();
    glutDisplayFunc(Draw);
    glutIdleFunc(Draw);
    glutSpecialFunc(Movement);
    glutTimerFunc(70, TimeFunc, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    glutMainLoop();
    return 0;

}