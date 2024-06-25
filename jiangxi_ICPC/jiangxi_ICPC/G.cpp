//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//using namespace std;
//const int N = 1e5 + 10;
//typedef long long ll;
//typedef pair<long long, long long> PII;
//
//ll quick_pow(int a, int b, int c)
//{
//	int t = 1;
//	while (b)
//	{
//		if (b & 1)t = t * a % c;
//		a = (ll)a * a % c;
//		b >>= 1;
//	}
//	return t;
//}
//void solve()
//{
//	ll n, x, g = 0;
//	char y;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> x >> y;
//		if (y == 'A') y = 10;
//		else y -= '0';
//		g += x * y;
//	}
//	if (g % 5) cout << "No" << "\n";
//	else cout << "Yes" << "\n";
//}
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}