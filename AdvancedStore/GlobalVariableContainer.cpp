
#include "GlobalVariableContainer.h"
#include "UserRegisterInterface.h"
#include "InterfaceChoose.h"

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
    new UserRegisterInterface()
};

GlobalVariableContainer GlobalContainer = GlobalVariableContainer(i);
