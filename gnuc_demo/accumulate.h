#ifndef ACCUMULATE_H_INCLUDED
#define ACCUMULATE_H_INCLUDED

#include <iostream>
#include <functional>   // std::minus
#include <numeric>      // std:: accumulate

namespace jj34
{

int myfunc(int x, int y)
{
    return x + 2 * y;
}

struct myclass
{
    int operator()(int x, int y)
    {
        return x + 3 * y;
    }
} myobj;

using namespace std;


void test_accumulate()
{
    int init = 100;
    int nums[] = {10,20,30};

    cout << "using default accumulate:";
    cout << accumulate(nums, nums+3, init);
    cout << endl;

    cout << "using functional's minus:";
    cout << accumulate(nums, nums+3, init, minus<int>());
    cout <<endl;

    cout << "using custom function:";
    cout << accumulate(nums, nums+3, init, myfunc);
    cout <<endl;

    cout << "using custom object:";
    cout << accumulate(nums, nums+3, init, myobj);
    cout <<endl;
}

}
#endif // ACCUMULATE_H_INCLUDED
