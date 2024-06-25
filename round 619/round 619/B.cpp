//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//
//using namespace std;
//const int N = 1010;
//int t, n;
//
//void solve()
//{
//	cin >> n;
//	long long ans = 0 , now  = n;
//	while (now >= 10)
//	{
//		ans += now - now % 10;
//		now = now / 10 + now % 10;
//	}
//	if (now) ans += now;
//	cout << ans << "\n";
//}
//int main()
//{
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//}