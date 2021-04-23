#include "Store.h"

Store* gStore               = Store::GetStore();
Store* Store::StoreInstance = nullptr;


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

vector<Product*> Store::GetProductList()
{
    return ProductList;
}
