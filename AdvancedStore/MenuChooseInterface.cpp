#include "MenuChooseInterface.h"
#include <iostream>

MenuChooseInterface::MenuChooseInterface()// : ProgrammInterface::ProgrammInterface(GlobalContainer)
{
	Name = "Choosing menu";
}

void MenuChooseInterface::PrintInfo()
{
	cout << "q - to open this menu\n";
	cout << "x - to close the game\n\n";

	cout << "Choose interface: \n\n";

	vector<ProgrammInterface*> ArrayOfInterfaces = GlobalContainer->GetInterfaces();

	for (int i = 1; i < ArrayOfInterfaces.size(); i++)
	{
		cout << i << ") " << ArrayOfInterfaces[i]->Name << endl;
	}
}

void MenuChooseInterface::InputProcess(Player* player, string& Command)
{
	int IndexCommand = stoi(Command);

	player->SetCurrentInterface(IndexCommand);

	UpdateScreen();
}
