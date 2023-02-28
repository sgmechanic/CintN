#include "autotest.h"

int autotest1() {
	int m1[4]{ 1, 2, 3, 4 };
	int m2[3]{ 1, 2, 1 };
	int otv_1[4]{ 1, 3, 5, 5 };
	CIntN0  mas1(4, true, m1);
	CIntN0  mas2(3, true, m2);
	//CIntN0 res_1;
	CIntN0 otvet_1(4, true, otv_1);
	CIntN0 res_1 = mas1 + mas2;
	if (res_1 != otvet_1) {
		cout << "Autotest 1 Failed..(mas1 + mas2)\n" << endl;
		return 0;
	}
	else {
		cout << "Autotest 1 Passed..(mas1 + mas2)\n" << endl;
		return 1;
	}
}

int autotest2() {
	int m1[4]{ 1, 2, 3, 4 };
	int m2[3]{ 1, 2, 1 };
	int otv_2[4]{ 1, 1, 1, 3 };
	CIntN0  mas1(4, true, m1);
	CIntN0 mas2(3, true, m2);
	CIntN0 res_2;
	CIntN0 otvet_2(4, true, otv_2);
	res_2 = mas1 - mas2;
	if (res_2 != otvet_2) {
		cout << "Autotest 2 Failed..(mas1 - mas2)\n" << endl;
		return 0;
	}
	else {
		cout << "Autotest 2 Passed..(mas1 - mas2)\n" << endl;
		return 1;
	}
}

int autotest3() {
	int m1[4]{ 1, 2, 3, 4 };
	int m2[3]{ 1, 2, 1 };
	int otv_3[4]{ 1, 1, 1, 3 };
	CIntN0  mas1(4, true, m1);
	CIntN0  mas2(3, false, m2);
	CIntN0 res_3;
	CIntN0 otvet_3(4, true, otv_3);
	res_3 = mas1 + mas2;
	if (res_3 != otvet_3) {
		cout << "Autotest 3 Failed..(mas1 + (-mas2))\n" << endl;
		return 0;
	}
	else {
		cout << "Autotest 3 Passed..(mas1 + (-mas2))\n" << endl;
		return 1;
	}
}

int autotest4() {
	int m1[4]{ 1, 2, 3, 4 };
	int m2[3]{ 1, 2, 1 };
	int otv_4[4]{ 1, 3, 5, 5 };
	CIntN0  mas1(4, true, m1);
	CIntN0  mas2(3, false, m2);
	CIntN0 res_4;
	CIntN0 otvet_4(4, true, otv_4);
	res_4 = mas1 - mas2;
	if (res_4 != otvet_4) {
		cout << "Autotest 4 Failed..(mas1 - (-mas2))\n" << endl;
		return 0;
	}
	else {
		cout << "Autotest 4 Passed..(mas1 + (-mas2))\n" << endl;
		return 1;
	}
}

int autotest(void) {
	if (!autotest1() || !autotest2() || !autotest3() || !autotest4()) {
		cout << "some auto Failed\n" << endl;
		return 0;
	}
	return 1;
}