#pragma once

#include <string>
#include "ProductManufacturer.h"
using namespace std;

class ProductManufacturer;


class Product abstract
{
public:

private:
	string Name;

	ProductManufacturer* ProductManufacturerName;

	float Price;
	
public:
	Product(string& Name, ProductManufacturer* ProductManufacturerName, float Price);

	/// getters
	// Returns Name
	string GetName();

	ProductManufacturer* GetProductManufacturerName();

	float GetPrice();

	/// setters
	// Sets price to the product
	void SetPrice(float Price);

	// Percent must be in range [0.f, 100.f]
	virtual void SetDiscount(float Percent) = 0;
};

