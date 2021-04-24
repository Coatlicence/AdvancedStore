#pragma once
#include "ProductManufacturer.h"
class ChipsFactory final: public ProductFactory
{
	void CreateProduct(ProductManufacturer* Licensor) override;
};

