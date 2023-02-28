#include "header.h"
#include "CIntN0.h"
#include "CIntN1.h"
#include "IntFabric.h"
#include "IntFabric0.h"
#include "IntFabric1.h"
#
CIntN::CIntN() {
    N_ = 1;
    znak_ = false;
    arr_ = new int[N_];
    name = "";
}

CIntN::CIntN(int N, bool znak) {
    N_ = N;
    znak_ = znak;
    arr_ = new int[N_];
    for (int i = 0; i < N_; i++) {
        arr_[i] = 0;
    }
    name = "";
}

CIntN::CIntN(int N, bool znak, int* b) {
    N_ = N;
    znak_ = znak;
    arr_ = new int[N_];
    for (int i = 0; i < N_; i++) {
        arr_[i] = b[i];
    }
    name = "";
}

CIntN::CIntN(string str, int N, bool znak, int* b){
    name = str;
    N_ = N;
    znak_ = znak;
    arr_ = new int[N_];
    for (int i = 0; i < N_; i++) {
        arr_[i] = b[i];
    }
}

CIntN::CIntN(string str, int N, bool znak, vector<int> b){
    name = str;
    N_ = N;
    znak_ = znak;
    arr_ = new int[N_];
    for (int i = 0; i < N_; i++) {
        arr_[i] = b[i];
    }
}


CIntN::~CIntN() {
    if (arr_ != nullptr)
    {
        delete[] arr_;
        arr_ = nullptr;
    }
}

CIntN& CIntN::operator=(const CIntN& b) {
    if (this == &b)
    {
        return *this;
    }
    delete[] arr_;
    N_ = b.N_;
    znak_ = b.znak_;
    arr_ = new int[N_];
    for (int i = 0; i < N_; i++)
    {
        arr_[i] = b.arr_[i];
    }
    name = b.name;
    return *this;
}


CIntN&& operator+(CIntN&& first, const CIntN& second) {
    int it_znak = 0, N = 0;

    N = second.N_;

    for (int i = N - 1; i > 0; i--) {
        first.arr_[i] += second.arr_[i];
        if (first.arr_[i] > 9)
        {
            first.arr_[i] -= 10;
            first.arr_[i - 1] += 1;
        }
    }
    if (first.arr_[0] > 9)
    {
        cout << "vse ploh" << endl;
        exit(0);
    }
    if (!first.znak_ && !second.znak_) {
        it_znak = 1;
    }
    if (it_znak == 1) {
        first.znak_ = false;
    }
    else if (it_znak == 0) {
        first.znak_ = true;
    }
    return move(first);
}

bool operator!=(const CIntN& first, const CIntN& second) {
    int c = 0, N = 0;
    if (first.N_ > second.N_) {
        N = first.N_;
    }
    else if (first.N_ < second.N_) {
        N = second.N_;
    }
    else {
        N = first.N_;
    }
    for (int i = 0; i < N; i++) {
        if (first.arr_[i] != second.arr_[i]) {
            c = 1;
        }
    }
    return!(c == 0 && first.znak_ == second.znak_ && first.name == second.name);
}

ostream& operator<<(ostream& cout, const CIntN& b)
{
    if (b.znak_ == false) { cout << "-"; }
    for (int i = 0; i < b.N_; i++) {
        cout << b.arr_[i];
    }
    return cout;
}
istream& operator>>(istream& cin, CIntN& b)
{
    for (int i = 0; i < b.N_; i++) {
        cin >> b.arr_[i];
    }
    return cin;
}
//void ReadAndPrint(vector<CIntN*> v_obj, string filename) {
//    string line;
//    fstream file;
//    file.open(filename, ios::in);
//    while (getline(file, line))
//    {
//        char* s = new char[line.size() + 1];
//        strcpy(s, line.c_str());
//        char* p = strtok(s, " ");
//        int type = atoi(p);
//        p = strtok(NULL, " ");
//        char* name = new char[strlen(p) + 1];
//        strcpy(name, p);
//        p = strtok(NULL, " ");
//        bool sign = bool(atoi(p));
//        p = strtok(NULL, " ");
//        int size = atoi(p);
//        p = strtok(NULL, " ");
//        int* data = new int[size];
//        int i = 0;
//        while (p != NULL) {
//            data[i] = atoi(p);
//            p = strtok(NULL, " ");
//            i++;
//        }
//        CIntN* ptr0 = new CIntN0(name, size, sign, data);
//        CIntN* ptr1 = new CIntN1(name, size, sign, data);
//        if (type == 0)
//            v_obj.push_back(ptr0);
//        else if (type == 1)
//            v_obj.push_back(ptr1);
//        delete[] data;
//        data = nullptr;
//        delete[] name;
//        name = nullptr;
//        delete[] s;
//        s = nullptr;
//        //delete ptr0;
//        //delete ptr1;
//    }
//
//    for (auto it : v_obj)
//    {
//        it->output();
//    }
//    for (auto it : v_obj)
//    {
//        delete it;
//    }
//    file.close();
//
//}

void ReadAndPrint(vector<CIntN*> v_obj, string filename)
{
    map <int, IntFabric*> ourMap;
    ourMap[0] = new IntFabric0;
    ourMap[1] = new IntFabric1;
    string tmpString;
    fstream file;
    file.open(filename, ios::in);
    while (getline(file, tmpString)) {
        std::stringstream strStream;
        strStream << tmpString;

        int type;
        strStream >> type;
        //std::cout << vectorType << std::endl;
        string name;
        strStream >> name;
        bool sign;
        strStream >> sign;
        int size;
        strStream >> size;
        int* data = new int[size];
        int el;
        int i = 0;
        while (strStream >> el) {
            data[i] = el;
            i++;
        }

        auto cur = ourMap.find(type);
        if (cur == ourMap.end()) {
            throw std::invalid_argument("Error! Wrong type of vector in file input.txt!\n");
        }
        v_obj.push_back(cur->second->Create(name, size, sign, data));
        //auto curVect = curFactory->second->Create(static_cast<unsigned int>(elementsList.size()), fileName);
        //unsigned int i = 0;
        ///* range-based loop */
        //for (const auto el : elementsList) {
        //    (*curVect)[i] = el;
        //    i++;
        //}

        //vectorVector.push_back(curVect);
          delete[] data;
    }

    for (auto it : v_obj)
    {
        it->output();
    }
    for (auto it : v_obj)
    {
        delete it;
    }
    file.close();
    delete ourMap[0];
    delete ourMap[1];
}
