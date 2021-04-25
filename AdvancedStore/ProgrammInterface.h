#pragma once

#include <map>
#include <string>
#include <iostream>
#include "GlobalVariableContainer.h"
#include "Player.h"
using namespace std;

struct GlobalVariableContainer;
class Player;

class ProgrammInterface abstract
{
public:
	map<string, void(*)()> MethodDictionary;
	
	string Name;

private:

public:
	// Prints important info
	virtual void PrintInfo() = 0;

	// processes Player::Input and reacts on Command
	virtual void InputProcess(Player* player, string& Command) = 0;

protected:
	// system("cls");
	void UpdateScreen();

}; 
