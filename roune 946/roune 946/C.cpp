//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//const int N = 1e5 + 10 , M = 1e6 + 1;
//typedef long long ll;
//typedef pair<int, int> PII;
//int n;
//int q[N];
//unordered_map<ll, vector<int>> m1 , m2 , m3;
//int m1a[N] , m2a[N] ,m3[N];
//void solve()
//{
//	ll ans = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)scanf("%d", &q[i]);
//	for (int i = 0; i + 2 < n; i++)
//	{
//		int j = q[i], k = q[i + 1], p = q[i + 2];
//		ll r = i * M + k;
//		ll o = k * M + p;
//		ll v = p * M + j;
//		m1[r].push_back(p);
//		m1a[p]++;
//		m2[o].push_back(j);
//		m3[v].push_back(j);
//	}
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
//}