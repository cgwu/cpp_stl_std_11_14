#include "stdafx.h"
using namespace std;

// type alias, identical to typedef
//typedef int(*FN_ALIAS)(int, int);
using FN_ALIAS = int(*)(int, int);

int fn_add(int a, int b)
{
	return a + b;
}

int fn_subtract(int a, int b)
{
	return a - b;
}


void TypeAlias() {
	FN_ALIAS fp = fn_add;
	std::cout << fp(10, 20) << std::endl;
	fp = fn_subtract;
	std::cout << fp(10, 20) << std::endl;
}
