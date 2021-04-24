#include "Store.h"

Store* Store::StoreInstance = nullptr;
Store* gStore               = Store::GetStore();

Store::Store()
{
}

Store::~Store()
{
}

Store* Store::GetStore()
{
    if (StoreInstance == nullptr)
    {
        StoreInstance = new Store();
    }

    return StoreInstance;
}

map<string, vector<Product*>>* Store::GetProductList()
{
    return &ProductList;
}