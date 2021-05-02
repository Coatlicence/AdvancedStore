#include "GlobalVariableContainer.h"
#include "MenuChooseInterface.h"
#include "OnStoreInterface.h"

GlobalVariableContainer::GlobalVariableContainer(vector<ProgrammInterface*> Interfaces)
{
    this->Interfaces = Interfaces;

    Licensors.push_back(new ProductManufacturer("Lipton"));
    Licensors.push_back(new ProductManufacturer("Fagqu"));

}

vector<ProgrammInterface*> GlobalVariableContainer::GetInterfaces()
{
    return Interfaces;
}

// add your interface here
vector<ProgrammInterface*> i =
{
    new MenuChooseInterface(),
    new OnStoreInterface(),
};

GlobalVariableContainer* GlobalContainer = new GlobalVariableContainer(i);
