#include <GL/glut.h> 
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "position.h"


#pragma once

struct color
{
	double r, g, b;
};

class Window
{
public:
	void InitWindow();
	void ReadWindow(std::ifstream& inp);
private:
	Position position;
	color color;
};