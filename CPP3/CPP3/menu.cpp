#include <GL/glut.h> 
#include "menu.h"
#include "button.h"
#include "window.h"
#include <vector>
#include <iostream>
#include <string>
#include "dialogwindow.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <functional>

#pragma once


void Menu::ReadFile(std::ifstream& inp)
{
	std::string str;
	int nSubMenu = 0;
	int nDialogWind = 0;
	w.ReadWindow(inp);
	inp >> numberbuttons;
	buttons.resize(numberbuttons);
	for (int i = 0;i < numberbuttons;i++)
	{
		buttons[i].ReadButton(inp);
		if (buttons[i].GetPush() == 1)
		{
			submenus.resize(nSubMenu + 1);
			submenus[nSubMenu].ReadFile(inp);
			buttons[i].SetNumberSubmenu(&nSubMenu);
			nSubMenu++;
		}
		if (buttons[i].GetPush() == 2)
		{
			dialogwindows.resize(nDialogWind + 1);
			dialogwindows[nDialogWind].ReadText(inp);
			buttons[i].SetNumberDialogWind(&nDialogWind);
			nDialogWind++;
		}
	}
	inp.close();
}

void Menu::InitializeMainMenu()
{
	std::ifstream inp("menu.txt");
	ReadFile(inp);
	w.InitWindow();
}

void Menu::InitializeSubMenu()
{
	w.InitWindow();
}


void Menu::DrawMenu()
{

	for (auto& b : buttons)
	{
		b.DrawButton();
	}

}

void Menu::Push(int Button, int State, Position* mousePosition)
{
	if (Button == GLUT_LEFT_BUTTON)
	{
		double x = (double)mousePosition->x / 500;
		double y = 1 - (double)mousePosition->y / 400;
		for (auto& b : buttons)
		{
			if (x <= b.GetX() + 0.1 && x >= b.GetX() - 0.1 && y <= b.GetY() + 0.05 && y >= b.GetY() - 0.05)
			{
				if (State == GLUT_DOWN)
				{
					if (b.GetPush() == 1)
					{
						submenus[b.GetNumberSubmenu()].InitializeSubMenu();
						glClear(GL_COLOR_BUFFER_BIT);
						glColor3f(1.0, 1.0, 1.0);
						submenus[b.GetNumberSubmenu()].DrawMenu();
						glFlush();
					}
					if (b.GetPush() == 2)
					{
						dialogwindows[b.GetNumberDialogWind()].InitDialogWindow();
						dialogwindows[b.GetNumberDialogWind()].WriteText();
					}
				}

			}
		}

	}

}

