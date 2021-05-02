#pragma once
#include <vector>
#include "ProgrammInterface.h"
#include "ProductManufacturer.h"
using namespace std;

class ProductManufacturer;
class ProgrammInterface;
class Player;
struct Account;

struct GlobalVariableContainer final
{

	/// All Licensors of the game
	vector<ProductManufacturer*> Licensors = 
	{
		new ProductManufacturer("Cock"),
	};

private:
	vector<ProgrammInterface*> Interfaces;

public:
	// fills Interfaces
	GlobalVariableContainer(vector<ProgrammInterface*> Interfaces);

	vector<ProgrammInterface*> GetInterfaces();
};

/// Stores main variables
extern GlobalVariableContainer* GlobalContainer;
