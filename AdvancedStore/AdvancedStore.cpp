#include <iostream>
#include "Store.h"
#include "Product.h"

using namespace std;

ProductManufacturer Coc = ProductManufacturer("Coc");
ProductManufacturer Oco = ProductManufacturer("Oco");


int main()
{
	Coc.MakeProduct("Coca-product", 101.f);
	Coc.MakeProduct("Coca-product", 101.f);

	Oco.MakeProduct("Chips", 40.f);
	Oco.MakeProduct("Chips", 40.f);

	map<string, vector<Product*>>* List = gStore->GetProductList();

	map<string, vector<Product*>>::iterator it;

	for (it = List->begin(); it != List->end(); it++)
	{
		cout << it->first << " ";

		cout << it->second.size() << " ";

		cout << "made by: ";

		cout << it->second.back()->GetManufacturerName() << endl;
	}

	cout << endl;
}