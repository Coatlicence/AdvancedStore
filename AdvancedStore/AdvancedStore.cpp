#include <iostream>
#include "Store.h"
#include "Product.h"
#include "Player.h"

using namespace std;

ProductManufacturer oco = ProductManufacturer("oco");
ProductManufacturer fff = ProductManufacturer("fff");
ProductManufacturer rrr = ProductManufacturer("rrr");
ProductManufacturer aaa = ProductManufacturer("aaa");

int main()
{
	Player player;
	
	oco.MakeProduct("oco", 100.f);
	oco.MakeProduct("oco_1", 1100.f);

	fff.MakeProduct("fff", 120.f);
	fff.MakeProduct("fff", 1200.f);

	rrr.MakeProduct("rrr", 130.f);
	rrr.MakeProduct("rrr1", 1220.f);

	aaa.MakeProduct("aaa", 140.f);
	aaa.MakeProduct("aaa1", 1320.f);


	while (player.Play)
	{
		player.InterfaceMenuOpen();

		player.Input();
	}
}
