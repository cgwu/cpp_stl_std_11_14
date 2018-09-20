
#include "stdafx.h"
using namespace std;

/*********  Variadic Templates(����������ģ�����)  **********/
// һ�����ò����ֽ�ݹ�ķ�ʽ
//1.
void print() {}

//2. ��3��ȣ��Ƚ��ػ���
template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
	cout << "sizeof args =(" << sizeof...(args) << "): " << firstArg << endl;
	print(args...);
}

//3. ��ģ�庯��δ���õ���
template <typename T, typename... Types>
void print(const Types&... args)
{
	cout << "#sizeof args =(" << sizeof...(args) << "): " << firstArg << endl;
	print(args...);
}

/**********************/
// ��������ģ�峣���ݹ�ķ�ʽ
// boost: util/printtuple.hpp
template<int IDX, int MAX, typename... Args>
struct PRINT_TUPLE
{
	static void print(ostream& os, const tuple<Args...>& t)
	{
		os << get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
		PRINT_TUPLE<IDX + 1, MAX, Args...>::print(os, t);
	}
};
// �ս�����: partial specialization to end the recursion
template<int MAX, typename... Args>
struct PRINT_TUPLE<MAX,MAX,Args...>
{
	static void print(ostream& os, const tuple<Args...>& t) { }
};

// output perator for tuples
template<typename... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t)
{
	os << "[";
	PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t);
	return os << "]";
}

void VariadicTemplates() {
	//1. Variadic Templates
	print(7.5, "hello�й�", bitset<16>(377), 42);

	auto t1 = make_tuple(17.5, "1hello�й�", bitset<16>(377), 142);
	cout << t1 << endl;

	cout << endl;
}