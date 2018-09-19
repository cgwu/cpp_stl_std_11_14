#include "stdafx.h"
using namespace std;

void TestTuple()
{
	cout << "sizeof(void*):" << sizeof(void*) << endl;
	cout << "sizeof(string):" << sizeof(string) << endl;
	cout << "sizeof(int):" << sizeof(int) << endl;
	cout << "sizeof(double):" << sizeof(double) << endl;
	cout << "sizeof(complex<double>):" << sizeof(complex<double>) << endl;

	tuple<string, int, int, complex<double>> t;
	cout << "sizeof(tuple):" << sizeof(t) << endl;
	tuple< complex<double>, string, int, int> t2;
	cout << "sizeof(tuple 2):" << sizeof(t2) << endl;
	tuple< string, complex<double>, int, int> t3;
	cout << "sizeof(tuple 3):" << sizeof(t3) << endl;

	get<1>(t) = 123;
	cout << "get<1>(t)=" << get<1>(t) << endl;

	tuple<int, float, string> t4(41, 6.3f, "nice");
	cout << "t4 #1:" << get<0>(t4) << ",t4 #2:" << get<1>(t4) << ",t4 #3:" << get<2>(t4) << endl;

	auto t5 = make_tuple(51, 7.3f, "great");
	cout << "t5 #1:" << get<0>(t5) << ",t5 #2:" << get<1>(t5) << ",t5 #3:" << get<2>(t5) << endl;
	//cout << t5 << endl;

	int i;
	float f;
	string str;
	tie(i, f, str) = t5; //assign values of t5 to i,f,str.
	cout << i << "," << f << "," << str << endl;

	typedef tuple<int, float, string> TupleType;
	cout << tuple_size<TupleType>::value << endl;	//tuple elements size

}

