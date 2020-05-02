#include <iostream>

#include "LuaPlus/LuaPlus.h"

using namespace LuaPlus;

LuaState* pLuaState = LuaState::Create();

int main()
{
	pLuaState->DoString("x = 5");
	pLuaState->DoFile("test.lua");

	{
		LuaObject globals = pLuaState->GetGlobals();
		LuaObject y = globals.GetByName("y");

		if (y.IsNumber())
		{
			std::cout << y.GetInteger() << std::endl;
		}
	}

	LuaState::Destroy(pLuaState);

	return 0;
}