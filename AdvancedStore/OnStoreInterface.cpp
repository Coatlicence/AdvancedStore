#include "OnStoreInterface.h"

void AddProductToStock()
{
	system("cls");

	vector<ProductManufacturer*> Licensors = GlobalContainer->Licensors;

	for (int i = 0; i < Licensors.size(); i++)
	{
		cout << (i + 1) << ") " << Licensors[i]->Name;
		cout << endl;
	}

	cout << endl;

	cout << "Choose Licensor \nIndex: ";
	int IndexOfLicensors;
	cin >> IndexOfLicensors;

	IndexOfLicensors--;

	cout << "Print name of product \nName: ";
	string NameOfProduct;
	cin >> NameOfProduct;

	float Price;
	cout << "Print price of product \nPrice: ";
	cin >> Price;

	Licensors[IndexOfLicensors]->MakeProduct(NameOfProduct, Price);

	system("cls");

	cout << "New product of " << Licensors[IndexOfLicensors]->Name << endl;
	cout << NameOfProduct << " for the price of " << Price << endl;
	cout << "Was made" << endl << endl;
}

void ShowProductStock()
{
	map<string, vector<Product*>*>* Stock = gStore->GetProductStock();

	map<string, vector<Product*>*>::const_iterator it;

	int i = 1;

	for (it = Stock->cbegin(); it != Stock->cend(); it++)
	{
		Product* ProductInstance = it->second->back();

		string ProductName = it->first;

		size_t ProductNumber = it->second->size();

		cout << i << ") " << ProductName << " for: " << ProductInstance->GetPrice() << "\tcount in stock: " << ProductNumber << endl;

		i++;
	}
}

OnStoreInterface::OnStoreInterface()
{
	Name = "Store";
	
	MethodDictionary["New Product"] = AddProductToStock;
	MethodDictionary["Open Store"]	= ShowProductStock;
}

void OnStoreInterface::PrintInfo()
{
	UpdateScreen();

	cout << "Print c\n to checkout ShoppingList\n\n";

	MethodDictionary["Open Store"]();

}

void OnStoreInterface::InputProcess(Player* player, string& Command)
{
	if (Command == "c")
	{
		player->account.CheckoutShoppingList();

		cout << player->account.Budget << endl;

		return;
	}

	map<string, vector<Product*>*>* Stock = gStore->GetProductStock();

	map<string, vector<Product*>*>::const_iterator it = Stock->cbegin();

	for (int i = 0; i < Stock->size(); i++)
	{
		if (i == (stoi(Command) - 1))
		{
			advance(it, i);
			
			player->account.AddShoppingList(it->second->back());
			
			gStore->RemoveProductFromStore(it->second->back());

			break;
		}
	}

	//player->account.
}

void OnStoreInterface::SetProductStock()
{
	ProductStock = gStore->GetProductStock();
	
	//GlobalContainer.Licensors[0] = new ProductManufacturer("Coc");

	GlobalContainer->Licensors.back()->MakeProduct("Dick", 10000.f);
}