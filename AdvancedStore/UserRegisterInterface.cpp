#include "UserRegisterInterface.h"

void NewAccount()
{
	cout << "User account created" << endl;
}

void DeleteAccount()
{
	cout << "User account deleted" << endl;

}

void Exit()
{
	cout << "Exited" << endl;
	system("cls");
}


UserRegisterInterface::UserRegisterInterface()
{
	Name = "User Register Interface";

	MethodDictionary["New Account"]		= NewAccount;
	MethodDictionary["Delete Account"]	= DeleteAccount;
	MethodDictionary["Exit"]			= Exit;

}

void UserRegisterInterface::PrintInfo()
{
	cout << Name << endl;

	cout << "Choose an item: \n";

	int i = 1;

	for (map<string, void(*)()>::iterator it = MethodDictionary.begin(); it != MethodDictionary.end(); it++)
	{
		cout << i << ") " << it->first << endl;

		i++;
	}
}

void UserRegisterInterface::InputProcess(Player* player, string& Command)
{
	
}
