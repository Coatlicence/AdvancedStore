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
	map<string, vector<Product*>*> ProductStock;

public:
	void operator=(Store&) = delete;

	static Store* GetStore();

	map<string, vector<Product*>*>* GetProductStock();

	/// returns true if removed
	bool RemoveProductFromStore(Product* product);
};

extern Store* gStore;

