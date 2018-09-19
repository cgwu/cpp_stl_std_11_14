// CppDemo_Std11_14.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "VariadicTemplates.hpp"
#include "InitializerListTest.hpp"
#include "TemplateTemplateParameter.hpp"
#include "TypeAlias.hpp"

using namespace std;


int main()
{
	//cout << __cplusplus << endl << endl;

	VariadicTemplates();
	
	InitializerListTest();

	TypeAlias();
	
	TemplateTemplateParameter();



	//getchar();
    return 0;
}
