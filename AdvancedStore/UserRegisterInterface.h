#pragma once
#include "ProgrammInterface.h"
class UserRegisterInterface: public ProgrammInterface
{
public:
	UserRegisterInterface();

private:
	void PrintInfo() override;

	void InputProcess(Player* player, string& Command) override;

};

