//#define _CRT_SECURE_NO_WARNINGS 1
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//using namespace std;
//typedef pair<int, int> PII;
//typedef long long ll;
//const int MOD = 998244353;
//int gcd(int a, int b) {
//	return b ? gcd(b, a % b) : a;
//}
//
//ll ksm(ll a, ll b)
//{
//	int t = 1;
//	while (b)
//	{
//		if (b & 1) t = t * a % MOD;
//		a = a * a % MOD;
//		b /= 2;
//	}
//	return t;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int s = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		s = (s * i) % MOD;
//		//cout << x << " ";
//	}
//	int sum = 0;
//	int x;
//	ll a = 0;
//	ll b = 0;
//	int t = n;
//	while (t--)
//	{
//		cin >> x;
//		sum += x;
//	}
//	// cout << sum << endl;
//	a = (2 * sum) % MOD;
//	ll temp = ksm(2, n - 1) % MOD;
//	//cout << temp << endl;
//	temp = (temp * (n - 2) + 3 - n + MOD) % MOD;
//	//cout << temp << endl;
//	//temp = (temp + 3 - n + MOD) % MOD;
//	//cout << temp << endl;
//	a = (a * temp) % MOD;
//	b = ksm(2, n - 1) % MOD;
//	b = (b * s) % MOD;
//	//cout << a << " " << b << endl;
//	cout << a * ksm(b, MOD - 2) % MOD << endl;
//	return 0;
//}
