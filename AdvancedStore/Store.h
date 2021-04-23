#pragma once

#include <vector>
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

	/// This vector stores all of game products and 
	vector<Product*> ProductList;

public:
	void operator=(Store&) = delete;

	static Store* GetStore();

	vector<Product*> GetProductList();
};

extern Store* gStore;
