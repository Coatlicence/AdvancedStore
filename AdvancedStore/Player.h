#pragma once

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "GlobalVariableContainer.h"
#include "ProgrammInterface.h"
#include "Product.h"
using namespace std;

struct GlobalVariableContainer;
class ProgrammInterface;


class Player final
{
public:
	bool Play = true;

	struct Account
	{
	public:
		Account();

		/// this is your money. Why its public? Because anyone can steal them
		float Budget;

		map<string, vector<Product*>*> ShoppingList;

	private:
		float MoneySpent;

	public:
		void CheckoutShoppingList();

		void AddMoneySpent(float& MoneySpentToAdd);

		float GetMoneySpent();

		void AddShoppingList(Product* product);

		map<string, vector<Product*>*>* GetShoppingList();
	};

	Account account;

private:
	int CurrentInterface = 0;

	// just use MethodDictionary from ProgrammInterface as pointer
	map<string, void(*)()>* MethodDictionary = nullptr;

public:
	~Player();

	Player();

	bool Input();

	void ChooseInterfaceChoosingMenu();

	// prints info of CurrentInterface
	void InterfaceMenuOpen();

	//// getters

	// get CurrentInterface
	ProgrammInterface* GetCurrentInterface();

	// get vector of interfaces
	vector<ProgrammInterface*> GetAllInterfaces();


	//// setters

	// uses pointer of interface MethodDictionary
	void SetMethodDictionary(map<string, void(*)()>& MethodDictionary);

	// sets Current Interfaces, can`t move out of range
	void SetCurrentInterface(unsigned int IndexOfInterfaceOnInterfaces);
};

