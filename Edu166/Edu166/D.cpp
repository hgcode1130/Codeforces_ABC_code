#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;
const int N = 2e5 + 10;
//思路分析
//正则表达式的条件
//1.di >= 0
//2. dn = 0；
//如果要反转一段子序列[l , r]
//要满足以下两个条件
//1.对于所有的在子序列中的i有2 * dl-1 > di
//2.dr - dl-1 = 0否则反转后会出现dn != 0 的情况
