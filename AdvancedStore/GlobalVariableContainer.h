#pragma once
#include <vector>
#include "ProgrammInterface.h"
using namespace std;

class ProgrammInterface;


struct GlobalVariableContainer final
{
private:
	vector<ProgrammInterface*> Interfaces;

public:
	// fills Interfaces
	GlobalVariableContainer(vector<ProgrammInterface*> Interfaces);

	vector<ProgrammInterface*> GetInterfaces();
};

/// Stores main variables
extern GlobalVariableContainer GlobalContainer;

