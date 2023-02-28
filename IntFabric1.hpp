#pragma once
#include "IntFabric.h"
class IntFabric1 : public IntFabric
{
public:
	CIntN* Create(string name, int size, bool sign, int* data) override
	{
		return new CIntN1(name, size, sign, data);
	}
};