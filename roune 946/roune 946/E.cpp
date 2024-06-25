//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int N = 1e5 + 10;
//int v[60], w[60];
//int t, n , m ,x;
//typedef long long ll;
//void solve()
//{
//	scanf("%d%d", &m, &x);
//	int  s = 0;
//	for (int i = 1; i <= m; i++)
//	{
//		scanf("%d%d", &v[i], &w[i]);
//		s += w[i];
//	}
//	vector<ll>f(s + 1, -(ll)1e15);
//	f[0] = 0;
//	//printf("%d\n", sum[m]);
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = s; j >= 0; j--)
//		{
//			if (j >= w[i] && f[j - w[i] >= v[i]])
//				f[j] = max(f[j], f[j - w[i]] - v[i]);
//			if(i != m)
//			f[j] += x;
//		}
//	}
//	int ans;
//	for (int i = 0; i <= s; i++)
//	{
//		if (f[i] >= 0)
//		{
//			ans = i;
//		}
//	}
//	printf("%d\n", ans);
//}
//int main()
//{
//	scanf("%d", &t);
//	while (t--)
//	{
//		solve();
//	}
//
//}