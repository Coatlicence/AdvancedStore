#pragma once

#include "ProgrammInterface.h"

class MenuChooseInterface : public ProgrammInterface
{
public:

private:

public:
	MenuChooseInterface();

	void PrintInfo() override;

	void InputProcess(Player* player, string& Command) override;
};