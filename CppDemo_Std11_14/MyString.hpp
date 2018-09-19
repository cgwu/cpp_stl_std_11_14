#include "stdafx.h"
using namespace std;

class MyString {
public:
	static size_t DCtor;	// �ۼ�default-ctor���д���
	static size_t Ctor;		// �ۼ�ctor���д���
	static size_t CCtor;	// �ۼ�copy-ctor���д���
	static size_t CAsgn;	// �ۼ�copy-asgn���д���
	static size_t MCtor;	// �ۼ�move-ctor���д���
	static size_t MAsgn;	// �ۼ�move-asgn���д���
	static size_t Dtor;		// �ۼ�dtor���д���

private:
	char* _data;
	size_t _len;

	void _init_data(const char* s) {
		_data = new char[_len + 1];
		memcpy(_data, s, _len);
		_data[_len] = '\0';
	}

public:
	//default constructor
	MyString() :_data(nullptr), _len(0) {
		++DCtor;
	}
	//constructor
	MyString(const char* p) : _len(strlen(p)) {
		++Ctor;
		_init_data(p);
	}
	//copy constructor
	MyString(const MyString& str) : _len(str._len) {
		++CCtor;
		_init_data(str._data);
	}
	//move constructor, with "noexcept"
	MyString(MyString&& str) noexcept 
		:_data(str._data),_len(str._len)
	{
		++MCtor;
		str._len = 0;
		str._data = nullptr;
	}
	//copy assignment
	MyString& operator=(const MyString& str) {
		++CAsgn;
		if (this != &str) {
			if (_data) delete _data;
			_len = str._len;
			_init_data(str._data);	//COPY!
		}
		return *this;
	}
	//move assignment
	MyString& operator=(MyString&& str) noexcept {
		++MAsgn;
		if (this != &str) {
			if (_data) delete _data;
			_len = str._len;
			_data = str._data;	//MOVE!
			str._len = 0;
			str._data = nullptr;
		}
		return *this;
	}
	//dtor : destructor is "noexcept" by default.
	virtual ~MyString() {
		++Dtor;
		if (_data) {
			delete _data;
		}
	}

	//Ϊ��set
	bool operator<(const MyString& rhs) {
		return string(this->_data) < string(rhs._data);		//�����ֳ���ʵstd::string�Ƚϴ�С
	}
	bool operator==(const MyString& rhs) {
		return string(this->_data) == string(rhs._data);	//�����ֳ���ʵstd::string�Ƚ����
	}

	char* get() const { return _data; }
};

size_t MyString::DCtor = 0;	// �ۼ�default-ctor���д���
size_t MyString::Ctor  = 0;	// �ۼ�ctor���д���
size_t MyString::CCtor = 0;	// �ۼ�copy-ctor���д���
size_t MyString::CAsgn = 0;	// �ۼ�copy-asgn���д���
size_t MyString::MCtor = 0;	// �ۼ�move-ctor���д���
size_t MyString::MAsgn = 0;	// �ۼ�move-asgn���д���
size_t MyString::Dtor  = 0;	// �ۼ�dtor���д���

namespace std {	//�������std��
	template<>
	struct hash<MyString> {
		size_t operator()(const MyString& s)const noexcept { //Ϊ��unordered containers
			return hash<string>()(string(s.get()));		//�����ֳɵ�hash<string>
		}
	};
}

template<typename T>
void output_static_data(const T& myStr)
{
	cout << typeid(myStr).name() << "--" << endl;
	cout << "copy-ctor=" << T::CCtor
		<< ", move-ctor=" << T::MCtor
		<< ", copy-asign=" << T::CAsgn
		<< ", move-asign=" << T::MAsgn
		<< ", destructor=" << T::Dtor
		<< ", ctor=" << T::Ctor
		<< ", default-ctor=" << T::DCtor
		<< endl;
}

template<typename M>
void test_moveable(M c1, long value)
{
	typedef typename iterator_traits<typename M::iterator>::value_type V1type;
	char buf[10];
	clock_t timeStart = clock();
	for (long i = 0; i < value; ++i) {
		snprintf(buf, 10, "%d", rand());
		auto ite = c1.end();
		c1.insert(ite, V1type(buf));
	}
	clock_t timeStage1 = clock();
	cout << "construction,milli-seconds:" << (timeStage1 - timeStart) << endl;
	cout << "size()=" << c1.size() << endl;
	output_static_data(*(c1.begin()));
	cout << endl;

	{
		M c11(c1);
		M c12(std::move(c11));
		c12.swap(c1);
	}
	cout << "after block,milli-seconds:" << (clock() - timeStage1) << endl;
	output_static_data(*(c1.begin()));
	cout << endl;
}

void TestSuiteMoveable() {
	//test_moveable(vector<MyString>(), 3000000);
	/*
	Use vector:
	construction,milli-seconds:13413
	size()=3000000
	class MyString--
	copy-ctor=0, move-ctor=10086629, copy-asign=0, move-asign=0, destructor=10086629
	, ctor=3000000, default-ctor=0

	after block,milli-seconds:1943
	class MyString--
	copy-ctor=3000000, move-ctor=10086629, copy-asign=0, move-asign=0, destructor=13
	086629, ctor=3000000, default-ctor=0
	*/
	
	//test_moveable(list<MyString>(), 3000000);
	/*
	Use list:
	construction,milli-seconds:13124
	size()=3000000
	class MyString--
	copy-ctor=0, move-ctor=3000000, copy-asign=0, move-asign=0, destructor=3000000,
	ctor=3000000, default-ctor=0

	after block,milli-seconds:6861
	class MyString--
	copy-ctor=3000000, move-ctor=3000000, copy-asign=0, move-asign=0, destructor=600
	0000, ctor=3000000, default-ctor=0
	*/

	test_moveable(deque<MyString>(), 3000000);
	/*
	Use deque:
	construction,milli-seconds:37616
	size()=3000000
	class MyString--
	copy-ctor=0, move-ctor=3000000, copy-asign=0, move-asign=0, destructor=3000000,
	ctor=3000000, default-ctor=0

	after block,milli-seconds:12012
	class MyString--
	copy-ctor=3000000, move-ctor=3000000, copy-asign=0, move-asign=0, destructor=600
	0000, ctor=3000000, default-ctor=0
	*/
}