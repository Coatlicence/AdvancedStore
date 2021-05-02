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
	void (*SetPrice)	(float Price, string LicensorName, string ProductName);

	void (*SetDiscount)	(float Discount, string LicensorName, string ProductName);

public:
	ProductManufacturer(string Name);

	string Name;

	void MakeProduct(string Name, float Price);

	///--------------------------------------------------------------
	// Setters

	/*	To change method just type in argument a 
	 *	non-namespace(declared outside of classes) 
	 *	function without operator() with given signature
	 */
	void SetStrategySetPrice	(void (*SetPrice)(float Price, string LicensorName, string ProductName));

	/*	To change method just type in argument a
	 *	non-namespace(declared outside of classes)
	 *	function without operator() with given signature
	 */
	void SetStrategySetDiscount	(void (*SetDiscount)(float Discount, string LicensorName, string ProductName));

	void SetPriceToAllProducts(float Price);

	void SetDiscountToAllProducts(float Discount);

};