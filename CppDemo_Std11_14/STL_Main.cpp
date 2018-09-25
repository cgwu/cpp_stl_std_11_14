#include "stdafx.h"
using namespace std;

int main_STL_Main() {
	int ia[6] = { 27,210,12,47,109,83 };
	vector<int, allocator<int>> vi(ia, ia + 6);

	//cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));	//VC²»Ö§³Öbind2nd
	cout << count_if(vi.begin(), vi.end(), [](int n) /* ->bool */ { return n >= 40; });
	cout << endl;
	return 0;
}