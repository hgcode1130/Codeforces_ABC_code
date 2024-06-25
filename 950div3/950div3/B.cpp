//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<map>
//#include<algorithm>
//using namespace std;
//const int N = 110;
//
//void solve()
//{
//	map<int, int> mp;
//	int n, k, f;
//	cin >> n >> f >> k;
//	int a[N];
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//		mp[a[i]]++;
//	}
//	int tar = a[f];
//	sort(a + 1, a + 1 + n , greater<int>());
//	int l = 0, r = k + 1;
//	while (l + 1 != r)
//	{
//		int mid = (l + r) >> 1;
//		if (a[mid] > tar) l = mid;
//		else r = mid;
//	}
//	if (r == k + 1) cout << "NO" << "\n";
//	if (r <= k) 
//	{
//		if (mp[tar] > k - r + 1) cout << "MAYBE" << "\n";
//		else cout << "YES" << "\n";
//	}
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