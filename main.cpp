#include"header.h"
#include "autotest.h"
#include "CIntN0.h"
#include "CIntN1.h"
int main(void)
{
	autotest();
	string filename;
	cout << "input file name:";
	cin >> filename;
	vector <CIntN*> v_obj;
	ReadAndPrint(v_obj, filename);
	/*if (1 == 1)
	{
		CIntN* ptr = new CIntN1 (1, 1);
		delete ptr;
	}*/

	return 0;
}