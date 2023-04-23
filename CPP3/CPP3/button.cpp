#include <GL/glut.h>
#include "button.h"
#include "dialogwindow.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "position.h"
#pragma once


void Button::DrawButton()
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2f(position.x - 0.1, position.y - 0.05);
    glVertex2f(position.x - 0.1, position.y + 0.05);
    glVertex2f(position.x + 0.1, position.y + 0.05);
    glVertex2f(position.x + 0.1, position.y - 0.05);
    glEnd();
    WriteName();
}

void Button::ReadButton(std::ifstream& inp)
{
    inp >> name;
    inp >> push;
    inp >> position.x;
    inp >> position.y;
    inp >> color.r;
    inp >> color.g;
    inp >> color.b;
}

void Button::WriteName() {

    glColor3f(1, 1, 1);
    glRasterPos2f(position.x - 0.05, position.y);
    for (const auto& c : name) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
    
}

int Button::GetPush()
{
    return push;
}

double Button::GetX()
{
    return position.x;
}

double Button::GetY()
{
    return position.y;
}

int Button::GetNumberSubmenu()
{
    return nSubMenu;
}

int Button::GetNumberDialogWind()
{
    return nDialogWind;
}


void Button::SetNumberSubmenu(int* numberS)
{
    nSubMenu = *numberS;
}

void Button::SetNumberDialogWind(int* numberD)
{
    nDialogWind = *numberD;
}