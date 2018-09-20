#include "stdafx.h"
using namespace std;

void LambdaTest() {
	[] {
		cout << "Hello lambda!" << endl;
	}();

	auto fn = [] {
		cout << "Hello lambda! auto" << endl;
	};
	fn();
	fn();
	
	// ---
	int id = 0;
	auto f = [id] () mutable {
		cout << "id:" << id << endl;
		++id;
	};
	id = 42;
	f();
	f();
	f();
	cout << "end id:" << id << endl;

	// ---
	vector<int> vi{ 5,28,50,83,70,590,245,59,24 };
	int x = 30;
	int y = 100;
	vi.erase(
		remove_if(vi.begin(), vi.end(), [x, y](int n) {return x < n && n < y; })
		,vi.end()
	);
	for (auto i : vi) {
		cout << i << ' ';
	}
	cout << endl;
}
