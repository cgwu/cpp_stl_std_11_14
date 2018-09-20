#include "stdafx.h"
using namespace std;

template<typename T1, typename T2>
auto fn_operate(T1 x, T2 y) -> decltype(x + y)	// 1.
{
	return x - y;
}

/*
// 2.
map<string,float> col;
decltype(col)::value_type element;

// 3.
auto cmp = [](const Person& p1, const Person& p2){ ... }
std::set<Person, decltype(cmp)> col(cmp);
*/

void DecltypeTest()
{
	cout << "int,int: " << fn_operate<int, int>(10, 5) << endl;
	cout << "float,float: " << fn_operate<float, float>(8.8f, 4.4f) << endl;
}

