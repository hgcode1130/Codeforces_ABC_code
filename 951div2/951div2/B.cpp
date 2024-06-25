//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<cmath>
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> PII;
//const int N = 2e5 + 10;
//int l[33];
//void solve()
//{
//	int f[60][60];
//	int n, m, len1, len2;
//	cin >> n >> m;
//	char a[60], b[60];
//	for (int i = 31; i; i--)
//	{
//		if (n >> i & 1)
//		{
//			len1 = i + 1;
//			break;
//		}
//	}
//	for (int i = 31; i; i--)
//	{
//		if (m >> i & 1)
//		{
//			len2 = i + 1;
//			break;
//		}
//	}
//	//cout << len1 << " "<<len2  << "\n";
//	for (int i = 0; i < 32; i++)
//	{
//		if (n >> i & 1)
//		{
//			a[i + 1] = '1';
//		}
//		else a[i + 1] = '0';
//		if (m >> i & 1)
//		{
//			b[i + 1] = '1';
//		}
//		else b[i + 1] = '0';
//	}
//	for (int i = 0; i < 32; i++)
//	{
//		if (a[i + 1] != b[i + 1])
//		{
//			cout << l[i] << "\n";
//			break;
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int t;
//	for (int i = 0; i < 32; i++) l[i] = pow(2, i);
//	cin >> t;
//	while (t--) solve();
//}