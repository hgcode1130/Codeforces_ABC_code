#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;
const int N = 2e5 + 10;
//˼·����
//������ʽ������
//1.di >= 0
//2. dn = 0��
//���Ҫ��תһ��������[l , r]
//Ҫ����������������
//1.�������е����������е�i��2 * dl-1 > di
//2.dr - dl-1 = 0����ת������dn != 0 �����
