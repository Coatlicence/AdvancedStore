#include "ProductManufacturer.h"

/// Applies price to all Products in Store
void ProductManufacturer::SetPrice(float Price)
{
	vector<Product*> ProductList = gStore->GetProductList();

	for (int i = 0; i < ProductList.size(); i++)
	{
		if (ProductList[i]->GetProductManufacturerName()->Name == this->Name)
		{
			ProductList[i]->SetPrice(Price);
		}
	}

	
}

void ProductManufacturer::SetDiscount(float Percent)
{
}
