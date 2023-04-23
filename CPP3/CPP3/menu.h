#include <GL/glut.h> 
#include "button.h"
#include "window.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include "dialogwindow.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
  

#pragma once

class Menu
{
public:
	void DrawMenu();
	void Push(int Button, int State, Position* mousePosition);
	void ReadFile(std::ifstream& inp);
	void InitializeMainMenu();
	void InitializeSubMenu();
private:
     std::vector<Button> buttons;
	 Window w;
	 int numberbuttons;
	 std::vector<Menu> submenus;
	 std::vector<DialogWindow> dialogwindows;
};