#include "Player.h"


Player::~Player()
{

}



Player::Player()
{

}



bool Player::Input()
{
	string Command;

	cout << "Command ";
	cin >> Command;

	// end the game
	if (Command == "x")
	{
		Play = false; 
		
		system("cls");
		return true;
	}

	// open interface choosing menu
	if (Command == "q")
	{
		ChooseInterfaceChoosingMenu(); // interface marked by zero always must equals MenuChooseInterface

		system("cls");
		return true;
	}
	
	GetCurrentInterface()->InputProcess(this, Command);

	return true;
}



void Player::ChooseInterfaceChoosingMenu()
{
	CurrentInterface = 0;
}



void Player::InterfaceMenuOpen()
{
	ProgrammInterface* Interface = GetCurrentInterface();

	Interface->PrintInfo();

	Interface = nullptr;
}



void Player::SetMethodDictionary(map<string, void(*)()> &MethodDictionary)
{
	this->MethodDictionary = &MethodDictionary;
}


/// can`t set 0, cuz setting to 0 permanently moves player to choosing interfaces menu
// for opening choosing interfaces menu check Player::Input();
void Player::SetCurrentInterface(int& IndexOfInterfaceOnInterfaces)
{
	if ((IndexOfInterfaceOnInterfaces > 0) and (IndexOfInterfaceOnInterfaces < GetAllInterfaces().size()))
	{
		CurrentInterface = IndexOfInterfaceOnInterfaces;

		SetMethodDictionary(GetCurrentInterface()->MethodDictionary);
	}
}



ProgrammInterface* Player::GetCurrentInterface()
{
	return GetAllInterfaces().at(CurrentInterface);
}



vector<ProgrammInterface*> Player::GetAllInterfaces()
{
	return GlobalContainer.GetInterfaces();
}

