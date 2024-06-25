//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//const int N = 2e5 + 10;
//
//int gcd(int a, int b)
//{
//	while (b ^= a ^= b ^= a %= b);
//	return a;
//}
//void solve()
//{
//	int n;
//	cin >> n;
//	int a[N];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	int b[N];
//	for (int i = 0; i < n - 1; i++)
//	{
//		b[i] = gcd(a[i], a[i + 1]);
//	}
//	int cnt = 0 ,pos;
//	for (int i = 0; i + 1 < n - 1; i++)
//	{
//		if (b[i] > b[i + 1])
//		{
//			cnt++;
//			pos = i;
//		}
//	}
//	if (cnt > 1) { cout << "NO" << "\n"; }
//	else if(cnt)
//	{
//		if (n == 3)
//		{
//			cout << "YES" << "\n";
//		}
//		else
//		{
//			if (pos == 0 || pos == n - 2)
//			{
//				cout << "YES" << "\n";
//			}
//			else 
//			{
//				b[pos - 1] = gcd(a[pos - 1], a[pos + 1]);
//				if (b[pos - 1] <= b[pos + 1]) { cout << "YES" << "\n"; }
//				else { cout << "NO" << "\n"; }
//			}
//		}
//	}
//	else
//	{
//		cout << "YES" << "\n";
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
//
//}