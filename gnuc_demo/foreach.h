#ifndef FOREACH_H_INCLUDED
#define FOREACH_H_INCLUDED

#include <iostream>
#include <algorithm>   // std::for_each
#include <vector>

namespace jj35
{
using namespace std;

void myfunc(int x)
{
   cout << ' ' << x;
}

struct myclass
{
    void operator()(int x)
    {
        cout << ' ' << x;
    }
} myobj;

using namespace std;


void test_foreach()
{
    vector<int> vi {10,20,30,20};

    for_each(vi.begin(),vi.end(), myfunc);
    cout << endl;

    for_each(vi.begin(),vi.end(), myobj);
    cout << endl;

    for_each(vi.begin(),vi.end(), [](int x){ cout << ' ' << x;});
    cout << endl;

    for(auto& e: vi)
    {
        e *=3;
    }
    for(auto e: vi)
    {
        cout << ' ' << e;
    }
    cout <<endl;

    auto result =  count(vi.begin(),vi.end(),60);
    cout <<result << endl;

    result =  count_if(vi.begin(),vi.end(),[](int x){ return x == 60;});
    cout <<result << endl;

    auto fresult = find(vi.begin(), vi.end(), 60);
    if(fresult == vi.end()) cout << " Not found" <<endl;
    else cout << *fresult << endl;

    cout << "排序:" <<endl;
    sort(vi.begin(),vi.end());
     for(auto e: vi)
    {
        cout << ' ' << e;
    }
    cout <<endl;
    // 排序: 30 60 60 90
    auto lower = std::lower_bound(vi.begin(),vi.end(),60);
    cout << "lower:" << *--lower <<endl;    //30
    auto upper = std::upper_bound(vi.begin(),vi.end(),60);
    cout << "upper:" << *upper <<endl;      //90

    cout << "反向排序:" <<endl;
    sort(vi.rbegin(),vi.rend());
     for(auto e: vi)
    {
        cout << ' ' << e;
    }
    cout <<endl;

    vi.push_back(999);
    sort(vi.begin(),vi.end(),greater<int>());
    for(auto e: vi)
    {
        cout << ' ' << e;
    }
    cout <<endl;

    using namespace std::placeholders;
    // #! not1, bind2nd, less.
    cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(),60))) <<endl;
    cout << count_if(vi.begin(), vi.end(), bind(less_equal<int>(),_1,60)) <<endl;
}

}
#endif // FOREACH_H_INCLUDED
