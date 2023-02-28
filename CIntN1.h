#pragma once
#include "header.h"
class CIntN1 : public CIntN
{
public:
	int output() override;
	friend CIntN1 operator+(const CIntN1& first, const CIntN1& second);
	friend CIntN1 operator-(const CIntN1& first, const CIntN1& second);
	CIntN1() : CIntN() {};
	CIntN1(CIntN& data) {
		N_ = data.getsize();
		znak_ = data.getznak();
		arr_ = new int[N_];
		for (int i = 0; i < N_; i++)
		{
			arr_[i] = data.getarrelem(i);
		}
		name = data.getname();
	}
	CIntN1(int N, bool znak) : CIntN(N, znak) {};
	CIntN1(int N, bool znak, int* b) : CIntN(N, znak, b) {};
	CIntN1(string str, int N, bool znak, int* b) : CIntN(str, N, znak, b) {};
	CIntN1(string str, int N, bool znak, vector<int>b) : CIntN(str, N, znak, b) {};
};