#include "stdafx.h"
using namespace std;

/*
Template Template Parameterģ��ģ�����:
https://blog.csdn.net/SUSU0203/article/details/80619865
C++ģ��Ԫ��̣�C++ template metaprogramming��:
https://www.cnblogs.com/liangliangh/p/4219879.html
*/

//template<typename /* xyz �˴����ƿ�ʡ�� */> typename Conainer
//template<class T> class Conainer


#define CONTAINER_SIZE 10

template
<
	typename T,
	template<typename> class Conainer
>
class TTPCls {
private:
	Conainer<T> c;
	
public:
	TTPCls() {
		srand((unsigned)time(NULL));
		for (int i = 0; i < CONTAINER_SIZE; ++i) {
			c.insert(c.end(), T(rand() / double(RAND_MAX) * 100));
			//c.insert(c.end(), i);
		}
	}

	void PrintContainer() {
		cout << "Container elements: ";
		for (auto e : c) {
			cout << e << ", ";
		}
		cout << endl;
	}
};


template<typename T>
using Vec = vector<T, allocator<T>>;

template<typename T>
using Lst = list<T, allocator<T>>;

void TemplateTemplateParameter() {

	TTPCls<int, Vec> vec1;
	vec1.PrintContainer();
	TTPCls<double, Lst> lst1;
	lst1.PrintContainer();
	std::cout << std::endl;
}
