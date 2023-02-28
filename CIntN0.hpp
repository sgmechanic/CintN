#pragma once
#include "header.h"
class CIntN0 : public CIntN
{
public:
	int output() override;
	friend CIntN0 operator+(const CIntN0& first, const CIntN0& second);
	friend CIntN0 operator-(const CIntN0& first, const CIntN0& second);
	CIntN0() : CIntN() {};
	CIntN0(CIntN& data) {
		N_ = data.getsize();
		znak_ = data.getznak();
		arr_ = new int[N_];
		for (int i = 0; i < N_; i++)
		{
			arr_[i] = data.getarrelem(i);
		}
		name = data.getname();
	}
	CIntN0(int N, bool znak) : CIntN(N, znak) { };
	CIntN0(int N, bool znak, int* b) : CIntN(N, znak, b) { };
	CIntN0(string str, int N, bool znak, int* b) : CIntN(str, N, znak, b) {};
	CIntN0(string str, int N, bool znak, vector<int>b) : CIntN(str, N, znak, b) {};
};
