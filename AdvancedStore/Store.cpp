#include "Store.h"

Store* Store::StoreInstance = nullptr;
Store* gStore               = Store::GetStore();

Store::Store()
{
}

Store::~Store()
{
    map<string, vector<Product*>*>::iterator it;

    for (it = ProductList.begin(); it != ProductList.end(); it++)
    {
        for (int i = 0; i < it->second->size(); i++)
        {
            delete it->second->at(i);
        }

        it->second->~vector();
    }
}

Store* Store::GetStore()
{
    if (StoreInstance == nullptr)
    {
        StoreInstance = new Store();
    }

    return StoreInstance;
}

map<string, vector<Product*>*>* Store::GetProductList()
{
    return &ProductList;
}