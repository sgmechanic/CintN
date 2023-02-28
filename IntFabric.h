#pragma once
#include "header.h"
#include "CIntN0.h"
#include "CIntN1.h"
class IntFabric {
public:
	virtual CIntN* Create(string name, int size, bool sign, int* data) = 0;
    virtual ~IntFabric(){};
};
