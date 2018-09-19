
#include "stdafx.h"
using namespace std;

/*********  Variadic Templates(数量不定的模板参数)  **********/
void print() {}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
	cout << "sizeof args =(" << sizeof...(args) << "): " << firstArg << endl;
	print(args...);
}

template <typename T, typename... Types>
void print(const Types&... args)
{
	cout << "#sizeof args =(" << sizeof...(args) << "): " << firstArg << endl;
	print(args...);
}

template<typename T>
using Vec = vector<T, allocator<T>>;

template<typename T>
using Lst = list<T, allocator<T>>;

void VariadicTemplates() {
	//1. Variadic Templates
	print(7.5, "hello中国", bitset<16>(377), 42);
	cout << endl;
}