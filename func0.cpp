#include "CIntN0.h"
int CIntN0::output()
{
    ofstream file(name, ios_base::app);
    for (int i = 0; i < N_; i++)
        file << arr_[i] << "  ";
    file << endl;
    return 0;
}
CIntN0 operator+(const CIntN0& first, const CIntN0& second) {
    CIntN0 res;
    int col_0 = 0;
    int c = 0, it_znak = 0, col_1 = 0, col_2 = 0, col = 0, N = 0, N_new = 0;
    bool n_1 = false, n_2 = false;
    int* bar;
    int* kol;
    int it[1];
    it[0] = 0;
    CIntN0 nol(1, true, it);

    for (int i = 0; i < N; i++) {
        if (first.arr_[i] < 0 && first.arr_[i] > 9) {
            cout << "Error in vvode 0" << endl;
            exit(0);
        }
    }
    for (int i = 0; i < N; i++) {
        if (second.arr_[i] < 0 && second.arr_[i] > 9) {
            cout << "Error in vvode 0" << endl;
            exit(0);
        }
    }

    if (first.N_ != second.N_) {
        if (first.N_ > second.N_) {
            N = first.N_;
            bar = new int[N];
            for (int i = 0; i < N; i++) {
                if (i < N - second.N_) {
                    bar[i] = 0;
                }
                else {
                    bar[i] = second.arr_[i - (N - second.N_)];
                }
            }

            if (first.znak_ && second.znak_) {  //оба положительны
                res = first;
                for (int i = N - 1; i > 0; i--) {
                    res.arr_[i] += bar[i];
                    if (res.arr_[i] > 9)
                    {
                        res.arr_[i] -= 10;
                        res.arr_[i - 1] += 1;
                    }
                    res.arr_[0] += bar[0];
                    if (res.arr_[0] > 9)
                    {
                        cout << "vse ploh" << endl;
                        exit(0);
                    }
                }
            }
            if ((!first.znak_ && second.znak_) || (!second.znak_ && first.znak_)) {
                c = 1;
            }
            if (!first.znak_ && !second.znak_) {    //оба отрицательны
                res = first;
                for (int i = N - 1; i > 0; i--) {
                    res.arr_[i] += bar[i];
                    if (res.arr_[i] > 9)
                    {
                        res.arr_[i] -= 10;
                        res.arr_[i - 1] += 1;
                    }
                    res.arr_[0] += bar[0];
                    if (res.arr_[0] > 9)
                    {
                        cout << "vse ploh" << endl;
                        exit(0);
                    }
                }
                it_znak = 1;
            }
            if (c == 1) {
                for (int i = 0; i < N; i++) {
                    if (first.arr_[i] > bar[i]) {
                        col_1 += 1;
                    }
                    else if (first.arr_[i] < bar[i]) {
                        col_2 += 1;
                    }
                    else {
                        col += 1;
                    }
                    if (col_1 > 0) {
                        n_1 = true;
                        break;
                    }
                    if (col_2 > 0) {
                        n_2 = true;
                        break;
                    }
                }
                if (col == N) {
                    cout << "0" << endl;
                    exit(1);
                }
                if (n_1) {  //first > second
                    res = first;
                    for (int i = N - 1; i > 0; i--) {
                        res.arr_[i] -= bar[i];
                        if (res.arr_[i] < 0) {
                            res.arr_[i] += 10;
                            res.arr_[i - 1] -= 1;
                        }
                        res.arr_[0] -= bar[0];
                    }
                    if (!first.znak_ && second.znak_) {
                        it_znak = 1;
                    }

                }
                else if (n_2) { //second > first
                    res = second;
                    for (int i = 0; i < N; i++) {
                        res.arr_[i] = bar[i];
                    }
                    for (int i = N - 1; i > 0; i--) {
                        res.arr_[i] -= first.arr_[i];
                        if (res.arr_[i] < 0) {
                            res.arr_[i] += 10;
                            res.arr_[i - 1] -= 1;
                        }
                        res.arr_[0] -= first.arr_[0];
                    }
                    if (first.znak_ && !second.znak_) {
                        it_znak = 1;
                    }

                }
            }
            if (c == 2) {
                it_znak = 1;
            }
            if (it_znak == 1) {
                res.znak_ = false;
            }
            else if (it_znak == 0) {
                res.znak_ = true;
            }
        }

        if (first.N_ < second.N_) {
            N = second.N_;
            bar = new int[N];
            for (int i = 0; i < N; i++) {
                if (i < N - first.N_) {
                    bar[i] = 0;
                }
                else {
                    bar[i] = first.arr_[i - (N - first.N_)];
                }
            }

            if (first.znak_ && second.znak_) {  //оба положительны
                res = second;
                for (int i = N - 1; i > 0; i--) {
                    res.arr_[i] += bar[i]/*second.arr_[i]*/;
                    if (res.arr_[i] > 9)
                    {
                        res.arr_[i] -= 10;
                        res.arr_[i - 1] += 1;
                    }
                    res.arr_[0] += bar[0]/*second.arr_[0]*/;
                    if (res.arr_[0] > 9)
                    {
                        cout << "vse ploh" << endl;
                        exit(0);
                    }
                }
            }
            if ((!first.znak_ && second.znak_) || (!second.znak_ && first.znak_)) {
                c = 1;
            }
            if (!first.znak_ && !second.znak_) {    //оба отрицательны
                res = second;
                for (int i = N - 1; i > 0; i--) {
                    res.arr_[i] += bar[i]/*second.arr_[i]*/;
                    if (res.arr_[i] > 9)
                    {
                        res.arr_[i] -= 10;
                        res.arr_[i - 1] += 1;
                    }
                    res.arr_[0] += bar[0]/*second.arr_[0]*/;
                    if (res.arr_[0] > 9)
                    {
                        cout << "vse ploh" << endl;
                        exit(0);
                    }
                }
                it_znak = 1;
            }
            if (c == 1) {
                for (int i = 0; i < N; i++) {
                    if (bar[i] > second.arr_[i]) {
                        col_1 += 1;
                    }
                    else if (bar[i] < second.arr_[i]) {
                        col_2 += 1;
                    }
                    else {
                        col += 1;
                    }
                    if (col_1 > 0) {
                        n_1 = true;
                        break;
                    }
                    if (col_2 > 0) {
                        n_2 = true;
                        break;
                    }
                }
                if (col == N) {
                    cout << "0" << endl;
                    exit(1);
                }
                if (n_1) {  //first > second
                    res = first;
                    for (int i = 0; i < N; i++) {
                        res.arr_[i] = second.arr_[i];
                    }
                    for (int i = N - 1; i > 0; i--) {
                        res.arr_[i] -= second.arr_[i];
                        if (res.arr_[i] < 0) {
                            res.arr_[i] += 10;
                            res.arr_[i - 1] -= 1;
                        }
                        res.arr_[0] -= second.arr_[0];
                    }
                    if (!first.znak_ && second.znak_) {
                        it_znak = 1;
                    }

                }
                else if (n_2) { //second > first
                    res = second;
                    for (int i = 0; i < N; i++) {
                        res.arr_[i] = second.arr_[i];
                    }
                    for (int i = N - 1; i > 0; i--) {
                        res.arr_[i] -= bar[i];
                        if (res.arr_[i] < 0) {
                            res.arr_[i] += 10;
                            res.arr_[i - 1] -= 1;
                        }
                        res.arr_[0] -= bar[0];
                    }
                    if (first.znak_ && !second.znak_) {
                        it_znak = 1;
                    }

                }
            }
            if (c == 2) {
                it_znak = 1;
            }
            if (it_znak == 1) {
                res.znak_ = false;
            }
            else if (it_znak == 0) {
                res.znak_ = true;
            }
        }
    }
    else if (first.N_ == second.N_) {
        N = first.N_;
        if (first.znak_ && second.znak_) {  //оба положительны
            res = first;
            for (int i = N - 1; i > 0; i--) {
                res.arr_[i] += second.arr_[i];
                if (res.arr_[i] > 9)
                {
                    res.arr_[i] -= 10;
                    res.arr_[i - 1] += 1;
                }
            }
            res.arr_[0] += second.arr_[0];
            if (res.arr_[0] > 9)
            {
                cout << "vse ploh" << endl;
                exit(0);
            }
        }
        if ((!first.znak_ && second.znak_) || (!second.znak_ && first.znak_)) {
            c = 1;
        }
        if (!first.znak_ && !second.znak_) {    //оба отрицательны
            res = first;
            for (int i = N - 1; i > 0; i--) {
                res.arr_[i] += second.arr_[i];
                if (res.arr_[i] > 9)
                {
                    res.arr_[i] -= 10;
                    res.arr_[i - 1] += 1;
                }
                res.arr_[0] += second.arr_[0];
                if (res.arr_[0] > 9)
                {
                    cout << "vse ploh" << endl;
                    exit(0);
                }
            }
            it_znak = 1;
        }
        if (c == 1) {
            for (int i = 0; i < N; i++) {
                if (first.arr_[i] > second.arr_[i]) {
                    col_1 += 1;
                }
                else if (first.arr_[i] < second.arr_[i]) {
                    col_2 += 1;
                }
                else {
                    col += 1;
                }
                if (col_1 > 0) {
                    n_1 = true;
                    break;
                }
                if (col_2 > 0) {
                    n_2 = true;
                    break;
                }
            }
            if (col == N) {
                return nol;
            }
            if (n_1) {  //first > second
                res = first;
                for (int i = N - 1; i > 0; i--) {
                    res.arr_[i] -= second.arr_[i];
                    if (res.arr_[i] < 0) {
                        res.arr_[i] += 10;
                        res.arr_[i - 1] -= 1;
                    }
                }
                res.arr_[0] -= second.arr_[0];
                if (!first.znak_ && second.znak_) {
                    it_znak = 1;
                }
            }
            else if (n_2) { //second > first
                res = second;
                for (int i = N - 1; i > 0; i--) {
                    res.arr_[i] -= first.arr_[i];
                    if (res.arr_[i] < 0) {
                        res.arr_[i] += 10;
                        res.arr_[i - 1] -= 1;
                    }
                }
                res.arr_[0] -= first.arr_[0];
                if (first.znak_ && !second.znak_) {
                    it_znak = 1;
                }
            }
        }
        if (c == 2) {
            it_znak = 1;
        }
        if (it_znak == 1) {
            res.znak_ = false;
        }
        else if (it_znak == 0) {
            res.znak_ = true;
        }
    }

    for (int i = 0; i < N; i++) {
        if (res.arr_[i] == 0) {
            col_0 += 1;
        }
        if (res.arr_[i] != 0) {
            break;
        }
    }
    if (col_0 > 0) {
        N_new = N - col_0;
        res.N_ = N_new;
        kol = new int[N_new];
        for (int i = 0; i < N_new; i++) {
            kol[i] = res.arr_[i + col_0];
        }
        delete[] res.arr_;
        res.arr_ = new int[N_new];
        for (int i = 0; i < N_new; i++) {
            res.arr_[i] = kol[i];

        }
    }
    delete[] bar;
    return res;
}

CIntN0 operator-(const CIntN0& first, const CIntN0& second) {
    CIntN0 res;
    int col_0 = 0;
    int c = 0, it_znak = 0, col_1 = 0, col_2 = 0, col = 0, N = 0, N_new = 0;
    //bool znak_1 = false, znak_2 = false,
    bool n_1 = false, n_2 = false;
    int* bar;
    int* kol;
    int it[1];
    it[0] = 0;
    CIntN0 nol(1, true, it);

    for (int i = 0; i < first.N_; i++) {
        if (first.arr_[i] < 0 && first.arr_[i] > 9) {
            cout << "Error in vvode 0" << endl;
            exit(0);
        }
    }
    for (int i = 0; i < second.N_; i++) {
        if (second.arr_[i] < 0 && second.arr_[i] > 9) {
            cout << "Error in vvode 0" << endl;
            exit(0);
        }
    }

    if (first.N_ != second.N_) {
        if (first.N_ > second.N_) {
            N = first.N_;
            bar = new int[N];
            for (int i = 0; i < N; i++) {
                if (i < N - second.N_) {
                    bar[i] = 0;
                }
                else {
                    bar[i] = second.arr_[i - (N - second.N_)];
                }
                //cout << "/ " << bar[i];
            }

            if (!second.znak_ && first.znak_) {
                res = first;
                for (int i = N - 1; i > 0; i--) {
                    res.arr_[i] += bar[i];
                    if (res.arr_[i] > 9)
                    {
                        res.arr_[i] -= 10;
                        res.arr_[i - 1] += 1;
                    }
                    res.arr_[0] += bar[0];
                }
            }
            if (!first.znak_ && second.znak_) {
                res = first;
                for (int i = N - 1; i > 0; i--) {
                    res.arr_[i] += bar[i];
                    if (res.arr_[i] > 9)
                    {
                        res.arr_[i] -= 10;
                        res.arr_[i - 1] += 1;
                    }
                    res.arr_[0] += bar[0];
                }
                it_znak = 1;
            }
            if ((first.znak_ && second.znak_) || (!first.znak_ && !second.znak_)) {
                c = 1;
            }

            if (c == 1) {
                for (int i = 0; i < N; i++) {
                    if (first.arr_[i] > bar[i]) {
                        col_1 += 1;
                    }
                    else if (first.arr_[i] < bar[i]) {
                        col_2 += 1;
                    }
                    else {
                        col += 1;
                    }
                    if (col_1 > 0) {
                        n_1 = true;
                        break;
                    }
                    if (col_2 > 0) {
                        n_2 = true;
                        break;
                    }
                }
                if (col == N) {
                    cout << "0" << endl;
                    exit(1);
                }
                if (n_1) {  //first > second
                    res = first;
                    for (int i = N - 1; i > 0; i--) {
                        res.arr_[i] -= bar[i];
                        if (res.arr_[i] < 0) {
                            res.arr_[i] += 10;
                            res.arr_[i - 1] -= 1;
                        }
                        res.arr_[0] -= bar[0];
                    }
                    if (!first.znak_ && !second.znak_) {
                        it_znak = 1;
                    }

                }
                else if (n_2) { //second > first
                    res = second;
                    for (int i = 0; i < N; i++) {
                        res.arr_[i] = bar[i];
                    }
                    for (int i = N - 1; i > 0; i--) {
                        res.arr_[i] -= first.arr_[i];
                        if (res.arr_[i] < 0) {
                            res.arr_[i] += 10;
                            res.arr_[i - 1] -= 1;
                        }
                        res.arr_[0] -= first.arr_[0];
                    }
                    if (first.znak_ && second.znak_) {
                        it_znak = 1;
                    }

                }
            }
            if (it_znak == 1) {
                res.znak_ = false;
            }
            if (it_znak == 0) {
                res.znak_ = true;
            }
        }

        if (first.N_ < second.N_) {
            N = second.N_;
            bar = new int[N];
            for (int i = 0; i < N; i++) {
                if (i < N - first.N_) {
                    bar[i] = 0;
                }
                else {
                    bar[i] = first.arr_[i - (N - first.N_)];
                }
                //cout << "/ " << bar[i];
            }

            if (!second.znak_ && first.znak_) {
                res = second/*first*/;
                for (int i = N - 1; i > 0; i--) {
                    res.arr_[i] += bar[i]/*second.arr_[i]*/;
                    if (res.arr_[i] > 9)
                    {
                        res.arr_[i] -= 10;
                        res.arr_[i - 1] += 1;
                    }
                    res.arr_[0] += bar[0]/*second.arr_[0]*/;
                }
            }
            if (!first.znak_ && second.znak_) {
                res = second;
                for (int i = N - 1; i > 0; i--) {
                    res.arr_[i] += bar[i]/*second.arr_[i]*/;
                    if (res.arr_[i] > 9)
                    {
                        res.arr_[i] -= 10;
                        res.arr_[i - 1] += 1;
                    }
                    res.arr_[0] += bar[0]/*second.arr_[0]*/;
                }
                it_znak = 1;
            }
            if ((first.znak_ && second.znak_) || (!first.znak_ && !second.znak_)) {
                c = 1;
            }

            if (c == 1) {
                for (int i = 0; i < N; i++) {
                    if (bar[i] > second.arr_[i]) {
                        col_1 += 1;
                    }
                    else if (bar[i] < second.arr_[i]) {
                        col_2 += 1;
                    }
                    else {
                        col += 1;
                    }
                    if (col_1 > 0) {
                        n_1 = true;
                        break;
                    }
                    if (col_2 > 0) {
                        n_2 = true;
                        break;
                    }
                }
                if (col == N) {
                    return nol;
                }
                if (n_1) {  //first > second
                    res = first;
                    for (int i = 0; i < N; i++) {
                        res.arr_[i] = bar[i];
                    }
                    for (int i = N - 1; i > 0; i--) {
                        res.arr_[i] -= second.arr_[i];
                        if (res.arr_[i] < 0) {
                            res.arr_[i] += 10;
                            res.arr_[i - 1] -= 1;
                        }
                        res.arr_[0] -= second.arr_[0];
                    }
                    if (!first.znak_ && !second.znak_) {
                        it_znak = 1;
                    }

                }
                else if (n_2) { //second > first
                    if (first.znak_ && second.znak_) {
                        res = second;
                        for (int i = N - 1; i > 0; i--) {
                            res.arr_[i] -= bar[i];
                            if (res.arr_[i] < 0) {
                                res.arr_[i] += 10;
                                res.arr_[i - 1] -= 1;
                            }
                            res.arr_[0] -= bar[0];
                        }
                        it_znak = 1;
                    }
                    else if (!first.znak_ && !second.znak_) {
                        res = second;
                        for (int i = N - 1; i > 0; i--) {
                            res.arr_[i] -= bar[i];
                            if (res.arr_[i] < 0) {
                                res.arr_[i] += 10;
                                res.arr_[i - 1] -= 1;
                            }
                            res.arr_[0] -= bar[0];
                        }
                    }
                }
            }

            if (it_znak == 1) {
                res.znak_ = false;
            }
            if (it_znak == 0) {
                res.znak_ = true;
            }
        }
    }
    else if (first.N_ == second.N_) {
        N = first.N_;
        if (!second.znak_ && first.znak_) {
            res = first;
            for (int i = N - 1; i > 0; i--) {
                res.arr_[i] += second.arr_[i];
                if (res.arr_[i] > 9)
                {
                    res.arr_[i] -= 10;
                    res.arr_[i - 1] += 1;
                }
                res.arr_[0] += second.arr_[0];
            }
        }
        if (!first.znak_ && second.znak_) {
            res = first;
            for (int i = N - 1; i > 0; i--) {
                res.arr_[i] += second.arr_[i];
                if (res.arr_[i] > 9)
                {
                    res.arr_[i] -= 10;
                    res.arr_[i - 1] += 1;
                }
                res.arr_[0] += second.arr_[0];
            }
            it_znak = 1;
        }
        if ((first.znak_ && second.znak_) || (!first.znak_ && !second.znak_)) {
            c = 1;
        }

        if (c == 1) {
            for (int i = 0; i < N; i++) {
                if (first.arr_[i] > second.arr_[i]) {
                    col_1 += 1;
                }
                else if (first.arr_[i] < second.arr_[i]) {
                    col_2 += 1;
                }
                else {
                    col += 1;
                }
                if (col_1 > 0) {
                    n_1 = true;
                    break;
                }
                if (col_2 > 0) {
                    n_2 = true;
                    break;
                }
            }
            if (col == N) {
                return nol;
            }
            if (n_1) {  //first > second
                res = first;
                for (int i = N - 1; i > 0; i--) {
                    res.arr_[i] -= second.arr_[i];
                    if (res.arr_[i] < 0) {
                        res.arr_[i] += 10;
                        res.arr_[i - 1] -= 1;
                    }
                    res.arr_[0] -= second.arr_[0];
                }
                if (!first.znak_ && !second.znak_) {
                    it_znak = 1;
                }

            }
            else if (n_2) { //second > first
                res = second;
                for (int i = N - 1; i > 0; i--) {
                    res.arr_[i] -= first.arr_[i];
                    if (res.arr_[i] < 0) {
                        res.arr_[i] += 10;
                        res.arr_[i - 1] -= 1;
                    }
                    res.arr_[0] -= first.arr_[0];
                }
                if (first.znak_ && second.znak_) {
                    it_znak = 1;
                }

            }
        }

        if (it_znak == 1) {
            res.znak_ = false;
        }
        if (it_znak == 0) {
            res.znak_ = true;
        }
    }

    for (int i = 0; i < N; i++) {
        if (res.arr_[i] == 0) {
            col_0 += 1;
        }
        if (res.arr_[i] != 0) {
            break;
        }
    }
    if (col_0 > 0) {
        N_new = N - col_0;
        res.N_ = N_new;
        kol = new int[N_new];
        for (int i = 0; i < N_new; i++) {
            kol[i] = res.arr_[i + col_0];
        }
        delete[] res.arr_;
        res.arr_ = new int[N_new];
        for (int i = 0; i < N_new; i++) {
            res.arr_[i] = kol[i];

        }
    }
    delete[] bar;
    return res;
}
