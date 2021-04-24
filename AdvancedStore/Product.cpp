#include "Product.h"

Product::Product(string Name, string ManufacturerName, float Price)
{
    this->Name = Name;

    this->ManufacturerName = ManufacturerName;

    this->Price = Price;
}

string Product::GetName()
{
    return Name;
}

string Product::GetManufacturerName()
{
    return ManufacturerName;
}

float Product::GetPrice()
{
    return Price;
}

void Product::SetPrice(float Price)
{
    this->Price = Price;
}
