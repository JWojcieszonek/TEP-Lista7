#include "CMySmartPointer.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string* test = new string("test");
	CMySmartPointer<string> c_pointer = CMySmartPointer<string>(test);
	CMySmartPointer<double> c_pointer_double(new double(2.575));
	CMySmartPointer<string> c_pointer_2 = c_pointer;
	CMySmartPointer<string> c_pointer_3 = CMySmartPointer<string>(c_pointer);
	//c_pointer_2.~CMySmartPointer();
	//c_pointer_3.~CMySmartPointer();
	//c_pointer.~CMySmartPointer();
	cout << *c_pointer << endl;
	cout << *c_pointer_2 << endl;
	cout << *c_pointer_double << endl;
	return 0;
}