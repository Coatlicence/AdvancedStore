#pragma once
#include <string>
#include "Product.h"
#include "Store.h"
using namespace std;

class Product;

/// works with products
class ProductManufacturer abstract
{
public:
	string Name;

	virtual void SetPrice(float Price) = 0;

	virtual void SetDiscount(float Percent) = 0;


};

/// creates products
class ProductFactory abstract
{
public:
	virtual void CreateProduct() = 0;
};