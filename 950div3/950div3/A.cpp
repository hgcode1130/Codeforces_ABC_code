//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<map>
//using namespace std;
//
//void solve()
//{
//	map<char, int> mp;
//	int n, m;
//	cin >> n >> m;
//	string a;
//	cin >> a;
//	for (int i = 0; i < a.size(); i++)
//	{
//		mp[a[i]]++;
//	}
//	int ans = 0;
//	for (int i = 'A'; i <= 'G'; i++)
//	{
//		if (mp[i] < m)
//		{
//			ans += m - mp[i];
//		}
//	}
//	cout << ans << "\n";
//}
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
//	return 0;
//}