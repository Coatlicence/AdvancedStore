#include "ProductManufacturer.h"

void StandartSetPrice(float Price, string ProductName, string LicensorName)
{
	map<string, vector<Product*>>* ProductList = gStore->GetProductList();

	map<string, vector<Product*>>::iterator it;

	for (it = ProductList->begin(); it != ProductList->end(); it++)
	{
		string Name = it->second[0]->GetManufacturerName();

		if (Name == LicensorName)
			for (int i = 0; i < it->second.size(); i++)
			{
				it->second[i]->SetPrice(Price);
			}
	}
}

// range is [0.f, 10.f]; 1.f = 100%
void StandartSetDiscount(float Percent, string ProductName, string LicensorName)
{
	if (!((Percent > 0.f) and (Percent <= 10.f)))
	{
		cout << "Percent must be more than 0.f and less than 10.f" << endl;
	}

	map<string, vector<Product*>>* ProductList = gStore->GetProductList();

	map<string, vector<Product*>>::iterator it;

	for (it = ProductList->begin(); it != ProductList->end(); it++)
	{
		string Name = it->second[0]->GetManufacturerName();

		if (Name == LicensorName)
			for (int i = 0; i < it->second.size(); i++)
			{
				float NewPrice = it->second[i]->GetPrice() * Percent;

				it->second[i]->SetPrice(NewPrice);
			}
	}
}

ProductManufacturer::ProductManufacturer(string Name)
{
	SetPrice	= StandartSetPrice;
	SetDiscount = StandartSetDiscount;

	this->Name = Name;
}



void ProductManufacturer::MakeProduct(string Name, float Price)
{
	Product product = Product(Name, this->Name, Price);

	/// -----------------------------------------------------
	// Delivering product to Market
	
	map<string, vector<Product*>>* ProductList = gStore->GetProductList();

	map<string, vector<Product*>>::iterator it;

	/// trying to find product in counter
	for (it = ProductList->begin(); it != ProductList->end(); it++)
	{
		if (it->first == product.GetName())
		{
			it->second.push_back(&product);
			return;
		}
	}

	vector<Product*> vp;

	/// adding product to new counter
	ProductList->insert(make_pair(product.GetName(), vp));

	ProductList->at(product.GetName()).push_back(&product);
}



void ProductManufacturer::SetStrategySetPrice(void (*SetPrice)(float Price, string ProductName, string LicensorName))
{
	this->SetPrice = SetPrice;
}



void ProductManufacturer::SetStrategySetDiscount(void(*SetDiscount)(float Discount, string ProductName, string LicensorName))
{
	this->SetDiscount = SetDiscount;
}



