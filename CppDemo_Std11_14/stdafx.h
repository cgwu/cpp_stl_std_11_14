// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <cstdlib>
#include <ctime>

// TODO: 在此处引用程序需要的其他头文件
#include <iostream>
#include <bitset>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <typeinfo> //typeid()
#include <tuple>
#include <complex>
#include <algorithm>
#include <functional>

template<typename T>
using Vec = std::vector<T, std::allocator<T>>;

template<typename T>
using Lst = std::list<T, std::allocator<T>>;

