#include <string>
#include <GL/glut.h> 
#include <vector>
#include "dialogwindow.h"
#include "window.h"
#include <cstdlib>
#include <fstream>
#include <sstream>

#pragma once

void DialogWindow::InitDialogWindow()
{
    glutInitWindowSize(100, 50);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Dialog Window");
    glClearColor(1, 1, 1, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}


void DialogWindow::WriteText()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glColor3f(0, 0, 0);
    glRasterPos2f(0.25, 0.5);
    for (const auto& c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
    glFlush();
}

void DialogWindow::ReadText(std::ifstream& inp)
{
    inp >> text;
}