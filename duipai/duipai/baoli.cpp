#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include<map>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
int main()
{
    freopen("in.txt", "r", stdin);      //�������������������������
    freopen("baoli.txt", "w", stdout); //�����
    int a, b, ans = 0;
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= a; ++i)
        ans++;
    for (int i = 1; i <= b; ++i)
        ans++;
    printf("%d\n", ans);
}
