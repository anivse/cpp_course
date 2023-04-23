#include <GL/glut.h>
#include <deque>
#pragma once

class Point 
{

public:
	void Draw();
	void Movement(int key);
	void FadingTrail();

private:
	 struct pos_t
	{
		float x;
		float y;
	};
	pos_t pos{ 0.01f,0.01f };
	std::deque<pos_t> trail;
	float pSize = 0.01;
	float tSize = 0.005;
	void DrawTrail();
	void DrawPoint();
	void DrawQuad(pos_t pos, float radius);
};