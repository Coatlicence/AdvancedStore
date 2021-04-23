#include <iostream>
#include "Store.h"

using namespace std;

int main()
{
	cout << gStore << endl;

	Store* store = Store::GetStore();

	cout << store << endl;
}