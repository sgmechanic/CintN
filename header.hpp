#pragma once
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <map>
#include <string.h>
#include <sstream>
using namespace std;

class CIntN {
protected:
    //char* name;
    string name;
    int N_;
    int* arr_;
    bool znak_;
public:
    CIntN();
    CIntN(const CIntN& data)
    {
        N_ = data.N_;
        znak_ = data.znak_;
        arr_ = new int[N_];
        for (int i = 0; i < N_; i++)
        {
            arr_[i] = data.arr_[i];
        }
        name = data.name;
    }
    CIntN(int N, bool znak);
    CIntN(string str, int N, bool znak, int* b);
    CIntN(int N, bool znak, int* b);
    CIntN(string str, int N, bool znak, vector<int> b);
    virtual ~CIntN();
    virtual int output() = 0;

   /* CIntN(const CIntN& b) {
        N_ = b.N_;
        arr_ = new int[N_];
        znak_ = b.znak_;
        for (int i = 0; i < N_; i++) {
            arr_[i] = b.arr_[i];
        }
        name = b.name;
    }*/

    int getsize() //возвращение размера массива
    {
        return N_;
    }
    bool getznak() {
        return znak_;
    }
    int getarrelem(int i)
    {
        return arr_[i];
    }
    char getnamelem(int i)
    {
        return name[i];
    }
    string getname()
    {
        return name;
    }
    void print() //показать массив
    {
        for (int i = 0; i < N_; i++)
            cout << arr_[i] << "  ";
        cout << endl;
    }
    friend ostream& operator<<(ostream& cout, const CIntN& b);
    friend istream& operator>>(istream& cin, CIntN& b);
    CIntN& operator=(const CIntN& b);
    friend CIntN&& operator+(CIntN&& first, const CIntN& second);
    friend bool operator!=(const CIntN& first, const CIntN& second);
    friend void ReadAndPrint(vector<CIntN*> v, string filename);
};