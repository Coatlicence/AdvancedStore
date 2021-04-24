#pragma once

#include <vector>
#include <map>
#include "Product.h"
using namespace std;

class Product;

/// only one instance allowed
class Store
{
private:
	Store();

	~Store();

	static Store* StoreInstance;

	/// This vector stores all of game products
	map<string, vector<Product*>> ProductList;

public:
	void operator=(Store&) = delete;

	static Store* GetStore();

	map<string, vector<Product*>>* GetProductList();
};

extern Store* gStore;
