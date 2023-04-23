#include <GL/glut.h> 
#include <string>
#include <vector>
#include "window.h"
#include "position.h"

#pragma once


class Button
{
public:
	void DrawButton();
	void ReadButton(std::ifstream& inp);
	int GetPush();
	double GetX();
	double GetY();
	int GetNumberSubmenu();
	int GetNumberDialogWind();
	void SetNumberSubmenu(int* numberS);
	void SetNumberDialogWind(int* numberD);
private:
	int push;
	int nSubMenu;
	int nDialogWind;
	Position position;
	std::string name;
	color color;
	void WriteName();
};