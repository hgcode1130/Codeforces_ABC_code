#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	unordered_map<int, int>mp;
	vector<int> yinzi;
	int x = n;
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			int cnt = 0;
			while (x % i == 0)
			{
				x /= i;
				cnt++;
			}
			yinzi.push_back(i);
			mp[i] = cnt;
		}
		
	}
	if (x > 1)
	{
		yinzi.push_back(x);
		mp[x] = 1;
	}
	if (yinzi[0] == n || (yinzi.size() == 1 && mp[yinzi[0]] < 6) || (yinzi.size() == 2 && mp[yinzi[0]] + mp[yinzi[1]] <= 3)) { cout << "NO" << "\n"; return; }
	int a, b, c;
	cout << "YES" << "\n";
	if (yinzi.size() == 1)
	{
		a = yinzi[0];
		b = yinzi[0] * yinzi[0];
		c = n / a / b;
	}
	else
	{
		a = yinzi[0];
		b = yinzi[1];
		c = n / a / b;
	}
	cout << a << " " << b << " " << c << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}