// CppDemo_Std11_14.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "VariadicTemplates.hpp"
#include "InitializerListTest.hpp"
#include "TemplateTemplateParameter.hpp"
#include "TypeAlias.hpp"
#include "MyString.hpp"
#include "TupleTest.hpp"
#include "DecltypeTest.hpp"
#include "LambdaTest.hpp"
#include "MyTuple.hpp"
#include "MyTupleComp.hpp"

using namespace std;

//int main_CppDemo_Std11_14()
int main()
{
	//cout << __cplusplus << endl << endl;

	//VariadicTemplates();
	
	//InitializerListTest();

	//TypeAlias();
	//
	//TemplateTemplateParameter();

	//TestSuiteMoveable();

	//TestTuple();

	//DecltypeTest();

	//LambdaTest();

	MyTupleTest();
	cout << endl << endl;
	MyTupleCompTest();

	//getchar();
    return 0;
}
