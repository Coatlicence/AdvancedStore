#include "ProgrammInterface.h"



void ProgrammInterface::PrintInfo()
{
	map<string, void(*)()>::iterator I;

	int i = 1;

	for (I = MethodDictionary.begin(); I != MethodDictionary.end(); I++)
	{
		cout << i << ") " << I->first << endl;

		i++;
	}
}

void ProgrammInterface::InputProcess(Player* player, string& Command)
{
	int IndexCommand = stoi(Command) - 1;

	map<string, void(*)()>::iterator I = MethodDictionary.begin();

	for (int i = 0; i < MethodDictionary.size(); i++)
	{
		if (i == IndexCommand)
		{
			advance(I, IndexCommand);

			I->second();
		}
	}
}

void ProgrammInterface::UpdateScreen()
{
	system("cls");
}
