//#include<iostream>
//#include<map>
//#include<vector>
//#include<set>
//#define int long long
//using namespace std;
//int dx[] = { 0 , 1 , -1 , 0 }, dy[] = { 1 , 0 , 0 , -1 };
//const int MOD = 1e9 + 7, N = 2e5 + 5;
//typedef pair<int, int> PII;
//int ksm(int a, int b)
//{
//	int res = 1;
//	while (b)
//	{
//		if (b & 1) res = res * a % MOD;
//		a = a * a % MOD;
//		b >>= 1;
//	}
//	return res;
//}
//int mp[26];
//void solve()
//{
//	int n;
//	for (int i = 0; i < 26; i++) mp[i] = 0;
//	map<int, set<string>> mp2;
//	cin >> n;
//	string t, q, s;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> t >> q >> s;
//		if (s[0] == 'a' && mp2[q[0] - 'A'].find(t) == mp2[q[0] - 'A'].end())
//		{
//			mp[q[0] - 'A']++;
//			mp2[q[0] - 'A'].insert(t);
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i < 26; i++)
//		if (mp[i] > mp[ans]) ans = i;
//	cout << (char)(ans + 'A');
//}
//
//signed main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t = 1;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//		if (t) cout << "\n";
//	}
//	return 0;
//}