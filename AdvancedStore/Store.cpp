#include "Store.h"

Store* Store::StoreInstance = nullptr;
Store* gStore               = Store::GetStore();

Store::Store()
{
    ProductStock = map<string, vector<Product*>*>();
}

Store::~Store()
{
    map<string, vector<Product*>*>::iterator it;

    for (it = ProductStock.begin(); it != ProductStock.end(); it++)
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

map<string, vector<Product*>*>* Store::GetProductStock()
{
    return &ProductStock;
}

bool Store::RemoveProductFromStore(Product* product)
{
    map<string, vector<Product*>*>::iterator it;

    for (it = ProductStock.begin(); it != ProductStock.end(); it++)
    {
        for (int i = 0; i < it->second->size(); i++)
        {
            Product* productToCheck = it->second->at(i);

            if ( (product != nullptr) and (product == productToCheck) )
            {
                vector<Product*>* v = it->second;

                vector<Product*>::iterator iit = find(v->begin(), v->end(), product);

                if (iit != v->end())
                {
                    v->erase(iit);

                    if (v->empty())
                    {
                        ProductStock.erase(it);
                    }

                    return true;
                }
            }
        }
    }

    return false;
}
