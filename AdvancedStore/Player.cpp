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

	cout << endl << endl;
	cout << "money: " << account.Budget << endl;

	Interface = nullptr;
}



void Player::SetMethodDictionary(map<string, void(*)()>& MethodDictionary)
{
	this->MethodDictionary = &MethodDictionary;
}


/// can`t set 0, cuz setting to 0 permanently moves player to choosing interfaces menu
// for opening choosing interfaces menu check Player::Input();
void Player::SetCurrentInterface(unsigned int IndexOfInterfaceOnInterfaces)
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
	return GlobalContainer->GetInterfaces();
}

Player::Account::Account()
{
	this->Budget = 50000.f;

	this->MoneySpent = 0.f;

	this->ShoppingList = map<string, vector<Product*>*>();
}

void Player::Account::CheckoutShoppingList()
{
	float MoneyToAdd = 0;

	map<string, vector<Product*>*>::iterator it;

	for (it = ShoppingList.begin(); it != ShoppingList.end(); it++)
	{
		for (int i = 0; i < it->second->size(); i++)
		{
			Product* p = it->second->at(i);

			MoneyToAdd += p->GetPrice();

			delete p;
		}

		it->second->~vector();
	}

	ShoppingList.clear();

	AddMoneySpent(MoneyToAdd);

	Budget -= MoneyToAdd;
}

void Player::Account::AddMoneySpent(float& MoneySpentToAdd)
{
	if (MoneySpentToAdd > 0)
	{
		this->MoneySpent += MoneySpentToAdd;
	}
	else return;
}

float Player::Account::GetMoneySpent()
{
	return MoneySpent;
}

void Player::Account::AddShoppingList(Product* product)
{
	map<string, vector<Product*>*>::iterator it = ShoppingList.find(product->GetName());

	if (it != ShoppingList.end())
	{
		it->second->push_back(product);
	}
	else
	{
		vector<Product*>* v = new vector<Product*>();

		v->push_back(product);

		ShoppingList.insert(make_pair(product->GetName(), v));
	}
}

map<string, vector<Product*>*>* Player::Account::GetShoppingList()
{
	return &ShoppingList;
}
