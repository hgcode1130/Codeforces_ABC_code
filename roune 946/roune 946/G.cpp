#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
using namespace std;
const int N = 2e5 + 10;
int a[N];
void solve()
{
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0 , now = 0;
	priority_queue<int, vector<int>, greater<int>()> q;
	for (int i = 1; i <= n; i++)
	{
		if (now >= a[i])
		{
			ans++;
			now -= a[i];
			q.push(a[i]);
		}
		else
		{
			if (a[i] < q.top())
			{
				q.pop();
				q.push(a[i]);
			}
		}
	}
	cout << ans << '\n';
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}