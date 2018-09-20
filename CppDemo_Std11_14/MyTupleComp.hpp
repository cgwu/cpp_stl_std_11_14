#include "stdafx.h"
using namespace std;
/*
Ä£°åµÝ¹é×éºÏ
*/
template<typename... Values> class MyTupleComp;
template<> class MyTupleComp<> {};

template<typename Head, typename... Tail>
class MyTupleComp<Head, Tail...>
{
	typedef MyTupleComp<Tail...> Composited;
protected:
	Head m_head;
	Composited m_tail;
	
public:
	MyTupleComp() {}
	MyTupleComp(const Head& v, const Tail&... vtail)	// #!
		:m_head(v), m_tail(vtail...) {}

	Head head() { return m_head; }
	Composited& tail() { return m_tail; }
};

void MyTupleCompTest() {
	MyTupleComp<int, float, string> t(3241, 26.3f, "Composited Nice!");
	cout << "sizeof MyTupleComp:"<< sizeof(t) << endl;
	cout << t.head() << endl;
	cout << t.tail().head() << endl;
	cout << t.tail().tail().head() << endl;
}