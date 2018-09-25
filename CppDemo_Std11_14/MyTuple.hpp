#include "stdafx.h"
using namespace std;
/*
Ä£°åµÝ¹é¼Ì³Ð
*/
template<typename... Values> class MyTuple;
template<> class MyTuple<> {};

template<typename Head, typename... Tail>
class MyTuple<Head, Tail...>
	:private MyTuple<Tail...>
{
	typedef MyTuple<Tail...> inherated;
protected:
	Head m_head;
public:
	MyTuple() {}
	MyTuple(const Head& v, const Tail&... vtail)
		:m_head(v), inherated(vtail...) {}

	Head head() { return m_head; }
	//auto head() -> decltype(m_head) { return m_head; }
	inherated& tail() { return *this; }
};

void MyTupleTest() {
	MyTuple<int, float, string> t(41, 6.3f, "const Nice!");
	cout << "sizeof MyTuple:"<< sizeof(t) << endl;
	cout << t.head() << endl;
	cout << t.tail().head() << endl;
	cout << t.tail().tail().head() << endl;
}
