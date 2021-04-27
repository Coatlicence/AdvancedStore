#include <iostream>
#include "Store.h"
#include "Product.h"
#include "Player.h"

using namespace std;

ProductManufacturer Coc = ProductManufacturer("Coc");
ProductManufacturer Oco = ProductManufacturer("Oco");


int main()
{
	
	Player player;

	while (player.Play)
	{
		player.InterfaceMenuOpen();

		player.Input();
	}
	/*
	Coc.MakeProduct("Coca-product", 101.f);
	Coc.MakeProduct("Coca-product", 101.f);

	Oco.MakeProduct("Chips", 40.f);
	Oco.MakeProduct("Chips", 40.f);

	map<string, vector<Product*>*>* List = gStore->GetProductList();

	map<string, vector<Product*>*>::iterator it;

	int a;
	
	cout << "Name" << "\t\t" << "Price" << "\t\t" << "Licensor" << "\t\t" << "Count" << endl << endl;

	for (it = List->begin(); it != List->end(); it++)
	{
		cout << it->first << " ";

		cout << it->second->size() << " ";

		cout << "\t\tmade by: ";

		cout << it->second->at(0)->GetManufacturerName() << endl;
	}

	cout << endl;
	*/

	//Player player;

	//while ()
}