#pragma once
#include <string>
#include <iostream>
#include "Product.h"
#include "Store.h"
using namespace std;

class Product;

class ProductManufacturer
{
private:
	/// Works by ProductManufacturer::Name
	void (*SetPrice)	(float Price,	string ProductName, string LicensorName);

	void (*SetDiscount)	(float Discount,string ProductName, string LicensorName);

public:
	ProductManufacturer(string Name);

	string Name;

	void MakeProduct(string Name, float Price);

	///--------------------------------------------------------------
	// Setters

	/*	To change method just type in argument a 
	 *	non-namespace(declared outside of classes) 
	 *	function without operator() 
	 */

	void SetStrategySetPrice	(void (*SetPrice)(float Price, string ProductName, string LicensorName));

	void SetStrategySetDiscount	(void (*SetDiscount)(float Discount, string ProductName, string LicensorName));
};