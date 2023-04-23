#include <GL/glut.h> 
#include <vector>
#include "window.h"
#include "position.h"
#include <cstdlib>
#include <fstream>
#include <sstream>

#pragma once

void Window::InitWindow()
{
    glutInitWindowSize(500, 400);
    glutInitWindowPosition(position.x, position.y);
    glutCreateWindow("Menu");
    glClearColor(color.r, color.g, color.b, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void Window::ReadWindow(std::ifstream& inp)
{
    inp >> position.x;
    inp >> position.y;
    inp >> color.r;
    inp >> color.g;
    inp >> color.b;
}
