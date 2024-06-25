//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<map>
//using namespace std;
//const int N = 2e5 + 10;
//
//void solve()
//{
//	int n, m , x;
//	cin >> n >> m;
//	int a[N], b[N];
//	for(int i = 0  ; i < n ; i ++)
//	{
//		cin >> a[i];
//	}
//	map<int, int> mp , mp2;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> b[i];
//		if (b[i] != a[i]) mp[b[i]]++;
//	}
//	for (int i = 0; i < m; i++)
//	{
//		cin >> x;
//		mp2[x]++;
//	}
//	for (auto [t, v] : mp)
//	{
//		if (mp2[t] < v) { cout << "NO" << "\n"; }
//	}
//	cout << "YES" << "\n";
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//}