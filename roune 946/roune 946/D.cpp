//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//using namespace std;
//const int N = 2e5 + 10;
//
//void solve()
//{
//	char a[N];
//	int len;
//	scanf("%d%s",&len , a);
//	int up = 0, r = 0 , l = 0 , dowm = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (a[i] == 'N') up++;
//		else if (a[i] == 'S') dowm ++;
//		else if (a[i] == 'W') l ++;
//		else r++;
//	}
//	if ((up - dowm) % 2 || (r - l) % 2 || (len == 2 && a[0] != a[1]))
//	{
//		printf("NO\n"); return;
//	}
//	bool f1 = 0, f2 = 0;
//	for (int i = 0; i < len; i++)
//	{
//
//		if (a[i] == 'N')
//		{
//			if (f1)
//				a[i] = 'R';
//			else a[i] = 'H';
//			f1 ^= 1;
//		}
//		else if (a[i] == 'S')
//		{
//			if (f1)
//				a[i] = 'R';
//			else a[i] = 'H';
//			f1 ^= 1;
//		}
//		else if (a[i] == 'W')
//		{
//			if (f2)
//				a[i] = 'R';
//			else a[i] = 'H';
//			f2 ^= 1;
//		}
//		else
//		{
//			if (f2)
//				a[i] = 'R';
//			else a[i] = 'H';
//			f2 ^= 1;
//		}
//	}
//	//if (len == 4)
//	//{
//	//	bool f = true;
//	//	char x = a[0];
//
//	//	for (int i = 0; i < len; i++)
//	//	{
//	//		if (a[i] != x) f = false;
//	//	}
//	//	if (f)
//	//	{
//	//		if (a[0] == 'R')
//	//		{
//	//			a[0] = a[1] = 'H';
//	//		}
//	//		else a[0] = a[1] = 'R';
//	//	}
//	//}
//	printf("%s\n", a);
//}
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		solve();
//	}
//
//	return 0;
//}