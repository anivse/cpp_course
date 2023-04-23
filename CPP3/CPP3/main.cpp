#include <GL/glut.h> 
#include "button.h"
#include "menu.h"
#include "window.h"
#include <vector>

#pragma once

Menu m;

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    m.DrawMenu();
    glFlush();
}


void Mouse(int Button, int State, int MouseX, int MouseY)
{
    Position mousePosition{ MouseX,MouseY };
    m.Push(Button, State, &mousePosition);
}

int main(int iArgc, char** cppArgv) 
{

    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);

    m.InitializeMainMenu();
    glutDisplayFunc(Draw);
    glutMouseFunc(Mouse);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    glutMainLoop();
    return 0;
}



