#include <string>
#include <GL/glut.h> 
#include <vector>
#include <string>
#include "button.h"
#include "window.h"

#pragma once

class DialogWindow
{
public:
	void ReadText(std::ifstream& inp);
	void InitDialogWindow();
	void WriteText();
private:
	std::string text;
};