#include "Product.h"

string Product::GetName()
{
    return Name;
}

ProductManufacturer* Product::GetProductManufacturerName()
{
    return ProductManufacturerName;
}

void Product::SetPrice(float Price)
{
    this->Price = Price;
}
