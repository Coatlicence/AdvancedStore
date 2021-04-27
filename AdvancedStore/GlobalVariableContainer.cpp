#include "GlobalVariableContainer.h"
#include "MenuChooseInterface.h"

GlobalVariableContainer::GlobalVariableContainer(vector<ProgrammInterface*> Interfaces)
{
    this->Interfaces = Interfaces;
}

vector<ProgrammInterface*> GlobalVariableContainer::GetInterfaces()
{
    return Interfaces;
}

// add your interface here
vector<ProgrammInterface*> i =
{
    new MenuChooseInterface(),

};

GlobalVariableContainer GlobalContainer = GlobalVariableContainer(i);
