#pragma once
#include "ProgrammInterface.h"
#include "GlobalVariableContainer.h"

class OnStoreInterface : public ProgrammInterface
{
public:
	map<string, vector<Product*>*>* ProductStock;

private:	

public:
	OnStoreInterface();

	void PrintInfo() override;

	void InputProcess(Player* player, string& Command) override;

private:
	/// just fills ProductStock, called in constructor
	void SetProductStock();
};
