#include "stdafx.h"
using namespace std;

void print_initializer_list(std::initializer_list<int> vals)
{
	for (auto p = vals.begin(); p != vals.end(); ++p)
	{
		cout << *p << endl;
	}
}

class P
{
public:
	P(int a, int b)
	{
		cout << "P(int, int), a=" << a << ", b=" << b << endl;
	}

	P(initializer_list<int> initlist)
	{
		cout << "P(initializer_list<int>), values= ";
		for (auto i : initlist) {
			cout << i << ' ';
		}
		cout << endl;
	}
};

void test_init_vector()
{
	vector<int> v1{ 1,2,3,4 };
	vector<int> v2({ 11,22,33,44 });
	vector<int> v3;
	v3 = { 5,6,7,8,9 };
	v3.insert(v3.begin() + 2, { 111,222,333 });	//v3 = 5 6 111 222 333 7 8 9
	cout << "v3 = ";
	for (auto i : v3) {
		cout << i << ' ';
	}
	cout << endl;

	cout << std::max({ string("abc"), string("efg"), string("adc") }) << endl;
	cout << std::min({ string("abc"), string("efg"), string("adc") }) << endl;
	cout << std::max({ 54,16,48,5 }) << endl;
	cout << std::min({ 54,16,48,5 }) << endl;
}

void InitializerListTest() {
	print_initializer_list({ 1, 2, 3, 4 });
	P p(1, 2);
	P q{ 3, 4 };
	P r{ 4, 5, 6 };
	P s = { 7,8 };
	test_init_vector();
	cout << endl;
}