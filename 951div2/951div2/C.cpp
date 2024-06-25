#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
PII k[60];
bool check(int x)
{
		
}

void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i].first;
		k[i].second = i;
	}
	sort(k + 1, k + 1 + n , greater<PII>());
	ll r = 1e11 , l = 0;
	while (l + 1 != r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else
		{
			l = mid;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}