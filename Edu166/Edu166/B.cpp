//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//const int N = 2e5 + 10;
//void solve()
//{
//	int a[N], b[N];
//	int n, maxn1 = 0, maxn2 = 0, minn1 = 0x3f3f3f3f, minn2 = 0x3f3f3f3f;
//	cin >> n;
//	long long ans = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//		maxn1 = max(maxn1, a[i]);
//		minn1 = min(minn1, a[i]);
//	}
//	for (int i = 0; i <= n; i++)
//	{
//		cin >> b[i];
//		if (i != n)
//		{
//			ans += (fabs(b[i] - a[i]));
//			maxn2 = max(maxn2, b[i]);
//			minn2 = min(minn2, b[i]);
//		}
//	}
//	bool f = false;
//	int res = 0x3f3f3f3f;
//	for (int i = 0; i < n; i++)
//	{
//		if (b[n] >= min(a[i], b[i]) && b[n] <= max(a[i], b[i]))
//		{
//			f = true;
//			break;
//		}
//		else
//		{
//			if (b[n] < min(a[i], b[i]))
//			{
//				res = min(min(a[i], b[i]) - b[n], res);
//			}
//			else
//			{
//				res = min(b[n] - max(a[i], b[i]), res);
//			}
//		}
//	}
//	ans++;
//	if (!f)
//	{
//		ans += res;
//	}
//	cout << ans << endl;
//}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}