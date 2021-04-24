#pragma once

#include <string>
#include "ProductManufacturer.h"
using namespace std;

class ProductManufacturer;


class Product
{
public:

private:
	string Name;

	string ManufacturerName;

	float Price;
	
public:
	Product(string Name, string ManufacturerName, float Price);

	/// getters
	// Returns Name
	string GetName();

	string GetManufacturerName();

	float GetPrice();

	/// setters
	// Sets price to the product
	void SetPrice(float Price);
};

