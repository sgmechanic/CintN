#pragma once
#include "IntFabric.h"
class IntFabric0 : public IntFabric
{
public:
	CIntN* Create(string name, int size, bool sign, int* data) override
	{
		return new CIntN0(name,size,sign,data);
	}
};