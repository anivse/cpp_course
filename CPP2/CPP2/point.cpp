#include <GL/glut.h>
#include <deque>
#include "point.h"
#pragma once


void Point::DrawQuad(pos_t pos, float radius)
{
    glBegin(GL_QUADS);
    glVertex2f(pos.x - radius, pos.y - radius);
    glVertex2f(pos.x - radius, pos.y + radius);
    glVertex2f(pos.x + radius, pos.y + radius);
    glVertex2f(pos.x + radius, pos.y - radius);
}

void Point::DrawPoint()
{
    glColor3f(0.5, 0.0, 0.5);
    DrawQuad(pos, pSize);
}

void Point::DrawTrail()
{
    if (!trail.empty())
    {
        glColor3f(0.0, 0.0, 0.0);
        for (auto& p : trail)
        {
            DrawQuad(p, tSize);
        }
    }
}

void Point::Draw() {

    DrawPoint();
    DrawTrail();
}

void Point::Movement(int key)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        trail.push_front(pos);
        pos.x -= 0.010f;
        break;
    case GLUT_KEY_RIGHT:
        trail.push_front(pos);
        pos.x += 0.010f;
        break;
    case GLUT_KEY_UP:
        trail.push_front(pos);
        pos.y += 0.010f;
        break;
    case GLUT_KEY_DOWN:
        trail.push_front(pos);
        pos.y -= 0.010f;
        break;
    }
}

void Point::FadingTrail() {
    if (!trail.empty())
    {
        trail.pop_back();
    }
}