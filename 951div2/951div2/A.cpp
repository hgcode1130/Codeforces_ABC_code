//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<cmath>
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> PII;
//const int N = 2e5 + 10;
//
//void solve()
//{
//	int n;
//	cin >> n;
//	int a[N];
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	int ans = 0x3f3f3f3f;
//	for (int i = 1; i < n; i++)
//	{
//		ans = min(max(a[i], a[i + 1]), ans);
//	}
//	cout << ans - 1 << "\n";
//}
//
//int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) solve();
//}