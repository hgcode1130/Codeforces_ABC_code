#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include<map>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<Windows.h>

#include<random>
#include<sys/timeb.h>
int main()
{
    struct _timeb T;
    _ftime(&T);
    srand(T.millitm);

    freopen("in.txt", "w", stdout); //���� ʹ���ݻ������� ��Ҫ���������
    int a = rand(), b = rand();
    printf("%d %d\n", a, b);
}
