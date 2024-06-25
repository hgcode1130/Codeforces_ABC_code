#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 4000;
bool st[N];
int prime[N], cnt;
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

vector<int> fenjie(int x)
{
	vector<int> res;
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			res.push_back(i);
			while (x % i == 0)
			{
				x /= i;
			}
		}
		if (x > 1) res.push_back(i);
	}
	return res;
}

void zhishu()
{

	for (int i = 2; i <= N; i++)
	{
		if (!st[i]) prime[++cnt] = i;
		for (int j = 0; prime[j] <= N / i; j++)
		{
			prime[i * prime[j]] = true;
			if (i % prime[j] == 0)break;
		}
	}
}

void solve()
{
	int x, y;
	cin >> x >> y;
	int g = gcd(x, y);
	if (g == 1)
	{
		vector<int> c = fenjie(y);
		int ans = 0x3f3f3f3f;
		cout << x * c[0] + y << endl;
	}
	else if (g == x)
	{
		cout << y << endl;
	}
	else
	{
		cout << x + y << endl;
	}
}

int main()
{
	zhishu();
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
}